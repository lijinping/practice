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
         int a = 0;  //a在这里定义，有效期到switch的}，如果直接走了case2，此变量是没有定义的 ，所以编译不过.
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
