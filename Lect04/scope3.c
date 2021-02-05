
#include <stdio.h>
// ôóíêö³ÿ, ùî çíàõîäèòü n!
unsigned long long int MyFact(int n) // ïî÷àòîê îáëàñò³ âèäèìîñò³ ôîðìàëüíîãî ïàðàìåòðó n
{
    int i;
    unsigned long long int f = 1; // ðåçóëüòàò

    for (i=1; i<=n; i++)
        f = f*i;

    return f;   // ê³íåöü îáëàñò³ âèäèìîñò³ ôîðìàëüíîãî ïàðàìåòðó n
}
//Âèêëèê ôóíêö³¿ ç ³íøîãî ïðîãðàìíîãî êîäó (³íøî¿ ôóíêö³¿):
// âèêëèê ôóíêö³¿ ç ³íøîãî ïðîãðàìíîãî êîäó


int a = 20; /* ãëîáàëüí³ çì³íí³ */
int sum(int a, int b);
int main() {   /* ëîêàëüí³ çì³íí³ â main function */
  int a = 10; int b = 20; int c = 0;
  printf ("value of a in main() = %d\n",  a);
  c = sum( a, b);
  printf ("value of c in main() = %d\n",  c);
int k;
unsigned long long int fact;
k = 6;
fact = MyFact(k); // fact = 6! = 720
printf ("value of factorial in main() = %Ld\n",  fact);
  
  return 0;
}

/* ôóíêö³ÿ äîäàâàííÿ */
int sum(int a, int b) {
   printf ("value of a in sum() = %d\n",  a);
   printf ("value of b in sum() = %d\n",  b);
   return a + b;
}