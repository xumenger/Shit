#include<iostream>
#include<string>
int main()
{
    int i,j,t,k;
    k=0;
    char c[2];
    char s[1000];
    std::cout<<"����һ�ַ���:";
    std::cin>>s;
    std::cout<<"����Ҫ�ҵ�һ���ַ�:";
    for(i=0;i<2;i++)
       std::cin>>c[i];
    j=strlen(s);
    for(t=0;t<j-1;t++)
    {
        if(s[t]==c[0]&&s[t+1]==c[1])
            k++;
    }
    std::cout<<"�ڸ��ַ������ҵ�"<<k<<"��"<<'\n';
    
    
    system("pause");
    return 0;
}
