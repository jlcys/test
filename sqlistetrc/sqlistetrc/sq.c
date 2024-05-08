#include"sq.h"
PeoInfo* CreateNewContact()
{
	PeoInfo* newcode = (PeoInfo*)malloc(sizeof(PeoInfo));
	if (newcode == NULL) {
		// 处理内存分配失败的情况  
		exit(-1);
	}
	return newcode;
}
void AddContact(PeoInfo** con)
{
	PeoInfo* newcode = CreateNewContact();
	PeoInfo* cur = *con;
	printf("用户名\n");
	scanf("%s", newcode->usname);
	printf("请输入单价\n");
	scanf("%lf", &(newcode->uprice));
	printf("请输入用电量\n");
	scanf("%lf", &(newcode->pwercon));
	newcode->price = newcode->uprice * newcode->pwercon;
	newcode->next = *con; // 新节点的next指向当前头节点  
	*con = newcode;

}
void ShowContact(PeoInfo* con)
{
	PeoInfo* petail = con;


	while (petail)
	{

		printf("\n");
		printf("用户名: %s\n", petail->usname);
		printf("单价: %.2lf\n", petail->uprice);
		printf("用电量: %.2lf\n", petail->pwercon);
		printf("总价: %.2lf\n", petail->price);
		
		printf("\n"); // 打印一个空行以分隔不同的信息
		petail = petail->next;
	}
}
PeoInfo* FindContact(PeoInfo* con)
{
	printf("请输入您要查找/删除/修改的用户名");
	char namex[100];
	scanf("%s", namex);
	PeoInfo* pcur = con;
	int count = 0;
	if (con == NULL) {
		printf("用户为空\n");
		return NULL;
	}
	PeoInfo* prev = NULL;
	while (pcur)
	{
		if (strcmp(pcur->usname, namex) == 0)
		{
			count = 1;
			printf("\n");

			printf("找到了\n");
			printf("\n");
			printf("用户名: %s\n", pcur->usname);
			printf("单价: %.2lf\n", pcur->uprice);
			printf("用电量: %.2lf\n", pcur->pwercon);
			printf("总价: %.2lf\n", pcur->price);
			return pcur;
		}
		pcur = pcur->next;
	}
	if (count == 0)
	{
		printf("没找到\n");
		return NULL;
	}


}
void DelContact(PeoInfo** con)//删除
{

	PeoInfo* det = FindContact(*con);
	if (det == NULL)
	{
		printf("删除失败\n");
		return;
	}
	PeoInfo* cur = *con;
	if (det == cur)
	{
		*con = det->next;
	}
	else
	{
		while (cur->next != det)
		{
			cur = cur->next;
		}
	}
	cur->next = det->next;
	free(det); // 释放被删除节点的内存  
	printf("删除成功\n");
	printf("\n");

}
void ModifyContact(PeoInfo** con)
{

	PeoInfo* reverse = FindContact(*con);
	printf("\n");

	printf("\n");
	printf("用户名: %s\n", reverse->usname);
	printf("单价: %.2lf\n", reverse->uprice);
	printf("用电量: %.2lf\n", reverse->pwercon);
	printf("总价: %.2lf\n", reverse->price);
	printf("修改成功\n");
}
void DestroyContact(PeoInfo** con)
{
	*con = NULL;

	free(*con);


}