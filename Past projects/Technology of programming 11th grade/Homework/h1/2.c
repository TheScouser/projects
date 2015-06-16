// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
Да се намери и изведе сумата на числата делящи се на 17 в интервал [x, y].
*/

#include <stdio.h>

int main(){
	int x,y,sum=0;
	while(x>y){
	printf("Enter two numbers: ");
	scanf("%d %d",&x,&y);
	}
	while(x<=y){
		if(x%17==0){
			sum=sum+x;
		}

		x++;
	}

	printf("Sumata e: %d",sum);
	scanf("%d",sum);
	return 0;
}
