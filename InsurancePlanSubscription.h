/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*         File Name: InsurancePlanSubscription.h        *
*********************************************************
*/

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the header file to be used *
*			   in the InsurancePlanSubscription.c file  *
*********************************************************
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h> 

/*
***************************************************************
*                Developer Name: Loke Weng Khay               *
* Description: Declaring all the struct variable to be        *
*              used in the InsurancePlanSubscription.c file   *
***************************************************************
*/
typedef struct subscriber
{
	int age;
	char planType[10];
	char CL[4];
	float amount;
	int id;
	struct 
	{
		char name[20], contactNumber[15], healthHistory[100];
		struct 
		{
			char houseNumber[5], street[30], city [30], state [20], zipCode [6];
		}address;
	}userInformation;	
}sub;

/*
***********************************************************************
*            Developer Name: Loke Weng Khay             			  *
* Description: Declaring all the function prototype to  			  *
*	 		   to be used in the InsurancePlanSubscription.c file     *
***********************************************************************
*/
int insurancePlanSubscription();
int getAgeInDays();
int getAgeInYears(int);
void displayInsuranceOptions(int,bool);
void getTypeofClaimLimit(char*);
float getPlanType(int,char*,bool,char*);
void getUserInformation(char*,char*,char*,char*,char*,char*,char*,char*);
void displayOverall(sub S,bool);
void saveToAFile(sub S,bool);
int getUserID();
