#include <iostream>
#include <string>

using namespace std;

#pragma pack(1)
//why this doesn't work?
struct pp
{
       pp *prev;
       pp *next;
};

struct abc
{
       int a;
       pp  pp_in_abc;
};

struct def
{
       int b;
       char c;
       pp pp_in_def;
};

int main()
{
    pp pp_instance;
    pp_instance.prev = NULL;     
    pp_instance.next = NULL;
    
    abc abcin;
    abcin.a = 100;
    abcin.pp_in_abc = pp_instance;
    
    def defin;
    defin.b = 99;
    defin.c = 59;
    defin.pp_in_def.prev = &abcin.pp_in_abc;
    
    pp *pp_head = &defin.pp_in_def;
    
    cout << (void *)&defin.b << endl;
    cout << (void *)&defin.c << endl;
    cout << (void *)&defin.pp_in_def << endl;
    
    char *p = (char *)pp_head;
    char *p2 = p - 5;
    cout << *(int *)( p2 ) << endl;
    
    p = (char *)(pp_head->prev);
    cout << *(int *)( p - 4 ) << endl;
    string str;
    cin >> str;
    return 0;
}
