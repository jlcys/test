#include"contract.h"
PeoInfo* CreateNewContact() 
{
	PeoInfo* newcode = (PeoInfo*)malloc(sizeof(PeoInfo));
	if (newcode == NULL) {
		// 处理内存分配失败的情况  
		exit(-1);
	}
	return newcode;
}
void AddContact(PeoInfo**con)
{
	PeoInfo* newcode = CreateNewContact();
	PeoInfo* cur = *con;
	printf("请输入名字\n");
	scanf("%s", newcode->name);
	printf("请输入年龄\n");
	scanf("%d", &newcode->age);
	printf("请输入地址\n");
	scanf("%s", newcode->addr);
	printf("请输入电话\n");
	scanf("%s", newcode->tel);
	printf("请输入性别\n");
	scanf("%s", newcode->sex);
	newcode->next = *con; // 新节点的next指向当前头节点  
	*con = newcode;
	
}
void ShowContact(PeoInfo* con)
{
	PeoInfo* petail = con;

	
	while (petail)
	{
		
		printf("\n");
		printf("名字: %s\n", petail->name);
		printf("年龄: %d\n", petail->age);
		printf("地址: %s\n", petail->addr);
		printf("电话: %s\n", petail->tel);
		printf("性别: %s\n", petail->sex);
		printf("\n"); // 打印一个空行以分隔不同的联系人信息
		petail = petail->next;
	}
}
PeoInfo* FindContact(PeoInfo* con)
{
	printf("请输入您要查找/删除/修改的名字");
	char namex[100];
	scanf("%s", namex);
	PeoInfo* pcur = con;
	int count = 0;
	if (con == NULL) {
		printf("联系人列表为空\n");
		return NULL;
	}
	PeoInfo* prev = NULL;
	while (pcur)
	{
		if (strcmp(pcur->name, namex) == 0)
		{
			count = 1;
			printf("\n");

			printf("找到了\n");
			printf("名字: %s\n", pcur->name);
			printf("年龄: %d\n", pcur->age);
			printf("地址: %s\n", pcur->addr);
			printf("电话: %s\n", pcur->tel);
			printf("性别: %s\n", pcur->sex);
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
	
	PeoInfo* det =FindContact(*con);
	if (det == NULL) 
	{
		printf("删除失败\n");
		return;
	}
	PeoInfo* cur = *con;
	if (det == cur)
	{
		*con= det->next;
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

	printf("请输入名字\n");
	scanf("%s", reverse->name);
	printf("请输入年龄\n");
	scanf("%d", &reverse->age);
	printf("请输入地址\n");
	scanf("%s", reverse->addr);
	printf("请输入电话\n");
	scanf("%s", reverse->tel);
	printf("请输入性别\n");
	scanf("%s", reverse->sex);
	printf("修改成功\n");
}
void DestroyContact(PeoInfo** con)
{
	*con = NULL;
	
	free(*con);
	
	
}