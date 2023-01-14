/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*              File Name: claimInsurance.c              *
*********************************************************
*/

/* Include the header file to allow this file to access the variable define in the header file*/
#include"claimInsurance.h"

/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To execute the other functions in order when this function is being called *
****************************************************************************************************
*/
int claimInsurance()
{
	user1 S1;
	getNameOrId(S1.userAnswer,S1.method);
	S1.location=compareAndGiveLocation(S1.userAnswer,S1.method);
	checkUserAge(S1.location);
	storeUserNameAndId(S1.id,S1.name,S1.location);
	S1.amountBalance=getAmountBalance(S1.location);
	S1.amountClaim=getAmountClaim(S1.location);
	getPlanType2(S1.TypeOfPlan,S1.location);
	display(S1.TypeOfPlan);
	S1.getRoomCharge=getRoomCharges();
	S1.getIcuCharge=getIcuCharges();
	S1.getHospitalSuppliesAndService=getHospitalSuppliesAndServices();
	S1.getSurgicalAndOtherFee=getSurgicalAndOtherFees();
	S1.total=totalRequestClaim(S1.TypeOfPlan,S1.amountBalance,S1.getRoomCharge,S1.getIcuCharge,S1.getHospitalSuppliesAndService,S1.getSurgicalAndOtherFee);
	S1.amountBalance=changeAmountBalance(S1.amountBalance,S1.total);
	S1.amountClaim=changeAmountClaim(S1.amountClaim,S1.total);
	displayOverallClaim(S1.id,S1.name,S1.total,S1.amountBalance);
	recordClaim(S1.id,S1.name,S1.total,S1.amountBalance);
	updateInsurancePlansFile(S1.location,S1.amountClaim,S1.amountBalance);
	
	return 0;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* 		 Function Description: To ask user to enter a name or id before proceeding to a claim	   *
****************************************************************************************************
*/
void getNameOrId(char *userAnswer1,char *method1)
{
	
	int k; 
	char c[]="usingName";
	char d[]="usingId";
	bool answer=false;
	int num;
	
  	char userName[25];
   	char userID[8];
    

	printf("Enter 1 to search using name\nEnter 2 to search using user ID\nYour Selection: ");
	
	for(k=0;answer!=true;k++)
	{
		if(scanf("%d", &num) != 1)
   		{
    		num=0;
			getchar();	
    	}
		if(num==1)
		{
			getchar();
			printf("\nEnter Full Name:\n");
			fgets(userName,sizeof(userName),stdin);
			strcpy(method1,c);
			answer=true;
			strcpy(userAnswer1,"Name: "); 
			strcat(userAnswer1,userName);
		}
		else if(num==2)
		{
			getchar();
			printf("Enter ID:\n");
			fgets(userID,sizeof(userID),stdin);
			answer=true;
			strcpy(method1,d);
			strcpy(userAnswer1,"ID: ");       
  			strcat(userAnswer1, userID);
		}
		else
		{
			printf("Wrong number entered\nEnter again\n");
		}
	}
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To compare user info and get the location of the user info in the text     *
*						file to prevent from printing the whole file itself 	   				   *
****************************************************************************************************
*/
int compareAndGiveLocation(char *userAnswer2,char *method2)
{
	FILE *fp;
    int i=0; 
    char x[MAX][LINES];
    
    bool nameFound=false;
	bool idFound=false;
	
	int count=0;
	
    fp = fopen("Insurance_Plans.txt","r");
    if(fp == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
		while(i<MAX && fgets(x[i],sizeof(x),fp))
		{
   			++i;
		}
		if(strcmp(method2,"usingName")==0)
		{
			while(nameFound!=true)
			{
				if(strcmp(userAnswer2,x[count])==0)
				{
					printf("Name Found\n\n");
					nameFound=true;
				
					return count-1;					
				}
				else if(strlen(x[count])==0)
				{
					printf("Name not found\n");
					nameFound=true;
					exit(0);
				}
				count++;
			}
		}
		else if(strcmp(method2,"usingId")==0)
		{
			while(idFound!=true)
			{
				if(strcmp(userAnswer2,x[count])==0)
				{
					printf("Id Found\n\n");
					idFound=true;
					return count;	
				}
				else if(strlen(x[count])==0)
				{
					printf("Id not found\n");
					idFound=true;
					exit(0);
				}
				count++;
			}
		}
		else
		{
			printf("Error occured");
		}
	}
	fclose(fp);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* 	Function Description: To check if the user age is still able to claim for an insurance 		   *
****************************************************************************************************
*/
void checkUserAge(int location0)
{
	time_t timer; 
    struct tm* tm_info;  
	char year[5]; 
		
	time(&timer); 
    tm_info = localtime(&timer); 
    strftime(year, 5, "%Y", tm_info); 
    
    char getAgeType1[15];
    char age1[3];
	char w[MAX][LINES];
	FILE *fptr;
	int count,h=0,j,n,k=0,g,d,f;
	int p=0,a=0;
	char subscribeDate[5];
	bool userFound=false;
	
	int difference,num1,num2,num3;
	
	fptr = fopen("Insurance_Plans.txt","r");
    if(fptr == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
		while(h<MAX && fgets(w[h],sizeof(w),fptr))
		{
   			++h;
		}
		n=strlen(w[location0+2]);
		if(strcmp(w[location0+3],"Type of Claim Limit: ACL\n")==0)
		{
			for(j=n-10;j<n+1;j++)
			{
				getAgeType1[a]=w[location0+2][j];
				a++;
			}
			if(strcmp(getAgeType1,"Years Old\n")==0)
			{
				g=strlen(w[location0+7]);
				for(j=5;j<n-10;j++)
				{
					age1[p]=w[location0+2][j];
					p++;
				}
				for(f=24;f<g+1;f++)
				{
					subscribeDate[d]=w[location0+7][f];
					d++;
				}
				num1=atoi(subscribeDate);
				num2=atoi(year);
				difference=num2-num1;
				num3=atoi(age1);
				if(num3+difference>60)
				{
					printf("Sorry, you can claim only until at age 60 years old for ACL");
					exit(0);
				}
			}				
		}
	}
	fclose(fptr);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* 	Function Description: To take the user name and id from the text file to the memory to be used *
****************************************************************************************************
*/
void storeUserNameAndId(char *id1,char *name1,int location1)
{
	FILE *fp2;
	int i=0; 
	int s;	
	int w;	
	int d;	
	int e;	
	int q=0;	
    char y[MAX][LINES];

	fp2 = fopen("Insurance_Plans.txt","r");
    if(fp2 == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
		while(i<MAX && fgets(y[i],sizeof(y),fp2))
		{
   			++i;
		}
		d=strlen(y[location1]);
		e=strlen(y[location1+1]);
		for(s=4;s<d;s++)
		{
			id1[q]=y[location1][s];
			q++;
		}
		q=0;
		for(w=6;w<e;w++)
		{
			name1[q]=y[location1+1][w];
			q++;
		}
	}
	fclose(fp2);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get the user amount balance from the text file and store it in the 	   *
*						memory for use 															   *
****************************************************************************************************
*/
float getAmountBalance(int location2)
{
	FILE *fp3;
	int m=0,l,n,a=0;
	char str1[1][35];
    char z[MAX][LINES];
    char amountBalance1[8];
	fp3 = fopen("Insurance_Plans.txt","r");
	
    if(fp3 == NULL) 
	{
        printf("Cannot open file.\n");
    }
	else
	{
		while(m<MAX && fgets(z[m],sizeof(z),fp3))
		{
   			++m;
		}
		n=strlen(z[location2+5]);
		for(l=19;l<n;l++)
    	{
   			amountBalance1[a]=z[location2+5][l];
   			a++;
		}
	}
	fclose(fp3);
	return (atof(amountBalance1));
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get the user amount claim from the text file and store it in the memory *
*						for use 															  	   *
****************************************************************************************************
*/
float getAmountClaim(int location3)
{
	FILE *fp4;
	int i=0,g,h,a;
    char z1[MAX][LINES];
    char amountClaim1[8];
	fp4 = fopen("Insurance_Plans.txt","r");
    if(fp4 == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
    	while(i<MAX && fgets(z1[i],sizeof(z1),fp4))
		{
   			++i;
		}
		h=strlen(z1[location3+6]);
		for(g=17;g<h;g++)
    	{
   			amountClaim1[a]=z1[location3+6][g];
   			a++;
		}
	}
	fclose(fp4);
	return (atof(amountClaim1));
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get the user Plan Type from the text file and store it in the memory    *
*						for use 															  	   *
****************************************************************************************************
*/
void getPlanType2(char *PT,int location4)
{
	FILE *fp5;
	int i=0,g,h,a=0;
    char z2[MAX][LINES];

	fp5 = fopen("Insurance_Plans.txt","r");
    if(fp5 == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
    	while(i<MAX && fgets(z2[i],sizeof(z2),fp5) )
		{
   			++i;
		}
		h=strlen(z2[location4+4]);
		for(g=14;g<h-1;g++)
    	{
   			*(PT+a)=z2[location4+4][g];
   			a++;
		}
	}
	fclose(fp5);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To display the suitable table to the user based on their plan subsciption  *
****************************************************************************************************
*/
void display(char *PT3)
{
	if(strcmp(PT3,"Plan120")==0)
	{
		printf("\n\nClaim Benefits for Plan 120\n");
		printf("-----------------------------------\n");
		printf("|Types of Claim     |   Plan120   |\n");
		printf("|                   |    (RM)     |\n");
		printf("-----------------------------------\n");
		printf("|Room Charges       |   120/day   |\n");
		printf("-----------------------------------\n");
		printf("|Intensive Care Unit|   250/day   |\n");
		printf("|(ICU) Charges      |             |\n");
		printf("-----------------------------------\n");
		printf("|Hospital Supplies  |             |\n");
		printf("|and Services       | As charged. |\n");
		printf("--------------------- Subject to  |\n");
		printf("|Surgical Fees      | approval by |\n");
		printf("|Other Fees         | ZeeMediLife |\n");
		printf("-----------------------------------\n");
	}
	else if(strcmp(PT3,"Plan150")==0)
	{
		printf("\n\nClaim Benefits for Plan 150\n");
		printf("-----------------------------------\n");
		printf("|Types of Claim     |   Plan150   |\n");
		printf("|                   |    (RM)     |\n");
		printf("-----------------------------------\n");
		printf("|Room Charges       |   150/day   |\n");
		printf("-----------------------------------\n");
		printf("|Intensive Care Unit|   400/day   |\n");
		printf("|(ICU) Charges      |             |\n");
		printf("-----------------------------------\n");
		printf("|Hospital Supplies  |             |\n");
		printf("|and Services       | As charged. |\n");
		printf("--------------------- Subject to  |\n");
		printf("|Surgical Fees      | approval by |\n");
		printf("|Other Fees         | ZeeMediLife |\n");
		printf("-----------------------------------\n");
	}
	else if(strcmp(PT3,"Plan200")==0)
	{
		printf("\n\nClaim Benefits for Plan 200\n");
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
	else
	{
		printf("\nUnable to find the suitable table");
		exit(0);
	} 
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get user claim amount for number of days in normal ward and store it in *
*						the respective variable/memory  										   *
****************************************************************************************************
*/
int getRoomCharges()
{
	int num1;
	bool n=false;
	printf("\nPlease enter the number of days that you stay in the normal ward\n");
	while(n!=true)
	{
		if(scanf("%d", &num1) != 1)
   		{
    		num1=0;
    		printf("Wrong input\nPlease enter again\n");
			getchar();	
    	}
    	else
    	{
    		n=true;
		}
	}
	return num1;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get user claim amount for number of days in ICU and store it in 		   *
*						the respective variable/memory  										   *
****************************************************************************************************
*/
int getIcuCharges()
{
	int num2;
	bool n=false;
	printf("\nPlease enter the number of days that you stay in the Intensive Care Unit\n");
	while(n!=true)
	{
		if(scanf("%d", &num2) != 1)
   		{
    		num2=0;
    		printf("Wrong input\nPlease enter again\n");
			getchar();	
    	}
    	else
    	{
    		n=true;
		}
	}
	return num2;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get user claim amount for hospital supplies and services and store it in*
*						the respective variable/memory  										   *
****************************************************************************************************
*/
float getHospitalSuppliesAndServices()
{
	float num3;
	bool n=false;
	printf("\nPlease enter the total hospital supplies and services fees\nRM ");
	while(n!=true)
	{
		if(scanf("%f", &num3) != 1)
   		{
    		num3=0;
    		printf("Wrong input\nPlease enter again\nRM");
			getchar();	
    	}
    	else
    	{
    		n=true;
		}
	}
	return num3;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To get user claim amount for surgical and other fee and store it in 	   *
*						the respective variable/memory  										   *
****************************************************************************************************
*/
float getSurgicalAndOtherFees()
{
	float num4;
	bool n=false;
	printf("\nPlease enter the total surgical and other fees\nRM ");
	while(n!=true)
	{
		if(scanf("%f", &num4) != 1)
   		{
    		num4=0;
    		printf("Wrong input\nPlease enter again\nRM");
			getchar();	
    	}
    	else
    	{
    		n=true;
		}
	}
	return num4;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To add up all 4 of the amount that have been inputed by the user and get   *
*                       the total amount that user want to claim based on their plan subsciption   *
* 						and also check whether the balance amount is able to cover the claim       *
*						requested by the user 										   			   *
****************************************************************************************************
*/
float totalRequestClaim(char *PT4,float amountBalance1, int getRoomCharges1,int getIcuCharges1,float getHospitalSuppliesAndServices1, float getSurgicalAndOtherFee1)
{
	float total;
	bool answer2=false;
	char answer[2];
	int d;
	if(strcmp(PT4,"Plan120")==0)
	{
		total=((getRoomCharges1*120)+(getIcuCharges1*250)+ getHospitalSuppliesAndServices1 + getSurgicalAndOtherFee1);
	}
	else if(strcmp(PT4,"Plan150")==0)
	{
		total=((getRoomCharges1*150)+(getIcuCharges1*400)+ getHospitalSuppliesAndServices1 + getSurgicalAndOtherFee1);
	}
	else if(strcmp(PT4,"Plan200")==0)
	{
		total=((getRoomCharges1*200)+(getIcuCharges1*700)+ getHospitalSuppliesAndServices1 + getSurgicalAndOtherFee1);
	}
	else
	{
		printf("An error occured");
	}
	if(total>amountBalance1)
	{
		total-=amountBalance1;
		printf("Your limit have been reach, you can only claim RM %.2f\nThe rest of the amount which is RM %.2f have to be borne by you\nWould you which to continue? ('Y','N')\n",amountBalance1,total);
		getchar();
		for(d=0;answer2!=true;d++)
		{
			gets(answer);
			if(strcmp(answer,"Y")==0)
			{
				printf("Your claim is RM %.2f\n",amountBalance1);
				answer2=true;
				total=amountBalance1;
				return total;
			}
			else if(strcmp(answer,"N")==0)
			{
				printf("Please call our customer service to subscribe to premium insurance to be insured more.\n Thank you for visiting our page\n");
				answer2=true;
				exit(0);
			}
			else
			{
				printf("Please enter the appropriate response\n");
			}
		}
	}
	else
	{
		printf("Your claim have been received\n");
		return total;
	}
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To update the value of amountBalance that is being store in the memory 	   *
****************************************************************************************************
*/
float changeAmountBalance(float amountBalance2,float total1)
{
	amountBalance2=amountBalance2-total1;
	return amountBalance2;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To update the value of amountclaim that is being stored in the memory 	   *
****************************************************************************************************
*/
float changeAmountClaim(float amountClaim1,float total2)
{
	amountClaim1=amountClaim1+total2;
	return amountClaim1;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To display the amount that the user will be claiming and display the       *
*						balance that user have left 	   										   *
****************************************************************************************************
*/
void displayOverallClaim(char *id2,char *name2,float total3,float amountBalance2)
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
    
	printf("\n\nInsurance Claim:\n");
	printf("ID: %s",id2);
	printf("Name: %s",name2);
	printf("Claim Date: %s/%s/%s\n",day,month,year);
	printf("Total Amount Claim: RM %.2f\n",total3);
	printf("Balance Claimable Amount: RM %.2f\n",amountBalance2);
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To store the record in the text file as prove of claim by the user         *
****************************************************************************************************
*/
void recordClaim(char *id3,char *name3,float total4,float amountBalance3)
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
        
	FILE *fp6,*fp7,*fp8;
	fp6=fopen("Insurance_Claims.txt","r");
	if(fp6==NULL)
	{
		fclose(fp6);
		fp7=fopen("Insurance_Claims.txt","w");
		fprintf(fp7,"Insurance Claim:\n");
		fprintf(fp7,"ID: %s",id3);
		fprintf(fp7,"Name: %s",name3);
		fprintf(fp7,"Claim Date: %s/%s/%s\n",day,month,year);
		fprintf(fp7,"Total Amount Claim: RM %.2f\n",total4);
		fprintf(fp7,"Balance Claimable Amount: RM %.2f\n",amountBalance3);
		fclose(fp7);
	}
	else
	{
		fclose(fp6);
		fp8=fopen("Insurance_Claims.txt","a");
		fprintf(fp8,"\n\nInsurance Claim:\n");
		fprintf(fp8,"ID: %s",id3);
		fprintf(fp8,"Name: %s",name3);
		fprintf(fp8,"Claim Date: %s/%s/%s\n",day,month,year);
		fprintf(fp8,"Total Amount Claim: RM %.2f\n",total4);
		fprintf(fp8,"Balance Claimable Amount: RM %.2f\n",amountBalance3);
		fclose(fp8);
	}
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To update the Insurance_Plans.txt to the correct amountBalance and         *
*						amountClaim value         												   *
****************************************************************************************************
*/
void updateInsurancePlansFile(int location5,float amountClaim2,float amountBalance4)
{
	FILE *fp9,*fp10,*fp11;
	int f=0,l=0,b,v;
	char z3[MAX][LINES];
	char amount1[40];
	char amount2[10];
	char amount3[40];
	char amount4[10];
	fp9=fopen("Insurance_Plans.txt","r");
	if(fp9==NULL)
	{
		printf("File is not available");
	}
	else
	{
		
		while(f<MAX && fgets(z3[f],sizeof(z3),fp9))
		{
   			++f;
		}
		sprintf(amount2, "%.2f", amountBalance4);
		strcpy(amount1,"Amount Balance: RM ");
		strcat(amount2,"\n");
		strcat(amount1,amount2);
		
		sprintf(amount4, "%.2f", amountClaim2);
		strcpy(amount3,"Amount Claim: RM ");
		strcat(amount4,"\n");
		strcat(amount3,amount4);
	
		for(b=0;b<strlen(amount1)+1;b++)
		{
			z3[location5+5][b]=amount1[b];
		}	
		for(v=0;v<strlen(amount3)+1;v++)
		{
			z3[location5+6][v]=amount3[v];
		}
		fclose(fp9);
		fp10=fopen("Insurance_Plans.txt","w");
		while(strlen(z3[l])!=0)
		{
			fprintf(fp10,"%s",z3[l]);
			l++;
		}
		fclose(fp10);
	}	
}
