#pragma once
#define NAMEMAX 100
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//用户数据
typedef struct PersonInfo
{
	char usname[NAMEMAX];
	double uprice;
	double pwercon;
	double price;
    struct PersonInfo* next;
}PeoInfo;


//添加数据
void AddContact(PeoInfo** con);
//删除数据
void DelContact(PeoInfo** con);
//展示数据
void ShowContact(PeoInfo* con);
//查找数据
PeoInfo* FindContact(PeoInfo* con);
//修改数据
void ModifyContact(PeoInfo** con);
//销毁数据
void DestroyContact(PeoInfo** con);