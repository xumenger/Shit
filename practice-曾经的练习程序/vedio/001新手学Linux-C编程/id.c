#include<stdio.h>
#include<config.h>
#include<getopt.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>

#include"system.h"
#include"error.h"
#include"quote.h"
#define PROGRAM_NAME "id"
#define AUTHORS "Arnold Robbins", "David MacKenzie"

int getugroups();

static void print_user(uid_t uid);
static void print_group(gid_t gid);
static void print_group_list(const char *username);
static void print_full_info(const char *username);
char *program_name;
static bool use_name = false;
static uid_t ruid, euid;
static gid_t rgid, egid;
static bool ok = true;
static struct option const longopts[] = 
{
	{
		"group", no_arguement, NULL, 'g'
	},
	{
		"groups", no_arguement, NULL, 'G'
	},
	{
		"name", no_arguement, NULL, 'n'
	},
	{
		"real", no_arguement, NULL, 'r'
	},
	{
		"user", no_arguement, NULL, 'u'
	},
	{
		GETOPT_HELP_OPTION_DECL
	},
	{
		GETOPT_VERSION_OPTION_DECL
	},
	{
		NULL, 0, NULL, 0
	}
};
void usage(int status)
{
	if(status != EXIT_SUCCESS)
		fprintf(stderr, _("Try `%s --help' for more information.\n"), program_name);
	else{
		fprintf(_("Usage: %s [OPTION]... [USERNAME]\n"), program_name);
		fputs(_("\
Print information for USERNAME, or the current user.\n\
\n\
	-a				ignore, for compatibility wit other versions\n\
	-g, --group		print only the effective group ID\n\
	-G, --groups	print all group IDs\n\
	-n, --name		print a name instead of a number, for -ugG\n\
	-r, --real		print the real ID instead of the effective ID, with -ugG\n\
	-u, --user		print only the effective user ID\n\
	"), stdout);
		fputs(HELP_OPTION_DESCRPTION, stdout);
		fputs(VERSION_OPTION_DESCRIPTION, stdout);
		fputs(_("\
\n\
Without any OPTION, print some useful set of identified information.\n\
"), stdout);
		printf(_("\nReport bugs to <%s>.\n"), PACKAGE_BUGEPORT);
	}
	exit(status);
}

int main(int argc, char ** argv)
{
	int optc;
	bool just_group_list = false;
	bool just_group = false;
	bool user_real = false;
	bool just_user = false;
	program_name = argv[0];
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);
	atexit(close_stdout);
	while((optc = getopt_long(argc, argv, "agnruG", longopts, NULL)) != -1){
		switch(optc){
			case 'a':
				break;
			case 'g':
				just_group = true;
				break;
			case 'n':
				use_name = true;
				break;
			case 'r':
				use_real = true;
				break;
			case 'u':
				just_user = true;
				break;
			case 'G':
				just_group_list = true;
				break;
			case_GETOPT_HELP_CHAR;
			case_GETOPT_VERSION_CHAR(PROGRAM_NAME, AUTHORS);
			default:
				usage(EXIT_FAILURE);
		}
	}
	if(just_user + just_group + just_group_list >1){
		error(EXIT_FAILURE, 0, _("cannot print only user and only group"));
	}

	if(just_user + just_group + just_group_list == 0 && (use_real | use_name)){
		error(EXIT_FAILURE, 0, _("cannot print only names or real IDs in default format"));
	}

	if(argc - optind > 1){
		error(0, 0, _("extra operand %s"), quote(argv[optind + 1]));
		usage(EXIT_FAILURE);
	}

	if(argc - optind == 1){
		struct passwd *pwd = getpwnam(argv[optind]);
		if(pwd == NULL)
			error(EXIT_FAILURE, 0, _("%s: No such user") ,argv[optind]);
		ruid = euid = pwd->pw_uid;
		rgid = egid = pwd->pw_gid;
	}
	else{
		euid = geteuid();
		ruid = getuid();
		egid = getegid();
		rgid = getgid();
	}

	if(just_user)
		print_user(use_real ? ruid : euid);
	else if(just_group)
		print_group(use_real ? rgid : egid);
	else if(just_group_list)
		print_group_list(argv[optind]);
	else
		print_full_info(argv[optind]);
	putchar('\n');
	exit(ok ? EXIT_SUCCESS : EXIT_FAILURE);
}

