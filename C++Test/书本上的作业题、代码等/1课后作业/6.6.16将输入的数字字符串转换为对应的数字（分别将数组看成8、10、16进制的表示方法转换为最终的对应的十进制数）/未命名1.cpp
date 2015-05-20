#include<iostream>
using namespace std;

int ctoi(char c);
int square(int i,int base);
int atoi(char* c,int base);

int main()
{
    char c[100];
    int n;
    int base;
    
    cout<<"�����������ַ�����";
    cin>>c;
    
    cout<<"����Ϊ���ٽ��Ƶ�����";
    cin>>base;
    
    if(atoi(c,base)==-1)
        cout<<"ERROR!"<<endl;
    else
    {
        n=atoi(c,base);
        cout<<"����ת��Ϊʮ���Ƶ���Ϊ��"<<n<<endl;
    }
    
    
    system("pause");
    return 0;
}

int ctoi(char c)//���ַ�ת��Ϊ��Ӧ������ 
{
    int i;
    switch(c)//case���һ��Ҫ����switch��{}���棬������� 
    {
       case '0': i=0;break;
       case '1': i=1;break;
       case '2': i=2;break;
       case '3': i=3;break;
       case '4': i=4;break;
       case '5': i=5;break;
       case '6': i=6;break;
       case '7': i=7;break;
       case '8': i=8;break;
       case '9': i=9;break;
       case 'a':
       case 'A': i=10;break;
       case 'b': 
       case 'B': i=11;break;
       case 'c': 
       case 'C': i=12;break;
       case 'd': 
       case 'D': i=13;break;
       case 'e': 
       case 'E': i=14;break;
       case 'f':
       case 'F': i=15;break;
       default : return -1;
    }
       
       return i;
       
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

int atoi(char* c,int base)
{
    int i; 
    int e;
    int len=strlen(c);
    for(i=0;i<len;i++)
    {
        if((ctoi(c[i])>base-1)||(ctoi(c[i])==-1))  
        {   
           
           e=-1;
           return -1;
        }          
    }
    
    int n=0;
    if(e!=-1)
    {
        for(i=0;i<len;i++)
            n=n+ctoi(c[i])*square(len-i-1,base);
    
        return n;
    }
} 
