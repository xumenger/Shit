#include<iostream>
using namespace std;

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
    int max_index(0);
 
    for(int i(0);i<20;i++)
    {
        int acc(0);
        for(int k(0);k<4;k++)
        {
            int n=i+k;
            if( n >= 20)
            {
                n-=20;
            }
            // ����4����֮��
            acc += num[n];
        } // for k
        if(i==0)
        {
            sum_max = acc;
            
        }
        else
        {
            
            if( sum_max < acc) 
            {
                sum_max = acc;
                max_index = i;
            }
        }
    } // for i
    for(int k(0);k<4;k++)
    {
            int n;
        // ���20�������������4����֮����������4���������� 
            n=max_index+k;
            if( n >= 20)
            {
                n-=20;
            }
        Max[k] = num[n];
    } // for k
     
     
}












