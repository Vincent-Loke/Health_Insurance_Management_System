/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*           File Name: accountInformation.c             *
*********************************************************
*/

/* Include the header file to allow this file to access the variable define in the header file*/
#include"accountInformation.h"

/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To execute the other functions in order when this function is being called *
****************************************************************************************************
*/
int accountInformation()
{
	int num;
	num=displayOptions();
	if(num==1)
	{
		displayTotalLCLAmountClaim();
	}
	else
	{
		totalOfExhaustedACL();
	}
	return 0;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To display the option to the user and get the input from the user and also *
*						check whether the correct input is inserted or not 						   *
****************************************************************************************************
*/
int displayOptions()
{
	int selection2;
	int k;
	bool correctSelection=false;
	printf("\nEnter 1 for Total amount claimed by Lifetime Claim Limit subscribers\nEnter 2 for total number of Annual Claim Limit subscribers who have exhausted all their eligible amount.\nYour selection: ");
	for(k=0;correctSelection!=true;k++)
	{
		if(scanf("%d", &selection2) != 1)
   		{
    		selection2=0;
			getchar();	
    	}
		if(selection2==1)
		{
			correctSelection=true;
		}
		else if(selection2==2)
		{
			correctSelection=true;
		}
		else
		{
			printf("Please enter a approriate response\n");
		}
	}
	return selection2;	
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get and display all the amount claim by the Lifetime Claim Limit        *
*						Subsciber						  										   *
****************************************************************************************************
*/
void displayTotalLCLAmountClaim()
{
	FILE *fp1;
	char f[MAX][LINES];
	int h,count=0,j,l=0;
	bool CL=false;
	char amountClaim[11];
	float totalClaim;
	float amountClaim2;
	
	fp1=fopen("Insurance_Plans.txt","r");
	
	while(h<MAX && fgets(f[h],sizeof(f),fp1))
	{
		h++;
	}
	while(CL!=true)
	{
		if(strcmp(f[count],"Type of Claim Limit: LCL\n")==0)
		{
			l=0;
			for(j=17;j<strlen(f[count+3]);j++)
			{
				amountClaim[l]=f[count+3][j];
				l++;
			}
			amountClaim2=atof(amountClaim);
			totalClaim=totalClaim+amountClaim2;
		}
		else if(strlen(f[count])==0)
		{
			CL=true;
		}
		count++;
		
	}
	printf("\nTotal Claim by Lifetime Claim Limit subscriber is RM %.2f",totalClaim);
	fclose(fp1);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get and display the number of Annual Claim Limit Subsciber who have     *
*						exhausted the all their balance amount						  			   *
****************************************************************************************************
*/
void totalOfExhaustedACL()
{
	FILE *fp2;
	char g[MAX][LINES];
	int j,count=0,EC=0;
	bool EC1=false;
	fp2=fopen("Insurance_Plans.txt","r");
	while(j<MAX && fgets(g[j],sizeof(g),fp2))
	{
		j++;
	}
	while(EC1!=true)
	{
		if(strcmp(g[count],"Type of Claim Limit: ACL\n")==0)
		{
			if(strcmp(g[count+2],"Amount Balance: RM 0.00\n")==0)
			{
				EC++;
			}
		}
		else if(strlen(g[count])==0)
		{
			EC1=true;
		}
		count++;
	}
	printf("\nTotal Annual Claim Limit subscriber that have exhausted their amount is %d",EC);	
	fclose(fp2);
}
