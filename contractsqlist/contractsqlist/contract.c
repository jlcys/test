#include"contract.h"
PeoInfo* CreateNewContact() 
{
	PeoInfo* newcode = (PeoInfo*)malloc(sizeof(PeoInfo));
	if (newcode == NULL) {
		// �����ڴ����ʧ�ܵ����  
		exit(-1);
	}
	return newcode;
}
void AddContact(PeoInfo**con)
{
	PeoInfo* newcode = CreateNewContact();
	PeoInfo* cur = *con;
	printf("����������\n");
	scanf("%s", newcode->name);
	printf("����������\n");
	scanf("%d", &newcode->age);
	printf("�������ַ\n");
	scanf("%s", newcode->addr);
	printf("������绰\n");
	scanf("%s", newcode->tel);
	printf("�������Ա�\n");
	scanf("%s", newcode->sex);
	newcode->next = *con; // �½ڵ��nextָ��ǰͷ�ڵ�  
	*con = newcode;
	
}
void ShowContact(PeoInfo* con)
{
	PeoInfo* petail = con;

	
	while (petail)
	{
		
		printf("\n");
		printf("����: %s\n", petail->name);
		printf("����: %d\n", petail->age);
		printf("��ַ: %s\n", petail->addr);
		printf("�绰: %s\n", petail->tel);
		printf("�Ա�: %s\n", petail->sex);
		printf("\n"); // ��ӡһ�������Էָ���ͬ����ϵ����Ϣ
		petail = petail->next;
	}
}
PeoInfo* FindContact(PeoInfo* con)
{
	printf("��������Ҫ����/ɾ��/�޸ĵ�����");
	char namex[100];
	scanf("%s", namex);
	PeoInfo* pcur = con;
	int count = 0;
	if (con == NULL) {
		printf("��ϵ���б�Ϊ��\n");
		return NULL;
	}
	PeoInfo* prev = NULL;
	while (pcur)
	{
		if (strcmp(pcur->name, namex) == 0)
		{
			count = 1;
			printf("\n");

			printf("�ҵ���\n");
			printf("����: %s\n", pcur->name);
			printf("����: %d\n", pcur->age);
			printf("��ַ: %s\n", pcur->addr);
			printf("�绰: %s\n", pcur->tel);
			printf("�Ա�: %s\n", pcur->sex);
			return pcur;
		}
		pcur = pcur->next;
	}
	if (count == 0)
	{
printf("û�ҵ�\n");
return NULL;
	}
		
	
}
void DelContact(PeoInfo** con)//ɾ��
{
	
	PeoInfo* det =FindContact(*con);
	if (det == NULL) 
	{
		printf("ɾ��ʧ��\n");
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
	free(det); // �ͷű�ɾ���ڵ���ڴ�  
	printf("ɾ���ɹ�\n");
	printf("\n");
	
}
void ModifyContact(PeoInfo** con)
{
	
	PeoInfo* reverse = FindContact(*con);
	printf("\n");

	printf("����������\n");
	scanf("%s", reverse->name);
	printf("����������\n");
	scanf("%d", &reverse->age);
	printf("�������ַ\n");
	scanf("%s", reverse->addr);
	printf("������绰\n");
	scanf("%s", reverse->tel);
	printf("�������Ա�\n");
	scanf("%s", reverse->sex);
	printf("�޸ĳɹ�\n");
}
void DestroyContact(PeoInfo** con)
{
	*con = NULL;
	
	free(*con);
	
	
}