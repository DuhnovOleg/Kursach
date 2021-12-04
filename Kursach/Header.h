#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <list>
#include <string.h>
#include <windows.h>
using namespace std;
FILE* DB;
int** A1, n;
char ADRESS[32];
void menu1();
void menu();
void print_file();
int** create_arr(int x);
int** zapolny_arr(int n);
void print();
void read_file();