
/* setlocale example */
#include <stdio.h>      /* printf */
#include <locale.h>     /* struct lconv, setlocale, localeconv */

#include <time.h>
#include <string.h>


int main_locale1 ()
{
    printf ("Locale is: %s\n", setlocale(LC_ALL, NULL) );
    setlocale (LC_ALL,"");
    struct lconv * lc;
 
    lc = localeconv();
    printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);
    setlocale (LC_ALL,"Ukrainain");
    printf ("íàøà âàëþòà: %s\n-\n",lc->currency_symbol);

  return 0;
}

#include <stddef.h> // wchar_t
int main12()
{
   int   i, result;
   float fp;
   char  c, s[81];
   wchar_t wc, ws[81];
   result = scanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws ); // C4996
   // consider using scanf_s and wscanf_s
   printf( "The number of fields input is %d\n", result );
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);

}



int main_locale(){
    setlocale(LC_ALL,"Ukrainian");
    
    printf("Привіт! Введіть щось:");
    char text[10];
    // До пробілів scanf("%s", text);
    // printf("текст %s",text);
    
    //scanf("%[^\n]%*c",text); // 1. як послідовність char 
    scanf("%[^\n]",text); // 2.як текст
    //3. fputs(text, 10, stdin); // CString -style бібліотека 
    
    //printf("текст %s",text); 
    fputs(text,stdout); // CString -style бібліотека
    
    
    time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  struct lconv * lc;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  int twice=0;

  do {
    printf ("Locale is: %s\n", setlocale(LC_ALL,NULL) );

    strftime (buffer,80,"%c",timeinfo);
    printf ("Date is: %s\n",buffer);

    lc = localeconv ();
    printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);

    setlocale (LC_ALL,"");
  } while (!twice++);
    
    return 0;   
}


#define __STDC_WANT_LIB_EXT1__ 1

int mainInf1(void)
{
    int i, j;
    float x, y;
    char str1[10], str2[4];
    wchar_t warr[2];
    setlocale(LC_ALL, "uk_UA.UTF-8");
 
    char input[] = "25 23,656 Інформатика 56789 0123 56ß水";
    /* parse as follows:
       %d: an integer
       %f: a floating-point value
       %24s: a string of at most 21 non-whitespace characters (*2 for ukr_utf-8)
       %2d: two-digit integer (digits 5 and 6)
       %f:  a floating-point value (digits 7, 8, 9)
       %*d: an integer which isn't stored anywhere
       ' ': all consecutive whitespace
       %3[0-9]: a string of at most 3 decimal digits (digits 5 and 6)
       %2lc: two wide characters, using multibyte to wide conversion  */
    int ret = sscanf(input, "%d%f%22s%2d%f%*d %3[0-9]%2lc",
                     &i, &x, str1, &j, &y, str2, warr);
 
    printf("Converted %d fields:\ni = %d\nx = %f\nstr1 = %s\n"
           "j = %d\ny = %f\nstr2 = %s\n"
           "warr[0] = U+%x warr[1] = U+%x\n sz=%lu",
           ret, i, x, str1, j, y, str2, warr[0], warr[1], sizeof("Інформатика"));
 
#ifdef __STDC_LIB_EXT1__
    int n = scanf_s( "%d%f%s", &i, &x, str1);
    // writes 25 to i, 5.432 to x, the 9 bytes "thompson\0" to str1, and 3 to n.
    printf("N=%d",n);
#else
     printf("Use C11");
#endif

char x1 = getchar();
    return x1;
}

/*
Output:

Converted 7 fields:
i = 25
x = 5.432000
str1 = Thompson
j = 56
y = 789.000000
str2 = 56
warr[0] = U+df warr[1] = U+6c34
  sz =24
 */