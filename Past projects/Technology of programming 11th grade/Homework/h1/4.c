// �������: ���� ( http://www.elsys-bg.org/ )
// ����: 11 �
// �����: 16
// ���: ������ ����� ������

/*������: �� �� ��������� ��������, ����� ������� �� ����������� �� ������ ��� ����������� �����, x � y, ������ x < y.
 �� �� ������� � ������� ������ ����� �� �������� � ��������� [x, y].
*/

#include <stdio.h>

int main(){
	int x,y,n,c;

	printf("Enter number: ");
	scanf("%d",&y);

	x=1;
	c=1;
	n=0;
	while(c<y){
            n=n+c;
            c=c+n;
            if(n>y) break;
            printf("Fibonnaci number: %d\n",n);
            if(c>y) break;
            printf("Fibonnaci number: %d\n",c);
            x=x+1;
            }


	scanf("%d",c);
	return 0;
}

