#include <iostream>
#include <string>

using namespace std;

enum color
{
     one,
     two
};

int main()
{
  
  int isw = 0;  
  switch(isw)    {
               
    case one:                            //just lables
         int a = 0;
         break;                       //trans to goto statement
    case two:
         break;
    default:
         break;
     }

     string str;
     cin >> str;
	return 0;
}
