/**-----------------------------------------------------------------------------
*  String���ʵ��
*------------------------------------------------------------------------------
*/
#pragma once

#include<iostream>
#include<cstring>
#includ <cassert>

using namespace std;

inline void SafeRelease_Array( const char* s )
{
 if( s != NULL )
 {
  delete []s;
  s = NULL;
 }
};

class String
{
public:
 String(void);
 String( unsigned size );
 String( const char* );
 String( const String& ss );
 String( unsigned count, const char& ch );
 ~String(void);
protected:
 char* m_str;
 unsigned m_uCount;
public:
 // --  ���ܺ�������  -------------------      -==---------->>>
 void clear();
 unsigned size();
 bool empty();
 const char* c_str() const;
 void insert( unsigned , const char& );
 void insert( unsigned , const String& );
 void push_back( const char& );
 void push_front( const char& );
 bool erase( const unsigned& );
 bool erase( const unsigned&,const unsigned& );
 
 // --  ���ز�������  -------------------      o(��_��)o...���� ---- >>>
 String& operator = ( const String& );
 String& operator += ( const String& );
 String operator + ( const String& );
 bool operator == ( const String& );
 bool operator < ( const String& );
 bool operator > ( const String& );
 // ȡֵ
 char& operator []( unsigned n );
public:
 extern friend ostream& operator << ( ostream& os, const String& ss );
 extern friend istream& operator >> ( istream& is, String& ss );
};
/**-----------------------------------------------------------------------------
*  String���ʵ��
*------------------------------------------------------------------------------
*/
#include "String.h"

/**-----------------------------------------------------------------------------
*  Ĭ�Ϲ��캯��
*------------------------------------------------------------------------------
*/
String::String(void):m_str(NULL),m_uCount(0)
{
}

/**-----------------------------------------------------------------------------
*  ����ָ����С�Ķ���
*------------------------------------------------------------------------------
*/
String::String( unsigned size ):m_str(NULL),m_uCount(size)
{
 if(size)
 {
  m_str = new char[ size ];
 }
}
/**-----------------------------------------------------------------------------
*  ��const char* ����
*------------------------------------------------------------------------------
*/
String::String( const char* str ):m_str(NULL)
{
 unsigned n = static_cast<unsigned>(strlen(str));
 m_uCount = n;
 if( n )
 {
  m_str = new char[ n ];
  strcpy_s( m_str,n+1 ,str );
 }
}

/**-----------------------------------------------------------------------------
*  �������캯��
*------------------------------------------------------------------------------
*/
String::String( const String& ss ):m_str(NULL)
{
 m_uCount = ss.m_uCount;
 if( m_uCount )
 {
  m_str = new char[ m_uCount ];
  strcpy_s( m_str,m_uCount+1 ,ss.m_str );
 }
}
/**-----------------------------------------------------------------------------
*  ��count��ch�������
*------------------------------------------------------------------------------
*/
String::String(unsigned int count, const char &ch):m_str(NULL),m_uCount(count)
{
 if( count )
 {
  m_str = new char[count];
  for(unsigned i = 0; i<count;i++)
  {
   *( m_str+i ) = ch;
  }  
  *( m_str + count ) = '\0';
 }
}
/**-----------------------------------------------------------------------------
*  ��������  --==> ֱ�ӵ���clear()�������
*------------------------------------------------------------------------------
*/
String::~String(void)
{
 clear();
}

/**-----------------------------------------------------------------------------
*  ɾ���ַ��� ����С����
*------------------------------------------------------------------------------
*/
void String::clear()
{
 if( !m_str ) // = m_str != NULL
 {
  delete []m_str;
  m_str = NULL;
 }
 m_uCount = 0;
}

/**-----------------------------------------------------------------------------
*  ���ش�С
*------------------------------------------------------------------------------
*/
unsigned String::size()
{
 return m_uCount;
}

/**-----------------------------------------------------------------------------
*  �ж��Ƿ�Ϊ��
*------------------------------------------------------------------------------
*/
bool String::empty()
{
 return !m_uCount;
}

