
#include <stdlib.h>
#include <iostream.h>


int main()
{
    
     char *p=(char *)calloc(sizeof(int),4);
     strcpy(p,"123456789");
     cout << p << endl;
     free(p);
     p=NULL;
     free(p);
     int a;
     cin >> a;
     return 0;
}
     
