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

void add_day(DATE &D)//�����ڽ����ռ�һ���� ,��Ϊ�ռ�һ��������������õ������Ե����ֳ���ʵ�� ��������ʹ�� 
{
                 if(D.month==1||D.month==3||D.month==5||D.month==7||D.month==8||D.month==10)
                 {
                     if(D.day>=1&&D.day<=30)
                        D.day++;
                     else if(D.day==31)
                     {
                         D.day=1;
                         D.month++;
                     }
                 }
                 else if(D.month==4||D.month==6||D.month==9||D.month==11)
                 {
                     if(D.day>=1&&D.day<=29)
                        D.day++;
                     else if(D.day==30)
                     {
                         D.day=1;
                         D.month++;
                     }
                 }
                 else if(D.month==12)
                 {
                      if(D.day>=1&&D.day<=30)
                          D.day++;
                      else if(D.day==31)
                      {
                           D.day=1;
                           D.month=1;
                           D.year++;
                      }
                 }
                 else if(D.month==2)
                 {
                     if(((D.year%4==0)&&(D.year%100!=0))||(D.year%400==0))//����
                      {
                          if(D.day>=1&&D.day<=28)
                             D.day++;
                          else if(D.day==29)
                          {
                               D.month++;
                               D.day=1;
                           }
                      } 
                      else//������ 
                      {
                          if(D.day>=1&&D.day<=27)
                             D.day++;
                          else if(D.day==28)
                          {
                               D.month++;
                               D.day=1;
                           }
                      }
                      
                 }
}

void add(DATE &D)//Ҫ�������ú�����ʵ�ε�ֵ�ı䣬��Ҫ�õ�&������ֻ���βα䣬ʵ�β��䣬��û��ʵ��ϣ���Ĺ��� 
{
    if(Judge_Date(D))
    {
        char c;
        cout<<"����a�����һ;����b���¼�һ;����c���ռ�һ"<<endl;
        cin>>c;
        switch(c)
        {
            case 'a':
            {
                if((D.year%4==0)&&(D.year%400!=0)&&(D.month==2)&&(D.day==29))
                {//���������2.29��һ���Ǵ����3.1 
                    D.year++;
                    D.month++;
                    D.day=1;
                }
                else 
                    D.year++;
                
                break;   
            } 
            case 'b':
            {
                if((((D.year%4==0)&&(D.year%100!=0))||(D.year%400==0))&&(D.month==1)&&(D.day==31))
                {
                    D.month++;
                    D.day=29; 
                } 
                else if(D.year%4!=0)
                
                break;            
            }
            case 'c':
            {
                 add_day(D); 
                 
                 break;
            }
            default:
            cout<<"�������\n";
        }
        
        
    }
    else
    {
       cout<<"����������ڸ�ʽ����"<<endl;
    }
}

int Day(DATE D)//�Թ�Ԫ2013��4��8��Ϊ��׼������������һ 
{//ע���Ϊ��׼��֮ǰ�ͻ�׼��֮������������ۣ���kֵ��¼��֮ǰ����֮�󣡣����ֲ�ͬ�� 
     int i=0;
     int j=0;
     int k;
     DATE DD;
     DD.year=2013;
     DD.month=4;
     DD.day=8;
     if(D.year>=DD.year||(D.year==DD.year&&D.month>=DD.month)||(D.year==DD.year&&D.month==DD.month&&D.day>=DD.day))
     {
         k=1;
         for(i=0;;i++)
         {
         
             if(D.year==DD.year&&D.month==DD.month&&D.day==DD.day)
                break;
             add_day(DD);
         }
     }
     else
     {
         k=2;
         for(j=0;;j++)
         {
             add_day(D);
             if(D.year==DD.year&&D.month==DD.month&&D.day==DD.day)
                break;
              
         }
     }
     
     if(k==1)
     {
         i=i%7;
         if(i!=6)
         { 
            cout<<"����������"<<i+1<<endl; 
            return i+1; 
         } 
         else
         {
            cout<<"������������"<<endl;
            return 7;
         }
     }
     else if(k==2)
     {
          j=j%7;
          if(j!=0)
          {
             cout<<"����������"<<7-j<<endl;
             return 7-j;
          } 
          else
          {
              cout<<"������������"<<endl;
              return 7;
          }
     }
}

void Next_monday(DATE D)
{
     int i=Day(D);
     int j=0;
     for(j=0;j<8-i;j++)
     {
         add_day(D);
     }
     cout<<"������������һ������Ϊ��"<<D.year<<" "<<D.month<<" "<<D.day<<endl; 
}

int main()
{
    DATE D;
    Initial_Date(D);
    Input_Date(D);
    cout<<"����1���ж������Ƿ���ȷ;����2������»��ռ�һ;����3���ж����ڼ�;����4������պ������һ������"<<endl;
    char c;
    cin>>c; 
    switch(c)
    {
        case '1':
        {
             if(Judge_Date(D))
                 cout<<"����������ڸ�ʽ��ȷ\n";
             else
                 cout<<"����������ڸ�ʽ����\n";
             break;
         }
         case '2':
         {
              add(D);
              cout<<D.year<<" "<<D.month<<" "<<D.day<<endl;
              break;
         } 
         case '3':
         {
             Day(D);
             break;
         }
         case '4':
         {
              Next_monday(D);
              break;
         }
         
         default:
            cout<<"�������"<<endl;
             
    } 
    
    
    system("pause");
    return 0;
} 
