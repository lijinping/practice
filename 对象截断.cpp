#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

using namespace std;

class base
{
public:
	virtual void show()
  {
		cout << "this is base." << endl;
	}
};

class child:public base
{
public:
	virtual void show()
	{
		cout << "this is child." << endl;
	}
};
                     

void show( base b )
{
     b.show();
}


int main(  )
{
    child a;
    show(a);		//show this base.
    
    char pp[100];
    char *kl = pp;
    strcpy(kl,"23456");
    kl += 7;
    strcpy(kl,"abcde");      //this will not show,because 0 is before them
    cout << pp << "33" << endl;
    //cout << pp+7 << "33" << endl;

 	system( "PAUSE" );
 	return 0;
}
