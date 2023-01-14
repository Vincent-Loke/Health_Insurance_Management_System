/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*           File Name: accountInformation.h             *
*********************************************************
*/


/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the header file to be used *
*			   in accountInformation.c file             *
*********************************************************
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Defining the variable to be used in the  *
*			   accountInformation.c file                *
*********************************************************
*/
#define MAX 12001
#define LINES 101

/*
***********************************************************
*            Developer Name: Loke Weng Khay               *
* Description: Declaring all the function prototype to    *
*			   to be used in the accountInformation.c file*
***********************************************************
*/
int accountInformation();
int displayOptions();
void displayTotalLCLAmountClaim();
void totalOfExhaustedACL();
