#include<iostream>
using namespace std;

struct date
{
    int year,month,day;
};
typedef struct date DATE;

void Input_Date(DATE &D)//�������� 
{//�ĳ� void Input_Date(DATE D)���� 
     cout<<"�������ꡢ�¡���:"; 
     cin>>D.year>>D.month>>D.day;
}

void Output_Date(DATE D)//������� 
{
     cout<<"\n��������ꡢ�¡���Ϊ��";
     cout<<D.year<<"��"<<D.month<<"��"<<D.day<<"��"<<'\n'; 
}

void Initial_Date(DATE &D)//��ʼ������
{
     D.year=2013;
     D.month=3;
     D.day=16;
} 

int Judge_Date(DATE D)//�ж���������ڸ�ʽ�Ƿ���ȷ 
{
    if((D.year>0)&&(D.month>0)&&(D.month<13)&&(D.day>0))
    {
        if(((D.month==1)||(D.month==3)||(D.month==5)||(D.month==7)||(D.month==8)||(D.month==10)||(D.month==12))&&(D.day<32))
           return 1;
        else if(((D.month==4)||(D.month==6)||(D.month==9)||(D.month==11))&&(D.day<31))
           return 1;
        else if(((D.year%4!=0)||(D.year%400==0))&&(D.month==2)&&(D.day<29))
           return 1;
        else if(((D.year%4==0)&&(D.year%400!=0))&&(D.month==2)&&(D.day<30))
           return 1;
        else 
           return 0;                                               
    }
    else
        return 0;
} 

int main()
{
    DATE D;
    Initial_Date(D);
    Input_Date(D);
     
    if(Judge_Date(D))
       Output_Date(D);
    else
       cout<<"����������ڸ�ʽ����\n";
    
    system("pause");
    return 0;
} 
