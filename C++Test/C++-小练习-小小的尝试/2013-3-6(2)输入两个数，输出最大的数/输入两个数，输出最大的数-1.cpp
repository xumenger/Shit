#include<iostream>
using namespace std;
int main()
{
    int max(int x,int y);//��max���������� 
    int a,b,c;
    cin >>a >>b;
    c=max(a,b);//����max���� 
    cout <<"max=" <<c <<"\n";
    system("pause");
    return 0;
} 

int max(int x,int y)//����max���� 
{
    int z;
    if(x>y)
       z=x;
    else
       z=y;
    return z;
}
