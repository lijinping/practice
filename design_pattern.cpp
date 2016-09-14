#include <iostream>
#include <string>

using namespace std;

class Duck;

class Ob
{
public:
    virtual void update(Duck *pDuck)=0;
    virtual ~Ob(){};
};

class ZhuanJia: public Ob
{
  virtual void update(Duck *pDuck);
  virtual ~ZhuanJia(){};
};


class Duck
{
public:
    Duck()
    {
        memset(m_pOb,0,10*sizeof(Ob *));
    }
    
    virtual ~Duck()
    {
    }

    virtual void setname(string &name)=0;

    virtual string & showname()=0;

    virtual void showMyColor() = 0;

    virtual void registerOb(Ob *pOb)
    {
        for( int i=0; i<10; i++)
        {
            if(m_pOb[i] == NULL)
            {
                m_pOb[i] = pOb;
                break;
            }
        }
    }
    virtual void notify(Duck *pDuck)
    {
        for( int i=0; i<10; i++)
        {
            if(m_pOb[i] != NULL)
            {
                m_pOb[i]->update(pDuck);
            }
        }   
    }
    Ob *m_pOb[10];
};

class ObsevableDuck: public Duck
{
public:
    ObsevableDuck()
    {
          m_name="";
    }
          
    virtual void showMyColor() = 0;

    virtual void setname(string &name)
    {
        m_name = name;
    }

    virtual ~ObsevableDuck()
    {
    }
    
    virtual string & showname()
    {
        return m_name;
    }
    string m_name;
};

void ZhuanJia::update(Duck *pDuck)
{
    cout << "LOOK,  duck:" << pDuck->showname() << "  just show." <<  endl;
} 
  
class RedDuck: public ObsevableDuck
{
public:
    virtual void showMyColor()
    {
        cout << "i am RedDuck." << endl;
        notify(this);
    }
};

class BlueDuck: public ObsevableDuck
{
public:
    virtual void showMyColor()
    {
        cout << "i am BlueDuck."<< endl;
        notify(this);
    }
};


class GreenDuck: public ObsevableDuck
{
public:
    virtual void showMyColor()
    {
        cout << "i am GreenDuck."<< endl;
        notify(this);
    }
};

class ZhuangShi: public Duck
{
public:
    ZhuangShi(Duck *pDuck)
    {
        m_pDuck = pDuck;
    }

    ~ZhuangShi()
    {
        delete m_pDuck;
        m_pDuck = NULL;
    }

    virtual void registerOb(Ob* pob)
    {
        m_pDuck->registerOb(pob);
    }

    virtual void setname(string &name)
    {
        m_pDuck->setname(name);
    }

    virtual string & showname()
    {
        return m_pDuck -> showname();   
    }
    virtual void showMyColor()
    {
        m_pDuck -> showMyColor();
        times++;
    }
    Duck *m_pDuck;
    static int times;
};

int ZhuangShi::times = 0;

class DuckFactory
{
public:
    virtual Duck * createRedDuck() = 0;
    virtual Duck * createBlueDuck() = 0;
    virtual Duck * createGreenDuck() = 0;
    virtual ~DuckFactory(){};
};

class CommonDuckFactroy: public DuckFactory
{
public:
    virtual Duck * createRedDuck()
    {
        return new RedDuck();
    }

    virtual Duck * createBlueDuck()
    {
        return new BlueDuck();
    }
    virtual Duck * createGreenDuck()
    {
        return new GreenDuck();
    }

};


class CountDuckFactroy: public DuckFactory
{
public:
    virtual Duck * createRedDuck()
    {
        return new ZhuangShi( new RedDuck() );
    }

    virtual Duck * createBlueDuck()
    {
        return new ZhuangShi( new BlueDuck());
    }


    virtual Duck * createGreenDuck()
    {
        return new ZhuangShi(new GreenDuck());
    }

};

class Component: public Duck
{
public:
    Component()
    {
        memset(duckArray,0,10*sizeof(Duck *));
    }

    virtual void showMyColor()
    {
        for( int i=0; i<10; i++ )   //可以使用iterator模式 
        {
            if( duckArray[i] != NULL )
            {
                duckArray[i]->showMyColor();
            }
        }
    }

    virtual void setname(string &name)
    {
    }

    virtual string & showname()
    {
        string *p = new string("iamgroup.");
        return *p;   
    }

    virtual void registerOb(Ob *pob)
    {
       for( int i=0; i<10; i++ )   //可以使用iterator模式 
        {
            if( duckArray[i] != NULL )
            {
                duckArray[i]->registerOb(pob);
            }
        }   
    }

    void AddItem(Duck *pDuck)
    {
        for( int i=0; i<10; i++ )
        {
            if( duckArray[i] == NULL )
            {
                duckArray[i] = pDuck;
                break;
            }
        }   
    }
    Duck *duckArray[10];
};

class Yeji
{
public:
    void IamBeauty()
    {
        cout << "i am beauty jiji adapte to YAYA." << endl;
    }
};

class AdapterYeji: public ObsevableDuck
{
public:
    AdapterYeji(Yeji *pji)
    {
        m_pji = pji;
    }

    virtual void showMyColor()
    {
        m_pji->IamBeauty();
        notify(this);
    }
    
    virtual ~AdapterYeji(){};

    Yeji *m_pji;
    
};


class Duck_Moni
{
public:
    void Run(DuckFactory *pDuckFactory)
    {
         Duck *redduck = pDuckFactory->createRedDuck();
         Duck *blueduck = pDuckFactory->createBlueDuck();
         Duck *greenduck = pDuckFactory->createGreenDuck();


         Duck *redduck2 = pDuckFactory->createRedDuck();
         Duck *blueduck2 = pDuckFactory->createBlueDuck();
         Duck *greenduck2 = pDuckFactory->createGreenDuck();

         Yeji *pji = new Yeji();
         AdapterYeji *pji_like_duck = new AdapterYeji(pji);
         pji_like_duck->m_name = "yeji ";

         ZhuanJia *pZJ= new ZhuanJia();


         Component myCom;
         string name="RR2";
         redduck2->setname(name);
         myCom.AddItem(redduck2);
         myCom.AddItem(blueduck2);
         myCom.AddItem(greenduck2);
         myCom.AddItem(pji_like_duck);

         myCom.registerOb(pZJ);

        Component AllCom;
        AllCom.AddItem(redduck);
        AllCom.AddItem(blueduck);
        AllCom.AddItem(greenduck);
        AllCom.AddItem(&myCom);
        
         DuckShow(&AllCom);
         cout << "times: " << ZhuangShi::times << endl;
        cout << redduck2->showname() << endl;

         delete redduck;
         delete blueduck;
         delete greenduck;
         delete redduck2;
         delete blueduck2;
         delete greenduck2;
    }
private:
    void DuckShow(Duck *pDuck)
    {
         pDuck->showMyColor();
    }
         
};



int main()
{
    Duck_Moni dm;
    DuckFactory *pfac =  new CountDuckFactroy();
    dm.Run(pfac);
    
    string x;
    cin >> x;
    return 0;
}
