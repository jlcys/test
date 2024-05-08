#pragma once
#define NAMEMAX 100
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//�û�����
typedef struct PersonInfo
{
	char usname[NAMEMAX];
	double uprice;
	double pwercon;
	double price;
    struct PersonInfo* next;
}PeoInfo;


//�������
void AddContact(PeoInfo** con);
//ɾ������
void DelContact(PeoInfo** con);
//չʾ����
void ShowContact(PeoInfo* con);
//��������
PeoInfo* FindContact(PeoInfo* con);
//�޸�����
void ModifyContact(PeoInfo** con);
//��������
void DestroyContact(PeoInfo** con);