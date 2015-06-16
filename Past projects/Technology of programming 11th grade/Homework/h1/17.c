// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе число x, където x e интервала (0;1).
Да се намери сумата от сбора на реципрочните стойности за всеки две twin primes.
Развитието да продължи докато отношението не стане по-малко то x.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n){
   int c,isPrime=0;
   for ( c = 2 ; c <= n - 1 ; c++ ){
      if ( n%c == 0 ){
         break;
      }
   }
   if ( c == n ){
     isPrime=1;

   }
   return isPrime;
}

int main(){
    float x,temp,temp2,r1,r2;
    int c,n,n2,once;
    long y;
     y = 10000000;
    printf("Vuvedete chislo v intervala(0;1): ");
    scanf("%f",&x);

    for(c=0;c<=y;c++){
    n=checkPrime(c);
    r1=c;

    n2=checkPrime(c+2);
    r2=c+2;

       if(n==1 && n2==1){
            if(once==1){
              temp2 = (1/r1)+(1/(r2));
              once=0;
              if(temp+temp2<x) {printf("%f e po malko ot %f\n",(temp+temp2),x); break;}
              else continue;
            }
          temp = (1/r1)+(1/(r2));
            c=c+2;
          once=1;
       }
    }


	scanf("%d",c);


    return 0;
}
