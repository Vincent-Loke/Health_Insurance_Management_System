/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*         File Name: InsurancePlanSubscription.c        *
*********************************************************
*/

/* Include the header file to allow this file to access the variable define in the header file*/
#include"InsurancePlanSubscription.h"

/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To execute the other functions in order when this function is being called *
****************************************************************************************************
*/
int insurancePlanSubscription()
{
	int age1;
	sub S;
	bool firstAnswer=false;
	printf("\nIf subscriber is below 1 years old, please enter '-1'\nPlease enter age in Years: \n"); 
	while(firstAnswer!=true)
	{
		if(scanf("%d", &age1) != 1)
   		{
    		age1=0;
			getchar();	
    	}
		if(age1==-1)
		{
			firstAnswer=true;
			S.age=getAgeInDays();	
			displayInsuranceOptions(S.age,true);
			getTypeofClaimLimit(S.CL);
			S.amount=getPlanType(S.age,S.CL,true,S.planType);
			getUserInformation(S.userInformation.name,S.userInformation.address.houseNumber,S.userInformation.address.street,S.userInformation.address.city,S.userInformation.address.state,S.userInformation.address.zipCode,S.userInformation.contactNumber,S.userInformation.healthHistory);
			S.id=getUserID();
			displayOverall(S,true);
			saveToAFile(S,true);
		}
		else if(age1>0)
		{
			firstAnswer=true;
			S.age=getAgeInYears(age1);	
			displayInsuranceOptions(S.age,false);
			getTypeofClaimLimit(S.CL);
			S.amount=getPlanType(S.age,S.CL,false,S.planType);
			getUserInformation(S.userInformation.name,S.userInformation.address.houseNumber,S.userInformation.address.street,S.userInformation.address.city,S.userInformation.address.state,S.userInformation.address.zipCode,S.userInformation.contactNumber,S.userInformation.healthHistory);
			S.id=getUserID();
			displayOverall(S,false);
			saveToAFile(S,false);
		}
		else
		{
			printf("Please enter an appropriate age\n");
		}
	}
	return 0;
}
/*
****************************************************************************************************************
*                                  		Developer Name: Loke Weng Khay             				               *
*Function Description: To get user's age in days and check whether the user have inserted a correct age in days*
****************************************************************************************************************
*/
int getAgeInDays()
{
	int ageInDays,j;
	bool ageInDays2=false;
	printf("\nPlease enter, how old is the subscriber in days: \n");
	for(j=0;ageInDays2!=true;j++)
	{
		if(scanf("%d", &ageInDays) != 1)
   		{
    		ageInDays=0;
			getchar();	
    	}
		if(ageInDays>14 && ageInDays<365)
		{
			ageInDays2=true;
			return ageInDays;
		}
		else if(ageInDays>0 && ageInDays<15)
		{	
			printf("Sorry, subscriber is not applicable for any insurance as the minimum age in days must be above 15 days old\n");
			exit(0);
		}
		else
		{
			printf("Please enter an appropriate age:\n");
		}
	}
}
/*
******************************************************************************************************************
*                                  		Developer Name: Loke Weng Khay             				                 *
*Function Description: To get user's age in years and check whether the user have inserted a correct age in years*
******************************************************************************************************************
*/
int getAgeInYears(int age2)
{
	int i,ageInYears=age2;
	bool ageInYears2=false;
	for(i=0;ageInYears2!=true;i++)
	{
		if(ageInYears>0 && ageInYears<55)
		{
			ageInYears2=true;
			return ageInYears;
		}
		else if(ageInYears>54)
		{	
			printf("Sorry, subscriber is not applicable for any insurance as the maximum age is cap at 54 years old\n");
			exit(0);
		}
		else
		{
			printf("Please enter an appropriate age:\n");
			scanf("%d",&ageInYears);
		}
	}
}
/*
****************************************************************************************
*                      	Developer Name: Loke Weng Khay             				       *
* Function Description: To display Insurance Plans and Benefits based on the age given *
****************************************************************************************
*/
void displayInsuranceOptions(int age3 ,bool ageInDays)
{
	if((age3>0 && age3<21) && (ageInDays==false) || (age3>14 && age3<365) && (ageInDays==true))
	{
		printf("The table below is the appropriate insurance for your age:\n\n");
		printf("		Insurance Plans\n");
		printf("----------------------------------------------------\n");
		printf("|                    | Plan120 | Plan150 | Plan200 |\n");
		printf("|                    |  (RM)   |   (RM)  |  (RM)   |\n");
		printf("----------------------------------------------------\n");
		printf("|Monthly Premium     |   120   |   150   |   200   |\n");
		printf("----------------------------------------------------\n");
		printf("|Annual Claim Limit  | 120,000 | 150,000 | 200,000 |\n");
		printf("----------------------------------------------------\n");
		printf("|Lifetime Claim Limit| 600,000 | 750,000 |1,000,000|\n");
		printf("----------------------------------------------------\n\n");
		
		printf("		   Benefits\n");
		printf("---------------------------------------------------\n");
		printf("|Types of Claim     | Plan120 | Plan150 | Plan200 |\n");
		printf("|                   |  (RM)   |   (RM)  |  (RM)   |\n");
		printf("---------------------------------------------------\n");
		printf("|Room Charges       | 120/day | 150/day | 200/day |\n");
		printf("---------------------------------------------------\n");
		printf("|Intensive Care Unit| 250/day | 400/day | 700/day |\n");
		printf("|(ICU) Charges      |         |         |         |\n");
		printf("---------------------------------------------------\n");
		printf("|Hospital Supplies  |                             |\n");
		printf("|and Services       |       As charged. Subject   |\n");
		printf("---------------------       to approval by        |\n");
		printf("|Surgical Fees      |       ZeeMediLife.          |\n");
		printf("|Other Fees         |                             |\n");
		printf("---------------------------------------------------\n");
		
	}
	else if((age3>20 && age3<41) && (ageInDays==false))
	{
		printf("The table below is the appropriate insurance for your age:\n\n");
		printf("	     Insurance Plans\n");
		printf("------------------------------------------\n");
		printf("|                    | Plan150 | Plan200 |\n");
		printf("|                    |   (RM)  |  (RM)   |\n");
		printf("------------------------------------------\n");
		printf("|Monthly Premium     |   150   |   200   |\n");
		printf("------------------------------------------\n");
		printf("|Annual Claim Limit  | 150,000 | 200,000 |\n");
		printf("------------------------------------------\n");
		printf("|Lifetime Claim Limit| 750,000 |1,000,000|\n");
		printf("------------------------------------------\n\n");
		
		printf("	        Benefits\n");
		printf("-----------------------------------------\n");
		printf("|Types of Claim     | Plan150 | Plan200 |\n");
		printf("|                   |   (RM)  |  (RM)   |\n");
		printf("-----------------------------------------\n");
		printf("|Room Charges       | 150/day | 200/day |\n");
		printf("-----------------------------------------\n");
		printf("|Intensive Care Unit| 400/day | 700/day |\n");
		printf("|(ICU) Charges      |         |         |\n");
		printf("-----------------------------------------\n");
		printf("|Hospital Supplies  |                   |\n");
		printf("|and Services       |As charged. Subject|\n");
		printf("---------------------   to approval by  |\n");
		printf("|Surgical Fees      |    ZeeMediLife.   |\n");
		printf("|Other Fees         |                   |\n");
		printf("-----------------------------------------\n");
		
	}
	else
	{
		printf("The table below is the appropriate insurance for your age:\n\n");
		printf("	Insurance Plans\n");
		printf("--------------------------------\n");
		printf("|                    | Plan200 |\n");
		printf("|                    |  (RM)   |\n");
		printf("--------------------------------\n");
		printf("|Monthly Premium     |   200   |\n");
		printf("--------------------------------\n");
		printf("|Annual Claim Limit  | 200,000 |\n");
		printf("--------------------------------\n");
		printf("|Lifetime Claim Limit|1,000,000|\n");
		printf("--------------------------------\n\n");
		
		printf("	     Benefits\n");
		printf("-----------------------------------\n");
		printf("|Types of Claim     |   Plan200   |\n");
		printf("|                   |    (RM)     |\n");
		printf("-----------------------------------\n");
		printf("|Room Charges       |   200/day   |\n");
		printf("-----------------------------------\n");
		printf("|Intensive Care Unit|   700/day   |\n");
		printf("|(ICU) Charges      |             |\n");
		printf("-----------------------------------\n");
		printf("|Hospital Supplies  |             |\n");
		printf("|and Services       | As charged. |\n");
		printf("--------------------- Subject to  |\n");
		printf("|Surgical Fees      | approval by |\n");
		printf("|Other Fees         | ZeeMediLife |\n");
		printf("-----------------------------------\n");
	}
}
/*
******************************************************************************************************************************
*                      						Developer Name: Loke Weng Khay                       				     		 *
* Function Description: To get user's type of claim limit and check whether the claim limit type is entered correctly or not *
******************************************************************************************************************************
*/
void getTypeofClaimLimit(char *CL2)
{
	char claimLimit[3];
	int k,l;
	bool typeOfClaimLimit=false;
	printf("\n\nACL for Annual Claim Limit\nLCL for Lifetime Claim Limit\nPlease enter the claim limit that you wish to subscribe in short form: \n");
	
	for(k=0;typeOfClaimLimit!=true;k++)
	{
		scanf("%s",claimLimit);
		getchar();
		if(strcmp(claimLimit,"ACL")==0) // Implies that content of claimLimit is equals to "ACL"
		{
	  		for(l=0;l<3;l++)
			{
				*(CL2+l)=claimLimit[l];
			}
			printf("\nYou have selected: Annual Claim Limit\n");
			typeOfClaimLimit=true;
		}
		else if(strcmp(claimLimit,"LCL")==0) // Implies that content of claimLimit is equals to "LCL"
		{
	  		for(l=0;l<3;l++)
			{
				*(CL2+l)=claimLimit[l];
			}
			printf("\nYou have selected: Lifetime Claim Limit\n");
			typeOfClaimLimit=true; 
		}
		else
		{
			printf("Please enter an appropriate type of claim limit.\nEither ACL or LCL\nYour Selection: ");
		}
	}
}
/*
********************************************************************************************************
*                      				Developer Name: Loke Weng Khay                       	   		   *
* Function Description: to get user's type of plan and check whether user enter the correct plan type  *
********************************************************************************************************
*/
float getPlanType(int age3,char *CL3, bool ageInDays2, char *PT)
{
	bool userPlanType=false;
	char planType[9];
	char plan120[8]="Plan120";
	char plan150[8]="Plan150";
	char plan200[8]="Plan200";
	int m;
	printf("\nPlease enter a plan to go with ");
	if(strcmp(CL3,"ACL")==0)
	{
		printf("Annual Claim Limit\n");
	}
	else
	{
		printf("Lifetime Claim Limit\n");
	}
	for(m=0;userPlanType!=true;m++)
	{
		scanf("%[^\n]%*c", planType);
		if(((age3>0 && age3<21) && (ageInDays2==false)) || ((age3>14 && age3<365) && (ageInDays2==true)))
		{
			if((strcmp(planType,"Plan 120")==0) || (strcmp(planType,"plan 120")==0) || (strcmp(planType,"Plan120")==0) || (strcmp(planType,"plan120")==0))
			{
				userPlanType=true;
				strcpy(PT,plan120);
				printf("\nYou have selected: Plan 120");
				if(strcmp(CL3,"ACL")==0)
				{
					return 120000;
				}
				else
				{
					return 600000;
				}
			}
			else if((strcmp(planType,"Plan 150")==0) || (strcmp(planType,"plan 150")==0) || (strcmp(planType,"Plan150")==0) || (strcmp(planType,"plan150")==0))
			{
				userPlanType=true;
				strcpy(PT,plan150);
				printf("\nYou have selected: Plan 150");
				if(strcmp(CL3,"ACL")==0)
				{
					return 150000;
				}
				else
				{
					return 750000;
				}
			}
			else if((strcmp(planType,"Plan 200")==0) || (strcmp(planType,"plan 200")==0) || (strcmp(planType,"Plan200")==0) || (strcmp(planType,"plan200")==0))
			{
				userPlanType=true;
				strcpy(PT,plan200);
				printf("\nYou have selected: Plan 200");
				if(strcmp(CL3,"ACL")==0)
				{
					return 200000;
				}
				else
				{
					return 1000000;
				}
			}
			else
			{
				printf("Please enter an appropriate plan type\n");
			}
		}
		else if((age3>20 && age3<41) && (ageInDays2==false))
		{
			if((strcmp(planType,"Plan 150")==0) || (strcmp(planType,"plan 150")==0) || (strcmp(planType,"Plan150")==0) || (strcmp(planType,"plan150")==0))
			{
				userPlanType=true;
				strcpy(PT,plan150);
				printf("\nYou have selected: Plan 150");
				if(strcmp(CL3,"ACL")==0)
				{
					return 150000;
				}
				else
				{
					return 750000;
				}
			}
			else if((strcmp(planType,"Plan 200")==0) || (strcmp(planType,"plan 200")==0) || (strcmp(planType,"Plan200")==0) || (strcmp(planType,"plan200")==0))
			{
				userPlanType=true;
				strcpy(PT,plan200);
				printf("\nYou have selected: Plan 200");
				if(strcmp(CL3,"ACL")==0)
				{
					return 200000;
				}
				else
				{
					return 1000000;
				}
			}
			else
			{
				printf("Please enter an appropriate plan type\n");
			}
		}
		else
		{
			if((strcmp(planType,"Plan 200")==0) || (strcmp(planType,"plan 200")==0) || (strcmp(planType,"Plan200")==0) || (strcmp(planType,"plan200")==0))
			{
				userPlanType=true;
				strcpy(PT,plan200);
				printf("\nYou have selected: Plan 200");
				if(strcmp(CL3,"ACL")==0)
				{
					return 200000;
				}
				else
				{
					return 1000000;
				}
			}
			else
			{
				printf("Please enter an appropriate plan type\n");
			}
		}
	}
}
/*
********************************************************************************************************
*                      				Developer Name: Loke Weng Khay                       	   		   *
* Function Description:  to get user information such as name, address, contact number and health      *
*					     history from the user to be recorded in the text file                         *
********************************************************************************************************
*/
void getUserInformation(char *name2,char *houseNumber2,char *street2, char *city2, char *state2, char *zipCode2,char *CN, char *HH)
{
	int s;
	char healthHistory[100];
	char none[5]={"None"};
	bool condition=false;
	char haveHealthIssue[3];
	printf("\n\nUser Deatils\nEnter Full Name: \n");
	gets(name2);
	printf("Enter House Number: \nNo. ");
	gets(houseNumber2);
	printf("Enter Street Address: \n");
	gets(street2);
	printf("Enter City: \n");
	gets(city2);
	printf("Enter State: \n");
	gets(state2);
	printf("Enter Zip Code: \n");
	gets(zipCode2);
	printf("Enter Contact Number: \n");
	gets(CN);
	printf("Do you have health issue: ('Yes','No')\n");
	for(s=0;condition!=true;s++)
	{
		scanf ("%s",haveHealthIssue);
		if((strcmp(haveHealthIssue,"Yes")==0) || (strcmp(haveHealthIssue,"yes")==0))
		{
			getchar();
			printf("Please state all your health issue that you are facing in one line and please use comma after naming each issue: \n");
			scanf("%[^\n]%*c",HH);
			printf("Thank you for entering all the information needed\n");
			condition=true;
		}
		else if((strcmp(haveHealthIssue,"No")==0) || (strcmp(haveHealthIssue,"no")==0))
		{
			strcpy(HH,none);
			printf("Thank you for entering all the information needed\n");
			condition=true;
		}
		else
		{
			printf("Wrong answer entered\nEither ('Yes','No')\n");
		}
	}
}
/*
********************************************************************************************************
*                      				Developer Name: Loke Weng Khay                       	   		   *
*    Function Description: To display all the user information, subscription and etc to the user       *
********************************************************************************************************
*/
void displayOverall(sub S,bool ageInDays3)
{
	time_t timer; 
    struct tm* tm_info; 
    char day[3]; 
    char month[3]; 
	char year[5]; 
		
	time(&timer); 
    tm_info = localtime(&timer); 
 
    strftime(day, 3, "%d", tm_info); 
    strftime(month, 3, "%m", tm_info); 
    strftime(year, 5, "%Y", tm_info); 
    
	printf("\nUser Information:\n");
	printf("User ID: %05d",S.id);
	printf("\nName: %s", S.userInformation.name);
	printf("\nAge: %d",S.age);
	if(ageInDays3==true)
	{
		printf(" Days Old");
	}
	else
	{
		printf(" Years Old");
	}
	printf("\nClaim Limit Type: %s",S.CL);
	printf("\nType of plan: %s\n",S.planType);
	printf("Amount Subscribe: RM %.2f",S.amount);
	printf("\nDate Subcription: %s/%s/%s",day,month,year);
	printf("\nAddress: No. %s, %s, %s, %s, %s",S.userInformation.address.houseNumber,S.userInformation.address.street,S.userInformation.address.city,S.userInformation.address.state,S.userInformation.address.zipCode);
	printf("\nContact: %s",S.userInformation.contactNumber);
	printf("\nHealth Issues: %s\n",S.userInformation.healthHistory);
}
/*
**********************************************************************************************
*                      		Developer Name: Loke Weng Khay                       	   		 *
*    Function Description: To store user information and subscription into a text file       *
**********************************************************************************************
*/
void saveToAFile(sub S,bool ageInDays4)
{
	time_t timer; 
    struct tm* tm_info; 
    char day[3]; 
    char month[3]; 
	char year[5]; 
		
	time(&timer); 
    tm_info = localtime(&timer); 
 
    strftime(day, 3, "%d", tm_info); 
    strftime(month, 3, "%m", tm_info); 
    strftime(year, 5, "%Y", tm_info); 
    
	FILE *fp1, *fp2, *fp3;
	if((fp1 = fopen ( "Insurance_Plans.txt", "r" ) ) == NULL  ) 
	{
		fclose(fp1);
		fp2 = fopen("Insurance_Plans.txt","w");
    	fprintf(fp2, "ID: %05d\nName: %s\nAge: %d",S.id,S.userInformation.name,S.age);
    	if(ageInDays4==true)
    	{
    		fprintf(fp2," Days Old\n");
		}
		else
		{
			fprintf(fp2," Years Old\n");
		}
		fprintf(fp2,"Type of Claim Limit: %s\nType of Plan: %s\nAmount Balance: RM %.2f",S.CL,S.planType,S.amount);
		fprintf(fp2,"\nAmount Claim: RM 0.00\nDate Subcription: %s/%s/%s\nAddress: No. %s, %s, %s, %s, %s\nContact Number: %s\nHealth History: %s",day,month,year,S.userInformation.address.houseNumber,S.userInformation.address.street,S.userInformation.address.city,S.userInformation.address.state,S.userInformation.address.zipCode,S.userInformation.contactNumber,S.userInformation.healthHistory);
		fclose(fp2);
	} 
	else 
	{
		fclose(fp1);
		fp3 = fopen("Insurance_Plans.txt","a");
    	fprintf(fp3, "\n\nID: %05d\nName: %s\nAge: %d",S.id,S.userInformation.name,S.age);
    	if(ageInDays4==true)
    	{
    		fprintf(fp3," Days Old\n");
		}
		else
		{
			fprintf(fp3," Years Old\n");
		}
		fprintf(fp3,"Type of Claim Limit: %s\nType of Plan: %s\nAmount Balance: RM %.2f",S.CL,S.planType,S.amount);
		fprintf(fp3,"\nAmount Claim: RM 0.00\nDate Subcription: %s/%s/%s\nAddress: No. %s, %s, %s, %s, %s\nContact Number: %s\nHealth History: %s",day,month,year,S.userInformation.address.houseNumber,S.userInformation.address.street,S.userInformation.address.city,S.userInformation.address.state,S.userInformation.address.zipCode,S.userInformation.contactNumber,S.userInformation.healthHistory);
		fclose(fp3);
	}
}
/*
**************************************************************************
*                   Developer Name: Loke Weng Khay                       *
*    Function Description: To get a unique id for each of the user       *
**************************************************************************
*/
int getUserID()
{
	FILE *fp4,*fp5,*fp6,*fp7;
	int j;
	int i=0;
	if ( (fp4 = fopen ( "Unique_ID.txt", "r" ) ) == NULL )
	{
		fclose ( fp4 );
		fp5=fopen("Unique_ID.txt","w");
		i++;
		fprintf(fp5,"%d",i);
		fclose(fp5);
		return i;
	}
	else 
	{
		fclose ( fp4 );
		fp6=fopen("Unique_ID.txt","r");
		fscanf(fp6,"%d",&j);
		fclose(fp6);
		fp7=fopen("Unique_ID.txt","w");
		j++;
		fprintf(fp7,"%d",j);
		fclose(fp7);
		return j;
	}
}
