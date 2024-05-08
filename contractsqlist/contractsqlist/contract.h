#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//�û�����
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
    struct PersonInfo* next;
}PeoInfo;


//���ͨѶ¼����
void AddContact(PeoInfo** con);
//ɾ��ͨѶ¼����
void DelContact(PeoInfo** con);
//չʾͨѶ¼����
void ShowContact(PeoInfo* con);
//����ͨѶ¼����
PeoInfo* FindContact(PeoInfo* con);
//�޸�ͨѶ¼����
void ModifyContact(PeoInfo** con);
//����ͨѶ¼����
void DestroyContact(PeoInfo** con);