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
               int a = 0;       //a�����ﶨ�壬��Ч�ڵ�switch��}�����ֱ������case2���˱�����û�ж���� �����Ա��벻�� 
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
