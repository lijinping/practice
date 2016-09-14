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
            
       virtual ~Base( void ) //基类没有虚析构函数时
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
 	
 	//通过基类的指针去删除派生类的对象，而基类又没有虚析构函数时，结果将是不可确定的。
    //(此处是派生类的析构函数没有被调用。)
    
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
