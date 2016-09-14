#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//#include <errorno.h>

using namespace std;
int main( void )
{

  char ddff[10];    
    char *p=ddff;
    int isw=0;
    switch(isw)
    {
               
    case 1:
         //{
               int a = 0;       //a在这里定义，有效期到switch的}，如果直接走了case2，此变量是没有定义的 ，所以编译不过 
               break;
         //}
    case 2:
         p = NULL;
         break;
    default:
         p = NULL;
         break;
     }

  
 	system( "PAUSE" );
 	return EXIT_SUCCESS;
}
