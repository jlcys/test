#include"sq.h"
void menu()

{
	printf("********************\n");
	printf("******1.��  ��*******\n");
	printf("******2.ɾ  ��*******\n");
	printf("******3.��  ��*******\n");
	printf("******4.��  ��******\n");
	printf("******5.չ  ʾ*******\n");
	printf("******0.��  ��*******\n");
	printf("********************\n");


}
int main()
{
	PeoInfo* con = NULL;
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
	} while (count);
	DestroyContact(&con);
	return 0;
}