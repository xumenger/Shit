#include<iostream>
using namespace std;
int add(int &i);

class Circle
{
      public:
             Circle();//Բ�����
             void Find_Max();//Բ�������Ҫ������Ѱ�ҷ��������ģ���Ϊ��С��������4���� 
             void Show(void);//���Բ������������С������ĸ��������ֵ
          
      private:
              int num[20];//������ɵ�20�������
              int Max[4];//���20�������������4����֮����������4����������
              int sum_max;//���20�������������4����֮�������ĺ� 
} ;

int main()
{
    Circle *cir=new Circle();
    cir->Find_Max();
    cir->Show();
    delete cir;
    cir=NULL;
    
    system("pause");
    return 0;
} 

Circle::Circle()
{
    for (int i(0);i<20;i++)
        num[i]=rand();
}

void Circle::Show(void)
{
     cout<<"Բ������������У�"<<endl;
     for(int i(0);i<20;i++)
         cout<<" "<<num[i];
         
     cout<<endl<<"�����ĸ�����"<<endl;
     for(int i(0);i<4;i++)
         cout<<" "<<Max[i];
     
     cout<<endl<<"��ֵ:"<<sum_max<<endl; 
     
}
void Circle::Find_Max()
{
     int i=0;
     int j;
     int k;
     int m[20];
     for(i=0;i<20;i++)
         m[i]=0;
     sum_max=m[0];
     int ii;
     for(i=0;i<20;i++)
     {
         j=i;
         k=i;
         m[i]=m[i]+num[add(j)]+num[add(j)]+num[add(j)]+num[add(j)];
         if(sum_max<m[i])
         {
             sum_max=m[i];
             for(ii=0;ii<4;ii++)
                 Max[ii]=num[add(k)];
             
         }
     }
     
}

int add(int &i)
{
    if(i>=0&&i<=18)
    {
        i++;
        return i;
    }
    else if(i=19)
    {
        i=0;
        return i;
    }
    else
        cout<<"wrong!"<<endl;
   
} 