/**-----------------------------------------------------------------------------
*  ת��
*------------------------------------------------------------------------------
*/
const char* String::c_str() const
{
 return m_str;
}

/**-----------------------------------------------------------------------------
*  �����ַ�char
*------------------------------------------------------------------------------
*/
void String::insert( unsigned pos, const char& ch )
{
 assert( pos <= m_uCount );

 char* t = new char[m_uCount]; // ����ʱ��ԭ���ַ���������ʱ������
 strcpy_s( t,m_uCount+1,m_str ); 

 m_str = new char[m_uCount +2]; // ���·����ڴ�

 strncpy_s(m_str,m_uCount+2,t,pos);  //��ǰt���ַ����Ƶ�������

 *(m_str+pos) = ch;  // ����ֵ

 *(m_str+pos+1) = '\0';
 /*strcat_s(m_str,m_uCount+2,tmp+pos);*/
 strncat_s(m_str,m_uCount+2,t,m_uCount - pos );

 m_uCount++;

 /*SafeRelease_Array(t);*/  //--==>>һ��Ϊ�����bug
}
/**-----------------------------------------------------------------------------
*  ����string
*------------------------------------------------------------------------------
*/
void String::insert( unsigned pos, const String& ss )
{
 assert( pos <= m_uCount );

 char* t1 = new char[ pos +1 ];
 strncpy_s(t1,pos+1,m_str,pos);

 char* t2 = new char[ m_uCount - pos + 1 ];
 strncpy_s(t2,m_uCount-pos+1,m_str+pos,m_uCount - pos );
 
 m_str = new char[m_uCount + ss.m_uCount + 1];
 strcpy_s(m_str,pos+1,t1);
 SafeRelease_Array( t1 );

 strcat_s(m_str,ss.m_uCount + m_uCount + 1,ss.m_str);
 strcat_s(m_str,ss.m_uCount + m_uCount + 1,t2 );
 m_uCount += ss.m_uCount;

 SafeRelease_Array( t2 );
}
/**-----------------------------------------------------------------------------
*  push_back
*------------------------------------------------------------------------------
*/
void String::push_back( const char& ch )
{
 insert( m_uCount, ch );
}

/**-----------------------------------------------------------------------------
*  push_front
*------------------------------------------------------------------------------
*/
void String::push_front( const char& ch )
{
 insert( 0, ch );
}
/**-----------------------------------------------------------------------------
*  ɾ������λ��
*------------------------------------------------------------------------------
*/
bool String::erase( const unsigned& pos )
{
 /*assert( pos < m_uCount );*/
 if( pos >= m_uCount )
 {
  return false;
 }
 char* t = new char[m_uCount+1];
 strcpy_s(t,m_uCount+1,m_str);
 
 SafeRelease_Array(m_str);

 m_str = new char[m_uCount];
 strncpy_s(m_str,m_uCount,t,pos);
 strncat_s(m_str,m_uCount,t+pos+1,m_uCount-pos-1);
 
 m_uCount--;
 SafeRelease_Array( t );

 return true;
}

/**-----------------------------------------------------------------------------
*  ɾ������λ��
*------------------------------------------------------------------------------
*/
bool String::erase( const unsigned& begin,const unsigned& end ) // ע�⣬�����Ǳ����䣬��string�಻ͬ��string����[ )�뿪�������
{
 assert( begin <= end );
 if(end>=m_uCount)
  return false;
 if( begin == end )
 {
  erase( begin );
 }
 else
 {
  unsigned gap = end - begin;
  char* t = new char[m_uCount+1];
  strcpy_s(t,m_uCount+1,m_str);
  SafeRelease_Array(m_str);
  int size = m_uCount - gap;
  m_str = new char[size];
  strncpy_s(m_str,size,t,begin);
  strncat_s(m_str,size,t+end+1,size - end-1);

  m_uCount -= (gap+1);

  SafeRelease_Array( t );
 }
 
 return true;
}

