#include <iostream>
using namespace std;

    int intarr[8] = {1,2,4,5,6,7,8,9};

void to_find( int begin, int end )
{
     int j = 7;
     
    if( begin == end )
    {
        if( intarr[begin]==j )
        {
            cout << "found here: " << begin << endl;
            }
        else
                cout << "not found." << endl;
        return;
    }
     
    if( intarr[(begin+end)/2] > j )
    {
        end = (begin+end)/2-1;
        to_find( begin, end );
    }
    else if( intarr[(begin+end)/2] < j )
    {
         begin = (begin+end)/2+1;
         to_find( begin, end );
    }
    else
    {
        cout << " it is here: " << (begin+end)/2 << endl;
        return;
    }
    

    

}


int main( void )
{

    
    to_find(0,7);
        
    

    
 	system( "PAUSE" );
 	return EXIT_SUCCESS;
}
