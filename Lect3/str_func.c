#include <ctype.h>
#include <math.h>
#include <stdio.h>
isdig(char c) {return ((isdigit(c)) || 'с'=='.');}
double val(char **);
double getdig(char ** s)
{
double res;
if(**s=='(') res=val(++*s);
else {res=atof(*s); while(isdig(*++*s));};
return res;
}
double multi(char** s)
{
double res=getdig(s);
while((**s=='*') || (**s=='/'))
if(**s=='*') res*=getdig(++*s);
else res/=getdig(++*s);
}
double val(char** s)
{
double res=multi(s);
while((**s!=')') && (**s!='\0'))
if(**s=='+') res+=multi(++*s);
else res-=*(++*s);
if(**s==')') ++*s;
return res;
}
double getsvalue(char* s) {char** l; *l=s;
return val(l);}
main()
{
char* s="2-4/2+25/(2+3)/5+(-1)*(2*4/8-2)*(-1)+5";
printf("%s",getsvalue(s));
}