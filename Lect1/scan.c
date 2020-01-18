#include <stdio.h>

// cross-platform scanf
#ifndef _MSC_VER

  #define scanf_s( fmt, ... ) scanf( scanf_validate( fmt, __FILE__, __LINE__ ), __VA_ARGS__ )

  const char* scanf_validate( const char* fmt, const char* file, long line )
    {
    const char* p = fmt;
    while (1) {
      p = strstr( p, "%s" );
      if (p == NULL) break;
      if ((p == fmt) || (*(p-1) != '%')) {
       fprintf( stderr, "Hey, you used \"%%s\" in %s: line %d!\n", file, line );
        abort();
        }
      }
    return fmt;
    }

#endif 


int main(){
  char s[10];
  int x,x1,x2;
  char c;
  scanf_s("%9s", s);
  scanf_s(" %c",&c);

  printf("\ns=%s; c=%c\n",s,c); 
  char c1[4];
  scanf_s(" %4c", &c1, 4); // not null terminated
  printf("\n c1=%s \n",c1); /*warning: format ‘%c’ expects argument of type ‘int’, but argument 2 has type ‘char *’ [-Wformat=] */


  scanf_s("%d",&x,2);
  scanf_s(" %d",&x1); // tha same

  printf("\nx=%d x1=%d\n",x,x1);

  fscanf(stdin," %d",&x2);
  printf("x2=%d",x2);

}

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

s=aaaaaaaaa; c=a
c1=p
a=4196589 0h
*/

/*

ewrewr

s=ewrewr; c=

34
3

 c1=34
3 
534534
454

x=534534 x1=454*/

/*
spaces
12345678910 df

s=123456789; c=1

 c1=0 df 
123456 78910

x=123456 x1=78910
3456
x2=3456

*/

/*
12345 678910

s=12345; c=6

 c1=7891 
3424 324234234

x=0 x1=3424
x2=324234234
*/
