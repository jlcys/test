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
//用户数据
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
    struct PersonInfo* next;
}PeoInfo;


//添加通讯录数据
void AddContact(PeoInfo** con);
//删除通讯录数据
void DelContact(PeoInfo** con);
//展示通讯录数据
void ShowContact(PeoInfo* con);
//查找通讯录数据
PeoInfo* FindContact(PeoInfo* con);
//修改通讯录数据
void ModifyContact(PeoInfo** con);
//销毁通讯录数据
void DestroyContact(PeoInfo** con);