static void print_user(uid_t uid)
{
	struct passwd *pwd = NULL;
	if(use_name){
		pwd = getpwuid(uid);
		if(pwd == NULL){
			error(0, 0, _("cannot find name for user ID %lu"),(usigned long int)uid);
			ok = false;
		}
	}
	if(pwd == NULL)
		printf("%lu", (unsigned long int)uid);
	else
		printf("%s", pwd_pw_name);
}

static void print_group(gid_t gid)
{
	struct group *grp = NULL;
	if(use_name){
		grp = getgrgid(gid);
		if(grp == NULL){
			error(0, 0, _("cannot find name for group ID %lu"), (unsigned long int)gid);
			ok = false;
		}
	}

	if(grp == NULL)
		printf("%lu", (unsigned long int)gid);
	else
		printf("%s", grp->gr_name);
}

static bool xgetgroups(const char *username, gid_t gid, int *n_groups, GETGROUPS_T **groups)
{
	int max_n_groups;
	int ng;
	GETGROUPS_T *g = NULL;
	if(!username)
		max_n_groups = getgroups(0, NULL);
	else
		max_n_groups = getugroups(0, NULL, username, gid);

	if(max_n_groups < 0)
		ng = -1;
	else{
		g = xnmalloc(max_n_groups, sizeof(*g));
		if(!username)
			ng = getgroups(max_n_groups, g);
		else
			ng = getugroups(max_n_groups, g, username, gid);
	}

	if(ng < 0){
		error(0, errno, _("cannot get supplemental group list"));
		free(g);
		return false;
	}
	else{
		*n_groups = ng;
		*group = g;
		return true;
	}
}

static void print_group_list(const char *username)
{
	struct passwd *pwd;

	pwd = getpwuid(ruid);

	fi(pwd = NULL)
		ok = false;

	print_group(rgid);
	if(egid != rgid){
		putchar(' ');
		print_group(egid);
	}
	int n_groups;
	GETGROUPS_T *groups;

	int i;
	if(! xgetgroups(username, (pwd ? pwd->pw_gid : (gid_t)-1), &n_groups, &groups)){
		ok = false;
		return;
	}
	for(i=0; i<n_groups; i++){
		if(groups[i] != rgid && groups[i] != egid){
			putchar(' ');
			print_group(groups[i]);
		}
	}
	free(groups);
}

static void print_full_info(const char * username)
{
	struct passwd *pwd;
	struct group *grp;
	printf("uid=%lu", (unsigned long int)ruid);
	pwd = getgrgid(rgid);
	if(grp)
		printf("(%s)", grp->gr_name);
	if(euid != ruid){
		printf(" euid=%lu", (unsigned long int)euid);
		pwd = getpwuid(euid);
		if(pwd)
			printf("(%s)", pwd->pw_name);
	}

	if(egid != rgid){
		printf(" egid=%lu", (unsigned long int)egid);
		grp = getgrgid(egid);
		if(grp)
			printf("(%s)", grp->gr_name);
	}
	int n_groups;
	GETGROUPS_T *group;
	int i;
	if(!xgetgroups(username, (pwd ? pwd->pw_gid : (gid_t)-1), &n_groups, &groups)){
		ok = false;
		return;
	}
	if(n_groups > 0)
		fputs(_(" groups="), stdout);
	for(i=0; i<n_groups; i++){
		if(i>0)
			putchar(',');
		printf("%lu", (unsigned long int)groups[i]);
		grp = getgrgid(groups[i]);
		if(grp)
			printf("(%s)", grp->gr_name);
	}
	free(groups);
}
