#include<iostream>
#include<cstring>
using namespace std;

int atoi(char* ,int);
int square(int i,int base);

int main()
{
    char c[100];
    int n;
    int base;
    
    cout<<"�����������ַ�����";
    cin>>c;
    
    cout<<"����Ϊ���ٽ��Ƶ�����";
    cin>>base;
    
    n=atoi(c,base);
    cout<<"����ת��Ϊʮ���Ƶ���Ϊ��"<<n<<endl;
    
    
    system("pause");
    return 0;
} 

int atoi(char* c,int base)
{
    int i=strlen(c);
    int m[i];
    int k;
    for(k=0;k<i;k++)
    {
        m[k]=c[k]-'0';
    } 
    int n=0;
    for(k=0;k<i;k++)
        n=n+m[k]*square(i-k-1,base);
    
    return n;
    
}
int square(int i,int base)//���� base �� i �η� 
{
    int k;
    int end=1;
    for(k=0;k<i;k++)
    {
        end=end*base;
    }
    return end;
}
