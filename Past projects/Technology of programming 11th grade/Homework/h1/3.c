// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
Да се намерят и изведат всички прости числа завършващи на 3 в интервал [x,y].
*/

#include <stdio.h>

int main(){
	int x,y,n,c;
	while(x>y){
	printf("Enter two numbers: ");
	scanf("%d %d",&x,&y);
	}

		  for (n=x; n<=y; n++){

        if(n%10==3){
            for ( c = 2 ; c <= n - 1 ; c++ ){
                      if ( n%c == 0 ){

                 break;
                      }
               }
               if ( c == n )
                      printf("%d is prime.\n", n);

                      }
                      }

	scanf("%d",c);
	return 0;
}

