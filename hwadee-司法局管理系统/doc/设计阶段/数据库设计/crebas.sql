/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2014-8-29 8:44:56                            */
/*==============================================================*/


drop table if exists Article;

drop table if exists DisputeSolve;

drop table if exists InsideUser;

drop table if exists JudicialIdentifyApply;

drop table if exists JudicialSupportApply;

drop table if exists Notarization;

drop table if exists Outlink;

drop table if exists OutsideUser;

drop table if exists Role;

drop table if exists SubscriptionRecord;

/*==============================================================*/
/* Table: Article                                               */
/*==============================================================*/
create table Article
(
   ArticleID            int not null auto_increment,
   UserID               int,
   ArticleName          varchar(50),
   ArticleContent       text,
   ArticleType          varchar(50) comment '1
            2
            3
            4
            5',
   UpdateTime           date,
   Author               varchar(50),
   ArticleStatus        varchar(50) comment '1.δ���
            2.ͨ��
            3.��ͨ��',
   primary key (ArticleID)
);

/*==============================================================*/
/* Table: DisputeSolve                                          */
/*==============================================================*/
create table DisputeSolve
(
   DSId                 int not null auto_increment,
   UserNumber           int,
   DSState              varchar(50) comment '1.δ�ύ
            2.���ύ
            3.�ѽ��',
   DSAppSex             varchar(50),
   DSAppAdd             date,
   DSAppBirth           varchar(50),
   DSClaims             varchar(1024),
   DSFact               longtext,
   primary key (DSId)
);

/*==============================================================*/
/* Table: InsideUser                                            */
/*==============================================================*/
create table InsideUser
(
   UserID               int not null auto_increment,
   Role                 varchar(50) comment '1.����Ա
            2.������
            3.��֤Ա
            4.�շ�Ա
            5.���Ա
            6.�鵵Ա
            7.�༭
            8.�ⲿ�û�',
   InsideUserStatus     varchar(50),
   LoginName            varchar(50),
   UserPassword         varchar(50),
   Department           varchar(50),
   primary key (UserID)
);

/*==============================================================*/
/* Table: JudicialIdentifyApply                                 */
/*==============================================================*/
create table JudicialIdentifyApply
(
   JudicialIdentifyApplyNumber int not null auto_increment,
   UserNumber           int,
   JIStatus             varchar(50) comment '1.δ�ύ
            2.���ύ
            3.�ѽ��',
   JIAppID              int,
   JIAppSex             varchar(50),
   JIAppBirthday        date,
   JIAppAdd             varchar(50),
   JIClaims1            varchar(1024),
   primary key (JudicialIdentifyApplyNumber)
);

/*==============================================================*/
/* Table: JudicialSupportApply                                  */
/*==============================================================*/
create table JudicialSupportApply
(
   JSID                 int not null auto_increment,
   UserNumber           int,
   JSStatus             varchar(50),
   JSAppID              int,
   JSAppSex             varchar(50),
   JSAppBirth           date,
   JSAppAdd             varchar(50),
   JSClaims             varchar(1024),
   JSFact               longtext,
   primary key (JSID)
);

/*==============================================================*/
/* Table: Notarization                                          */
/*==============================================================*/
create table Notarization
(
   NotaID               int not null auto_increment,
   UserID               int,
   UserNumber           int,
   NotaStatus           varchar(50) comment '1.δ���
            2.�շ�
            3.�鵵
            4.�����',
   AppDate              date,
   PrincipalID          int,
   FeeCollectID         int,
   ApprovalID           int,
   FilerID              int,
   NotaClaims           varchar(1024),
   NotaFact             longtext,
   NotaAppAdd           varchar(50),
   primary key (NotaID)
);

/*==============================================================*/
/* Table: Outlink                                               */
/*==============================================================*/
create table Outlink
(
   LinkID               int not null auto_increment,
   UserID               int,
   LinkName             varchar(20),
   Linkadd              varchar(1024),
   primary key (LinkID)
);

/*==============================================================*/
/* Table: OutsideUser                                           */
/*==============================================================*/
create table OutsideUser
(
   UserNumber           int not null auto_increment,
   Role                 varchar(50) comment '1.����Ա
            2.������
            3.��֤Ա
            4.�շ�Ա
            5.���Ա
            6.�鵵Ա
            7.�༭
            8.�ⲿ�û�',
   OutsideUserName      varchar(50),
   OutsideUserStatus    varchar(50),
   UserSex              varchar(50),
   BirthDate            date,
   CurrentADDR          varchar(100),
   Mobile               int,
   QQ                   varchar(50),
   MSN                  varchar(50),
   Phone                varchar(50),
   ZipCode              int,
   Address              varchar(80),
   Password             varchar(50),
   primary key (UserNumber)
);

/*==============================================================*/
/* Table: Role                                                  */
/*==============================================================*/
create table Role
(
   Role                 varchar(50) not null comment '1.����Ա
            2.������
            3.��֤Ա
            4.�շ�Ա
            5.���Ա
            6.�鵵Ա
            7.�༭
            8.�ⲿ�û�',
   Permission2          varchar(14) not null,
   primary key (Role)
);

/*==============================================================*/
/* Table: SubscriptionRecord                                    */
/*==============================================================*/
create table SubscriptionRecord
(
   SubID                int not null auto_increment,
   UserNumber           int,
   SubItem              varchar(50),
   primary key (SubID)
);

alter table Article add constraint FK_InsideUserArticle foreign key (UserID)
      references InsideUser (UserID) on delete restrict on update restrict;

alter table DisputeSolve add constraint FK_OutsideUserDisputeSolveApply foreign key (UserNumber)
      references OutsideUser (UserNumber) on delete restrict on update restrict;

alter table InsideUser add constraint FK_InsideUserRole foreign key (Role)
      references Role (Role) on delete restrict on update restrict;

alter table JudicialIdentifyApply add constraint FK_OutsideUserJudicialIdentifyApply foreign key (UserNumber)
      references OutsideUser (UserNumber) on delete restrict on update restrict;

alter table JudicialSupportApply add constraint FK_OutsideUserJudicialSupportApply foreign key (UserNumber)
      references OutsideUser (UserNumber) on delete restrict on update restrict;

alter table Notarization add constraint FK_InsideUserNotarization foreign key (UserID)
      references InsideUser (UserID) on delete restrict on update restrict;

alter table Notarization add constraint FK_OutsideUserNotarizationProcess foreign key (UserNumber)
      references OutsideUser (UserNumber) on delete restrict on update restrict;

alter table Outlink add constraint FK_InsideUserOutlink foreign key (UserID)
      references InsideUser (UserID) on delete restrict on update restrict;

alter table OutsideUser add constraint FK_OutsideUserRole foreign key (Role)
      references Role (Role) on delete restrict on update restrict;

alter table SubscriptionRecord add constraint FK_OutsideUserSubscriptionRecord foreign key (UserNumber)
      references OutsideUser (UserNumber) on delete restrict on update restrict;

