// �������: ���� ( http://www.elsys-bg.org/ )
// ����: 11 �
// �����: 16
// ���: ������ ����� ������

/*������: �� �� ��������� ��������, ����� ������� �� ����������� �� ������ ��� ����������� �����, x � y, ������ x < y.
�� �� ������ � ������ ������ �� ������� ������ �� �� 17 � �������� [x, y].
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
