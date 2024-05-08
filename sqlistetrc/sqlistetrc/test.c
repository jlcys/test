#include"sq.h"
void menu()

{
	printf("********************\n");
	printf("******1.添  加*******\n");
	printf("******2.删  除*******\n");
	printf("******3.查  找*******\n");
	printf("******4.更  改******\n");
	printf("******5.展  示*******\n");
	printf("******0.退  出*******\n");
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
			printf("输入错误\n");
		}
	} while (count);
	DestroyContact(&con);
	return 0;
}