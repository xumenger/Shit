#include<iostream>
void f1(int val,int &ref)//��һ���β�Ϊֵ���ã��ڶ���Ϊ���õ��� 
{
    val++;
    ref++;
}

void f2(int *val,int &ref)//��һ��Ϊ��һ��ֵ���ã��ڶ���Ϊ���õ��� 
{                             //�������ֺ�����ʽ�д� 
     val++;
     ref++;
} 

int main()
{
    int i=1;
    int j=1;
    f1(i,j);
    std::cout<<i<<"\n"<<j<<"\n";
    f1(i,j);
    std::cout<<i<<"\n"<<j<<"\n";//ֵ���������õ��õ����� 
    
    f1(2,j);
    //f1(1,2);�����ú�������ʽ������Ϊ��f1()�ж���Ҫ���һ��ʵ��Ϊint�ͣ��ڶ���Ϊint&�ͣ����������ʵ���ββ�ƥ�� 
    
    
    int a=1;
    int b=1; 
    f2(&a,b);
    std::cout<<a<<"\n"<<b<<"\n";
    f2(&a,b);
    std::cout<<a<<"\n"<<b<<"\n";//��һ��ֵ���������õ��õ����� 
    
    system("pause");
    return 0;
} 
