// �������: ���� ( http://www.elsys-bg.org/ )
// ����: 11 �
// �����: 16
// ���: ������ ����� ������

/*������: �� �� ��������� ��������, ����� ������� �� ����������� �� ������ ��� ����������� �����, x � y, ������ x < y.
�� �� ������ ������ �� ������ ������� ����� � ��������� [x,y]. */

#include <stdio.h>

int main(){
	int x,y,sum=0;
	while(x>y){
	printf("Enter two numbers: ");
	scanf("%d %d",&x,&y);
	}
	while(x<=y){
		if(x%2!=0){
			sum=sum+x;
		}

		x++;
	}

	printf("Sumata e: %d",sum);
	scanf("%d",sum);
	return 0;
}
