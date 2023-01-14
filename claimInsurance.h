/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*              File Name: claimInsurance.h              *
*********************************************************
*/


/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Including all the header file to be used *
*	           in the claimInsurance.c file             *
*********************************************************
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<assert.h>
#include<time.h>

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Defining the variable to be used in the  *
* 			   claimInsurance.c file                    *
*********************************************************
*/
#define MAX 12001
#define LINES 101

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the function prototype to  *
*			   be used in the claimInsurance.c file     *
*********************************************************
*/
int claimInsurance();
void getNameOrId(char*,char*);
int compareAndGiveLocation(char*,char*);
void checkUserAge(int);
void storeUserNameAndId(char*,char*,int);
float getAmountBalance(int);
float getAmountClaim(int);
void getPlanType2(char*,int);
void display(char*);
int getRoomCharges();
int getIcuCharges();
float getHospitalSuppliesAndServices();
float getSurgicalAndOtherFees();
float totalRequestClaim(char*,float,int,int,float,float);
float changeAmountBalance(float,float);
float changeAmountClaim(float,float);
void displayOverallClaim(char*,char*,float,float);
void recordClaim(char*,char*,float,float);
void updateInsurancePlansFile(int,float,float);

/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
* Description: Declaring all the struct value to be     *
*			   applied in the claimInsurance.c file     *
*********************************************************
*/
typedef struct userInfo
{
	char userAnswer[30], method[10],TypeOfPlan[8],id[8],name[25], ageType[12], age[3];
	int location, getRoomCharge,getIcuCharge;
	float getHospitalSuppliesAndService, getSurgicalAndOtherFee,amountBalance, amountClaim,total;
}user1;
