#include <iostream>
#include <string>

using namespace std;


class bird
{
public:
    virtual string getname() = 0;
    
    virtual int value() = 0;
    
};

class pingui: public bird
{
public:
       string getname()
       {
           return "pinpin ";
       }
       
       int value()
       {
           return 5;
       }
};

class chicken: public bird
{
public:
       virtual string getname()
       {
              return "chichi ";
       }
       
       int value()
       {
           return 1;
       }
};


class decorator: public bird
{
public:
    void set_bird(bird *b)
    {
        m_bird = b;
    }
        
    virtual int myvalue() = 0;
    virtual string myname() = 0;

    int value()
    {
        int x=m_bird->value() + myvalue();
        return x;
    }
        
       
    virtual string getname()
    {
      string tmp = m_bird->getname() + myname();
      return tmp;
    }

    bird *m_bird;
};

class hat:public decorator
{
public:
      int myvalue()
      {
          return 11;
      }
       
       virtual string myname()
       {
         return "with a hat ";
       }
};

class diamond:public decorator
{
public:
       int myvalue()
       {
           return 10000;
       }
       
       virtual string myname()
       {
         return "with a bigdiamond ";
       }
};
    

int main()
{

    bird *chichi = new chicken();
    cout <<     chichi->getname() << endl;
    //chichi->value();

    cout << chichi->value() << endl;
    decorator *dia = new diamond();

    dia->set_bird(chichi);

    decorator *ha = new hat();

    ha->set_bird(dia);
    cout << dia->value() << endl;
    cout << ha->value() << endl;
    cout << ha->getname() << endl;
    string str;
    cin >> str;
    return 0;
  }