/**-----------------------------------------------------------------------------
*  ���� = 
*------------------------------------------------------------------------------
*/
String& String::operator = ( const String& ss )
{
 clear();
 unsigned n = ss.m_uCount;
 if( n )
 {
  m_str = new char[ n + 1 ];
  strcpy_s( m_str,n+1,ss.m_str );
  m_uCount = ss.m_uCount;
 }
 
 return *this;
}
/**-----------------------------------------------------------------------------
*  ����+=
*------------------------------------------------------------------------------
*/
String& String::operator += ( const String& ss )
{
 // ������һ��Сbug,����Լ�+�Լ��ͻ�������磺 ss += ss; �޸ĺ�������
 //if( ss.m_uCount )
 //{
 // char* tmp = new char[ m_uCount + 1 ];
 // strcpy_s(tmp,m_uCount+1,m_str);

 // delete []m_str;
 // m_str = new char[ m_uCount + ss.m_uCount + 1];
 // strcpy_s( m_str,m_uCount+1,tmp );
 // delete []tmp;
 // strcat_s( m_str,m_uCount+ss.m_uCount+1,ss.m_str );

 // m_uCount += ss.m_uCount;
 //}
 if( ss.m_uCount )
 {
  String temp1(*this);
  String temp2(ss);
  m_uCount += ss.m_uCount;

  delete []m_str;
  m_str = new char[ m_uCount + 1 ];
  strcpy_s( m_str,temp1.m_uCount+1,temp1.m_str );
  strcat_s( m_str,m_uCount + 1,temp2.m_str );  
 }

 return *this;
}
/**-----------------------------------------------------------------------------
*  ���� +
*------------------------------------------------------------------------------
*/
String String::operator + ( const String& ss )
{
 if( !ss.m_uCount )  // ���ssΪ����ֱ�ӷ���
 {
  return *this;
 }
 else  // ��������Ѿ����ڵ�+=��^_^   ������
 {
  String temp(*this);
  temp += ss;

  return temp;
 }
}
/**-----------------------------------------------------------------------------
*  ���� ==
*------------------------------------------------------------------------------
*/
bool String::operator == ( const String& ss )
{
 if( !strcmp( m_str,ss.m_str ) )
 {
  return true;
 }
 else
  return false;
 //ò�������и����棺
 //warning C4800: ��int��: ��ֵǿ��Ϊ����ֵ��true����false��(���ܾ���)
 /*return !static_cast<bool>( strcmp( m_str,ss.m_str ) );*/
}

/**-----------------------------------------------------------------------------
*  ���� <
*------------------------------------------------------------------------------
*/
bool String::operator < ( const String& ss )
{
 int mark = strcmp( m_str,ss.m_str );
 if( mark < 0 )
  return true;
 else
  return false;
}

/**-----------------------------------------------------------------------------
*  ���� >
*------------------------------------------------------------------------------
*/
bool String::operator > ( const String& ss )
{
 // ���������ǲ����ܵġ�����
 //return !( *this < ss );
 int mark = strcmp( m_str,ss.m_str );
 if( mark > 0 )
  return true;
 else
  return false;
}

/**-----------------------------------------------------------------------------
*  ȡֵ ����[]
*------------------------------------------------------------------------------
*/
char& String::operator [] ( unsigned n )
{
 assert( n < m_uCount );

 return *(m_str+n);
}
/**-----------------------------------------------------------------------------
*  ������������
*------------------------------------------------------------------------------
*/
ostream& operator << ( ostream& os, const String& ss )
{
 os<<ss.m_str;

 return os;
}
/**-----------------------------------------------------------------------------
*  �������������
*------------------------------------------------------------------------------
*/
istream& operator >> ( istream& is, String& ss )  // ����ʱ��������ո�
{
 ss.clear();
 is>>ss.m_str;

 ss.m_uCount = static_cast<unsigned>(strlen( ss.m_str ));

 return is;
}
