 #include<iostream>
using namespace std;
int main(int argc,char* argv[])
{
	if(argc<2)
		   cout<<"δ����㹻�Ĳ���������"<<endl;
	else
	{
		for(int i=1;i<argc;++i)
			cout<<"hello,"<<argv[i]<<endl;
	}
	system("pause"); 
	return 0;
}
