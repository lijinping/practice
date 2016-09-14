#include <iostream>
using namespace std;

class Base
{
public:
       Base( void )
       {
             cout << "Base::Base( )" << endl;
       }
       
       virtual void kkk()
       {
            cout << " kkk base." << endl;
       }
            
       virtual ~Base( void ) //����û������������ʱ
       {
              cout << "Base::~Base( )" << endl;
       }
};

class Derived : public Base
{
public:
       Derived( void )
       {
                m_pData = new int;
                cout << "Derived::Derived( )" << endl;
       }
       
       virtual void kkk()
       {
            cout << " kkk Derived." << endl;
       }
       
       virtual ~Derived( void )
       {
                delete m_pData;
                m_pData = NULL;
                cout << "Derived::~Derived( )" << endl;
       }
       
       int cc;
private:
        int* m_pData;
};

int main( void )
{
    Base bo;
    Derived* pD = new Derived;
    
 	Base* pB = pD;
 	
 	//ͨ�������ָ��ȥɾ��������Ķ��󣬶�������û������������ʱ��������ǲ���ȷ���ġ�
    //(�˴������������������û�б����á�)
    
    pB->kkk();              //child
    
    Base &ba = *pD;

    ba.kkk();                  //child
    
    Base bb = *pD;             //object truncate
    bb.kkk();                  //base

    
    
 	delete pB;                  //undefined
 	pB = NULL;
    
 	system( "PAUSE" );
 	return EXIT_SUCCESS;
}
