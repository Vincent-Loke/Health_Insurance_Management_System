/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*           	   File Name: search.c                  *
*********************************************************
*/

/* Include the header file to allow this file to access the variable define in the header file*/
#include"search.h"

/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To execute the other functions in order when this function is being called *
****************************************************************************************************
*/
int search()
{
	user2 S;
	Data g;
	getNum(g.num,g.age,g.ageInDays,g.ageInYears,S.userAnswer1,S.userAnswer2,S.userAnswer3,S.method);
	openFileCompareDisplay(S.userAnswer1,S.userAnswer2,S.userAnswer3,S.method);
	return 0;
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: To display option to search for a specific user by using either (Name) or  *
*						(Id) or (Age, Plan type and Claim Limit) and get their input and store all *
*					    the input into their respective variable or in the memory 				   *
****************************************************************************************************
*/
void getNum(int num,int age,char *ageInDays,char *ageInYears,char *userAnswer1,char *userAnswer2,char *userAnswer3,char *method1)
{
	
	int k,m,b,n;
	char c[]="usingName";
	char d[]="usingId";
	
	bool answer=false;
	
  	char userName[25];
   	char userID[8];
    bool name=true;
	
	printf("Enter 1 to search using name\nEnter 2 to search using user ID\nEnter 3 to searh using Plan, Claim Limit Type and Age\nYour Selection: ");
	
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
			strcpy(method1,d);
			answer=true;
			strcpy(userAnswer1,"ID: ");       
  			strcat(userAnswer1, userID);
		}
		else if(num==3)
		{
			get3Attribute(age,ageInDays,ageInYears,userAnswer1,userAnswer2,userAnswer3,method1);
			answer=true;
		}
		else
		{
			printf("Wrong input entered\nEnter again\n");
		}
	}
}
/*
*****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				    *
* Function Description: If user is search using the combination of Age, Plan type and Claim Limit,  *
*						this function will be called to get Age, Plan type and Claim Limit from     *
*						user and store all the input into their respective variable or in the memory*
*****************************************************************************************************
*/
void get3Attribute(int age2,char *ageInDays2,char *ageInYears2,char *userAnswer4,char *userAnswer5,char *userAnswer6,char *method2)
{
	int n;
	
	char e[]="using3AttributeWithDaysOld";
	char f[]="using3AttributeWithYearsOld";
	char plan120[8]="Plan120";
	char plan150[8]="Plan150";
	char plan200[8]="Plan200";
	
	bool CLAnswer=false;
	bool PTAnswer=false;
	bool ageAnswer=false;
	bool ageInDaysAnswer=false;
	
	char plan[10];
	char CL[5];
	
	int ageInDays3;
	
	printf("If the subscriber is less than 1 years old, please enter '-1'\nEnter age:\n");
	while(ageAnswer!=true)
	{
		if(scanf("%d", &age2) != 1)
   		{
    		age2=0;
			getchar();	
    	}
		if(age2==-1)
		{
			ageAnswer=true;
			strcpy(method2,e);
			getchar();
			printf("Enter the age in days\n");
				
			while(ageInDaysAnswer!=true)
			{
				gets(ageInDays2);
				ageInDays3=atoi(ageInDays2);
				if(ageInDays3>0 && ageInDays3<365)
				{
					ageInDaysAnswer=true;
					sprintf(ageInDays2,"%d",ageInDays3); 
				}
				else
				{
					printf("Please enter an appropriate age in days\n");
				}
			}
			
			strcpy(userAnswer4,"Age: ");       
  			strcat(ageInDays2," Days Old\n");
  			strcat(userAnswer4,ageInDays2);
  			
  			printf("ACL = Annual Claim Limit\nLCL = Lifetime Claim Limit\nEnter Claim Limit Type:\n");
  			while(CLAnswer!=true)
  			{
  				fgets(CL,sizeof(CL),stdin);
  				if(strcmp("ACL\n",CL)==0) 
  				{
  					CLAnswer=true;
				}
  				else if(strcmp("LCL\n",CL)==0) 
  				{
  					CLAnswer=true;
				}
				else
				{
					printf("Please enter an appropriate claim limit\nEither ACL or LCL\nYour Selection: ");
				}
			}
  				
  			strcpy(userAnswer5,"Type of Claim Limit: ");       
  			strcat(userAnswer5,CL);
  	
  			printf("Enter Plan Type: \n");
  		
			while(PTAnswer!=true)
			{
  				fgets(plan,sizeof(plan),stdin);
  				if((strcmp("Plan 120\n",plan)==0) ||  (strcmp("plan 120\n",plan)==0) || (strcmp("Plan120\n",plan)==0) || (strcmp("plan120\n",plan)==0) )
  				{
  					strcpy(plan,plan120);
  					PTAnswer=true;
				}
  				else if((strcmp("Plan 150\n",plan)==0) ||  (strcmp("plan 150\n",plan)==0) || (strcmp("Plan150\n",plan)==0) || (strcmp("plan150\n",plan)==0) )
  				{
  					strcpy(plan,plan150);
  					PTAnswer=true;
				}
				else if((strcmp("Plan 200\n",plan)==0) ||  (strcmp("plan 200\n",plan)==0) || (strcmp("Plan200\n",plan)==0) || (strcmp("plan200\n",plan)==0) )
  				{
  					strcpy(plan,plan200);
  					PTAnswer=true;
				}
				else
				{
					printf("Please enter an appropriate plan\nEither Plan 120, Plan 150 or Plan 200\nYour Selection: ");
				}
			}
  			strcpy(userAnswer6,"Type of Plan: ");   
			strcat(plan,"\n");    
  			strcat(userAnswer6,plan);
		}
		else if(age2>0)
		{
			getchar();
			ageAnswer=true;
			strcpy(method2,f);
			sprintf(ageInYears2,"%d",age2);
			strcpy(userAnswer4,"Age: "); 
			strcat(ageInYears2," Years Old\n");    
  			strcat(userAnswer4,ageInYears2);
  				
  			printf("ACL = Annual Claim Limit\nLCL = Lifetime Claim Limit\nEnter Claim Limit Type:\n");
  			while(CLAnswer!=true)
  			{
  				fgets(CL,sizeof(CL),stdin);
  				if(strcmp("ACL\n",CL)==0) 
  				{
  					CLAnswer=true;
				}
  				else if(strcmp("LCL\n",CL)==0) 
  				{
  					CLAnswer=true;
				}
				else
				{
					printf("Please enter an appropriate claim limit\nEither ACL or LCL\nYour Selection: ");
				}
			}	
  			strcpy(userAnswer5,"Type of Claim Limit: ");       
  			strcat(userAnswer5,CL);
  				
  			printf("Enter Plan Type: \n");
  			while(PTAnswer!=true)
  			{
  				fgets(plan,sizeof(plan),stdin);
  				if((strcmp("Plan 120\n",plan)==0) ||  (strcmp("plan 120\n",plan)==0) || (strcmp("Plan120\n",plan)==0) || (strcmp("plan120\n",plan)==0) )
  				{
  					strcpy(plan,plan120);
  					PTAnswer=true;
				}
  				else if((strcmp("Plan 150\n",plan)==0) ||  (strcmp("plan 150\n",plan)==0) || (strcmp("Plan150\n",plan)==0) || (strcmp("plan150\n",plan)==0) )
  				{
  					strcpy(plan,plan150);
  					PTAnswer=true;
				}
				else if((strcmp("Plan 200\n",plan)==0) ||  (strcmp("plan 200\n",plan)==0) || (strcmp("Plan200\n",plan)==0) || (strcmp("plan200\n",plan)==0) )
  				{
  					strcpy(plan,plan200);
  					PTAnswer=true;
				}
				else
				{
					printf("Please enter an appropriate plan\nEither Plan 120, Plan 150 or Plan 200\nYour Selection: ");
				}
			}	
  		strcpy(userAnswer6,"Type of Plan: ");   
		strcat(plan,"\n");      
  		strcat(userAnswer6,plan);
		}
		else
		{
			printf("Please enter an appropriate age\n");
		}
	}
}
/*
****************************************************************************************************
*                                    Developer Name: Loke Weng Khay             				   *
* Function Description: Starts to open the InsurancePlan.txt file to compare between the data in   *
*						the memory/variable and the data in the text file, once the data is found  *
*						the user information is displayed to the user				   			   *
****************************************************************************************************
*/
void openFileCompareDisplay(char *userAnswer7,char *userAnswer8,char *userAnswer9,char *method3)
{
	FILE *fp;
    int i=0,l;
    char x[MAX][LINES];
    
    bool nameFound=false;
	bool idFound=false;
	bool dataFound=false;
	bool display1=false;	
	int count=0;
    fp = fopen("Insurance_Plans.txt","r");
    if(fp == NULL) 
	{
        printf("Cannot open file.\n");
    }
    else
    {
    	while(i<MAX && fgets(x[i],sizeof(*x),fp))
		{
   			++i;
		}
		if(strcmp(method3,"usingName")==0)
		{
			while(nameFound!=true)
			{
				if(strcmp(userAnswer7,x[count])==0)
				{
					printf("Name Found\n\n");
					nameFound=true;
					display1=true;
				}
				else if(strlen(x[count])==0)
				{
					printf("Name not found\n");
					nameFound=true;
				}
				count++;
			}
			if(display1==true)
			{
				for(l=count-2;l<count+9;l++)
				{
					printf("%s",x[l]);
				}
			}
		}
		else if(strcmp(method3,"usingId")==0)
		{
			while(idFound!=true)
			{
				if(strcmp(userAnswer7,x[count])==0)
				{
					printf("Id Found\n\n");
					idFound=true;
					display1=true;
				}
				else if(strlen(x[count])==0)
				{
					printf("Id not found\n");
					idFound=true;
				}
				count++;
			}
			if(display1==true)
			{
				for(l=count-1;l<count+10;l++)
				{
					printf("%s",x[l]);
				}
			}
		}
		else if((strcmp(method3,"using3AttributeWithDaysOld")==0) || (strcmp(method3,"using3AttributeWithYearsOld")==0))
		{
			while(dataFound!=true)
			{
				if((strcmp(userAnswer7,x[count])==0) && (strcmp(userAnswer8,x[count+1])==0) && (strcmp(userAnswer9,x[count+2])==0))
				{
					printf("\nData Found\n\n");
				
					display1=true;
					if(display1==true)
					{
						for(l=count-2;l<count+9;l++)
						{
							printf("%s",x[l]);
						}
					}
				}
				else if(strlen(x[count])==0)
				{
					if(display1==false)
					{
						printf("Data not found\n");
					}
					dataFound=true;	
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
