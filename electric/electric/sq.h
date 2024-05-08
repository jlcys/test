#pragma once  
#define _CRT_SECURE_NO_WARNINGS 1;
#include "ele.h"  
#include <stdio.h>  
#include <stdlib.h>  
typedef struct sqlist
{
    datatype* arr;
    int size;
    int capacity;
} sys;

void Initsq(sys* ps);
void espushback(sys* ps, datatype x);
void SLErase(sys* ps, int pos);
int FindByName(sys* ps, char name[]);
void DesTroy(datatype* con);