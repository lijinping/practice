/* va_start example */
#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

void PrintFloats (int n, ...)
{
  int i;
  double val;
  printf ("Printing floats:");
  va_list vl;
  va_start(vl,n);
  for (i=0;i<n;i++)
  {
    val=va_arg(vl,double);
    printf (" [%.2f]",val);
  }
  va_end(vl);
  printf ("\n");
}

int main ()
{
  PrintFloats (5,2.11,3.14159,2.71828,1.41421);
  getchar();
  return 0;
}


/* vsprintf example */
#include <stdio.h>
#include <stdarg.h>

void PrintFError ( const char * format, ... )
{
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsprintf (buffer,format, args);
  perror (buffer);
  va_end (args);
}

int main ()
{
  FILE * pFile;
  char szFileName[]="myfile.txt";

  pFile = fopen (szFileName,"r");
  if (pFile == NULL)
    PrintFError ("Error opening '%s'",szFileName);
  else
  {
    // file successfully open
    fclose (pFile);
  }
  return 0;
}
