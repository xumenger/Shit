#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

class Vec4
{
    float v[4];
    public:
           Vec4(float fv1=0.0,float fv2=0.0,float fv3=0.0,float fv4=0.0)//����һ�����ɣ��ܺã� 
           {//���������Vec4�Ĺ��캯���������û��Լ�����Vec4 a(1,2,3,4)����ʽ��������ֵ��Ҳ����ֱ��Vec4 a����aĬ��Ϊ(0,0,0,0)������������Vec4 a(1,2,3)��������һ������aĬ��Ϊ(1,2,3,0) 
               v[0]=fv1;
               v[1]=fv2;
               v[2]=fv3;
               v[3]=fv4;
           }
           ~Vec4(){};
           float& operator[](int);
           Vec4& operator+(float);//���Ƕ���Vec4������������ӵļӷ� 
           Vec4& operator+(Vec4&);//���Ƕ���Vec4��������һ��Vec4������ӵļӷ�����������һ��ʵ�֣�����ļ�����������ʵ�� 
           Vec4& operator-(float);
           Vec4& operator*(float);//��Ҳ����ͬʱʵ�������������ĳ˷��������������������ļӷ���ͬ 
           Vec4& operator/(float);
           Vec4& operator=(float);
           Vec4& operator+=(float);
           Vec4& operator-=(float);
           Vec4& operator*=(float);
           Vec4& operator/=(float);
           void print()
           {
                cout<<v[0]<<","<<v[1]<<","<<v[2]<<","<<v[3]<<endl;
           }
};

float& Vec4::operator[](int i)
{
       assert(0<=i&&i<4);//assert�����Ĺ��ܣ����������ı��ʽΪ�٣����������˳��������һ��������Ϣ��������ʽ��ֵΪ�������ִ�к������� 
       return v[i];
}

Vec4& Vec4::operator+(Vec4& x)//ע��Ӽ��˳��������ʵ�ֵĸ�ʽ 
{
      v[0]=v[0]+x.v[0];
      v[1]=v[1]+x.v[1];
      v[2]=v[2]+x.v[2];
      v[3]=v[3]+x.v[3];
      return *this;
} 

Vec4& Vec4::operator+(float x)
{
      v[0]=v[0]+x;
      v[1]=v[1]+x;
      v[2]=v[2]+x;
      v[3]=v[3]+x;
      return *this;
} 

Vec4& Vec4::operator-(float x)
{
      v[0]=v[0]-x;
      v[1]=v[1]-x;
      v[2]=v[2]-x;
      v[3]=v[3]-x;
      return *this;
}

Vec4& Vec4::operator*(float x)
{
      v[0]=v[0]*x;
      v[1]=v[1]*x;
      v[2]=v[2]*x;
      v[3]=v[3]*x;
      return *this;
}

Vec4& Vec4::operator/(float x)
{
      if(fabs(x)<=1.0e-4)//fabs��Ը����������ֵ����abs������������ֵ 
      {
           cout<<"error"<<endl;
           return *this; 
      } 
      else
      {
          v[0]=v[0]/x;
          v[1]=v[1]/x;
          v[2]=v[2]/x;
          v[3]=v[3]/x;
          return *this;
      }
}

Vec4& Vec4::operator=(float x)
{
      v[0]=x;
      v[1]=x;
      v[2]=x;
      v[3]=x;
      return *this;
}

Vec4& Vec4::operator+=(float x)
{
      v[0]+=x;
      v[1]+=x;
      v[2]+=x;
      v[3]+=x;
      return *this;
}

Vec4& Vec4::operator-=(float x)
{
      v[0]-=x;
      v[1]-=x;
      v[2]-=x;
      v[3]-=x;
      return *this;
}

Vec4& Vec4::operator*=(float x)
{
      v[0]*=x;
      v[1]*=x;
      v[2]*=x;
      v[3]*=x;
      return *this;
}

Vec4& Vec4::operator/=(float x)
{
      v[0]/=x;
      v[1]/=x;
      v[2]/=x;
      v[3]/=x;
      return *this;
}


int main()
{
    cout<<"���ܣ�"<<endl;
    cout<<"     ������d������ǰ����ֵ�����ĸ�Ĭ��Ϊ0����ͬʱ�����Զ�����a��b��c��ֵ��������b=b+a��a=a+1��d=d+b�����㣬������a��b��c��d"<<endl;
    
    float i,j,k;
    cin>>i>>j>>k;
    Vec4 d(i,j,k); 
    Vec4 a(23.0,45.0,34.0),b(0.0,8.0,9.0,4.0),c;//a��Ȼֻ����������ֵ����֮ǰ��д��Vec4�Ĺ��캯��Ĭ��ʣ�µ�Ϊ���һ����Ĭ�ϸ�ֵ0 
    b=b+a;
    a=a+1.0;
    d=d+b;//���д��d=b+d���У���Ϊ�ڶ���+ʱ������ʽ�ض�����˳�򣬼�����ܱ䣬������� 
    
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
    
    system("pause");
    return 0;
}
