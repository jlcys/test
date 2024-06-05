#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

#include<time.h>


void adjustdown(int* a, int size, int parent);
void adjustup(int* a, int child);
void swap(int* a, int* b);