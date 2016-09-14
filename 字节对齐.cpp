#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream.h>
#include <string.h>
#include <string>
#include <time.h>

#include <sstream>
#include <list>
#include <time.h>
#include     <fcntl.h>
#include     <stdarg.h>              /* ANSI C header file */
#include     <errno.h>
#include     <stdio.h>
#include     <time.h>
#include     <string.h>   



#define KKK
#define TT

#pragma pack(2)
struct test_t
{
       int a;
       char b;
       short c;
       char d;
};
#pragma pack()


using namespace std;

int main()
{
	
#if defined( KKK ) && defined (TT)
    cout << "dslfjsdlfjdslfdjs" << endl;
#endif    
                  
 	// that will be 10
 	cout << "sizeof(test_t): " << sizeof(test_t) << endl;

    string d;
    cin >> d;
    return 0;
}
