#include <iostream>
#include <string>

using namespace std;

class abc
{
private:
        void show();
public:
       void kk();
       void ss()
       {
            cout << "thisis ss" << endl;
       }
};

enum color
{
     red,
     black,
     blue,
     green
};

union uu
{
      int iuu;
      long  long luu;
      char cuu[4];
};
     
int main()
{

abc d;
d.ss();
//d.show();

int a[5] = {3};
cout << *a << endl;
cout << &a[0] << endl;

color ca;
ca=green;
cout << ca << endl;

cout << "-----------------union---------------" << endl;
long long x=57;
uu uu_instance;
memcpy(&uu_instance,(void *)&x, sizeof(long long));
cout << sizeof(uu_instance) << endl;
cout << uu_instance.iuu << endl;
cout << uu_instance.luu << endl;
cout << uu_instance.cuu << endl;
string str;
cin >> str;
return 0;
}    
