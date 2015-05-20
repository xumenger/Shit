#include<iostream>
using namespace std;

class Vec4
{
      float s[4];
      class Error{};//
      public:
             Vec4(float a=0.0,float b=0.0,float c=0.0,float d=0.0)
             {
                 s[0]=a;
                 s[1]=b;
                 s[2]=c;
                 s[3]=d;
             }
             void check(int i)
             {
                  if(i<0||i>4)
                  throw Error();//
             } 
             float operator[](int i)
             {
                   check(i);
                   return s[i];
             }
             friend Vec4 operator+(const Vec4& a,const Vec4& b)//
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]+b.s[0];
                    sa.s[1]=a.s[1]+b.s[1];
                    sa.s[2]=a.s[2]+b.s[2];
                    sa.s[3]=a.s[3]+b.s[3];
                    return sa;
             }
             friend Vec4 operator-(const Vec4& a,const Vec4& b)
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]-b.s[0];
                    sa.s[1]=a.s[1]-b.s[1];
                    sa.s[2]=a.s[2]-b.s[2];
                    sa.s[3]=a.s[3]-b.s[3];
                    return sa;
             }
             friend Vec4 operator*(const Vec4& a,const Vec4& b)
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]*b.s[0];
                    sa.s[1]=a.s[1]*b.s[1];
                    sa.s[2]=a.s[2]*b.s[2];
                    sa.s[3]=a.s[3]*b.s[3];
                    return sa;
             }
             friend Vec4 operator/(const Vec4& a,const Vec4& b)
             {
                    for(int i=0;i<4;i++)
                    {
                        if(b.s[i]==0)
                            throw Error();
                    }
                    
                    Vec4 sa;
                    sa.s[0]=a.s[0]/b.s[0];
                    sa.s[1]=a.s[1]/b.s[1];
                    sa.s[2]=a.s[2]/b.s[2];
                    sa.s[3]=a.s[3]/b.s[3];
                    return sa;
             }
             friend Vec4 operator+(const Vec4& a,float f)//
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]+f;
                    sa.s[1]=a.s[1]+f;
                    sa.s[2]=a.s[2]+f;
                    sa.s[3]=a.s[3]+f;
                    return sa;
             }
             /*Vec4& operator=(Vec4& a)
             {
                   s[0]=a.s[0];
                   s[1]=a.s[1];
                   s[2]=a.s[2];
                   s[3]=a.s[3];
                   
                   return *this;
             }
             Vec4& operator=(float a)
             {
                   s[0]=a;
                   s[1]=a;
                   s[2]=a;
                   s[3]=a;
                   
                   return *this;
             }*/
             //��Ҫ��ֵ�ţ�����������У����˸�ֵ�ţ����򷴶����������ˣ�Ϊʲô 
             Vec4 operator+=(Vec4& a)
             {
                  s[0]+=a.s[0];
                  s[1]+=a.s[1];
                  s[2]+=a.s[2];
                  s[3]+=a.s[3];
                  
                  return *this;
             }
             Vec4 operator-=(Vec4& a)
             {
                  s[0]-=a.s[0];
                  s[1]-=a.s[1];
                  s[2]-=a.s[2];
                  s[3]-=a.s[3];
                  
                  return *this;
             }
             Vec4 operator*=(Vec4 &a)
             {
                  s[0]*=a.s[0];
                  s[1]*=a.s[1];
                  s[2]*=a.s[2];
                  s[3]*=a.s[3];
                  
                  return *this;
             }
             Vec4 operator/=(Vec4& a)
             {
                  for(int i=0;i<4;i++)
                  {
                      if(a.s[i] == 0)
                          throw Error();
                  }
                  s[0]/=a.s[0];
                  s[1]/=a.s[1];
                  s[2]/=a.s[2];
                  s[3]/=a.s[3];
                  return *this;
             }
             
};

int main()
{
    cout<<"���ܣ�"<<endl;
    cout<<"     ������d������ǰ����ֵ�����ĸ�Ĭ��Ϊ0����ͬʱ�����Զ�����a��b��c��ֵ��������b=b+a��a=a+1��d=d+b�����㣬������a��b��c��d"<<endl;
    
    int i,j,k;
    cin>>i>>j>>k;
    Vec4 d(i,j,k); 
    Vec4 a(23,45,34),b(0,8,9,4),c;//a��Ȼֻ����������ֵ����֮ǰ��д��Vec4�Ĺ��캯��Ĭ��ʣ�µ�Ϊ���һ����Ĭ�ϸ�ֵ0 
    b=b+a;
    a=a+1;
    d=b+d;
    c=a+b; 
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
    
    system("pause");
    return 0;
}
