#include<iostream>//��̬�����볣����������� 
void f(int a)
{
     while(a--)
     {
         static int n=0;//��̬���� 
         int x=0;//������� 
         std::cout<<"n=="<<n++<<",x=="<<x++<<'\n';
     }
}
int main()
{
    f(3);
    
    system("pause");
    return 0;
} 
