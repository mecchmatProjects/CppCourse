#include <stdio.h>
#include <stdbool.h> // Since C99
#include <locale.h>
 
int conditions(void)
{
    bool a = true, b=(1<0);
    bool c = a&&b; // c==false 
    int  d = a||b;
    char e = !b;
    
    printf("%s",c?"true":"false");
    printf("(%d %i %u",c,d,e);
    
    double r;
    scanf("%lf",&r);
    
    if(r>2){
        printf("r(%lf)>2\n",r);
    }
    else{
        printf("r(%lf)<=2\n",r);
    }
    
    if((r>-1)&&(r<1)){
        printf("|%lf|<1\n",r);
    }
    else if ((r==1) || (r==-1)){
        printf("|r(%lf)=1|\n",r);
    }
    else {
        printf("|r|>1\n");
    }
    
    long long int f=1L;
    for(int i=1;i<16;++i){
        f*=i;
        }
    printf("f=%Ld",f);
    
    return 0;
}


int f3()
{
   int tr, fal;
   tr=(11<=15); /* вираз істинний */
   fal=(1>1); /* вираз хибний */
   printf("tr= - %d false - %d ", tr, fal);
   return 0;
}


int main(){
setlocale(LC_ALL, "uk_UA.UTF-8");
int points;
printf("Введіть оцiнку [2..5]:");
scanf("%d",&points);
printf("%s",points>3?"Ви добре знаєте матеріал!":"Погано...");

conditions();
}
