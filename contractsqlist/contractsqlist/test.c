#include"contract.h"
void menu()

{
	printf("***********************\n");
	printf("******1.�����ϵ��*******\n");
	printf("******2.ɾ����ϵ��*******\n");
	printf("******3.������ϵ��*******\n");
	printf("******4.������ϵ��*******\n");
	printf("******5.չʾͨѶ¼*******\n");
	printf("******0.��  ��   *******\n");
	printf("***********************\n");


}
int main()
{
	PeoInfo *con=NULL;
	int count = 0;
	do
	{
		menu();
		scanf("%d", &count);
		switch (count)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break; 
		case 3:
			FindContact(con);
		    break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(con);
			break;
		case 0:
			break;
		default:
			printf("�������\n");
		}
	}
	while (count);
	DestroyContact(&con);
	return 0;
}