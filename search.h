/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*           	   File Name: search.h                  *
*********************************************************
*/


/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the header file to be used *
*			   in search.c file                			*
*********************************************************
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Defining the variable to be used in the  *
*			   search.c file               				*
*********************************************************
*/
#define MAX 12001
#define LINES 101


/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the function prototype to  * 
*			   be used in the search.c file             *
*********************************************************
*/
int search();
void getNum(int,int,char*,char*,char*,char*,char*,char*);
void get3Attribute(int age2,char*,char*,char*,char*,char*,char*);
void openFileCompareDisplay(char*,char*,char*,char*);

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the struct and union v     *
*			   variable to be used in the search.c file *
*********************************************************
*/
typedef union tempoaryData 
{
	int num;
   	int age;
   	char ageInDays[20];
   	char ageInYears[20];
}Data;
typedef struct userInfo2
{
	char userAnswer1[30];
	char userAnswer2[30];
	char userAnswer3[30];	
	char method[30];
}user2;

