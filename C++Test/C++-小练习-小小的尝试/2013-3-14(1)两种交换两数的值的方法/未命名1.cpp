#include<iostream>//swap1��swap2������ʵ�������Ľ��� 
int main()
{
    extern void swap1(int*,int*);
    extern void swap2(int&,int&);
    int a=10;
    int b=100;
    int c=10;
    int d=100;
    swap1(&a,&b);//ע��˴����Բ���Ϊswap(a,b) 
    swap2(c,d);//����swap1��swap2�Ĳ�� 
    std::cout<<"a="<<a<<"\nb="<<b<<"\n";
    std::cout<<"c="<<c<<"\nd="<<d<<"\n";
    
    system("pause");
    return 0;
} 
void swap1(int* p,int* q)//����p��qֵ�ĺ��� 
{
     int t=*p;
     *p=*q;
     *q=t;
}
void swap2(int &p,int &q)//����p��qֵ�ĺ��� 
{
     int t=p;
     p=q;
     q=t;
}

