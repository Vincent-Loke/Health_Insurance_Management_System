/*
*********************************************************
*            Developer Name: Loke Weng Khay             *
*        Name of Program: Health Insurance System       *
*              File Name: menu.c               			*
*********************************************************
*/
//Decalration of the header file
#include"menu.h"

/*
*****************************************************************************
*                     Developer Name: Loke Weng Khay             			*
*     Function Description: This function is to get and check user input    *
*****************************************************************************
*/
void mainScreenOptions()
{
	int selection;
	bool answer=false;

	printf("Please Select: \n1 = Subscribe A New Insurance Plan\n2 = Claim Insurance\n3 = Account Information\n4 = Search\n5 = Exit\n\nYou Selected: ");
	while(answer!=true)
	{
		if(scanf("%d", &selection) != 1)
   		{
    		selection=0;
			getchar();	
    	}	
		if(selection==1)
		{
			answer=true;
			insurancePlanSubscription();
		}
		else if(selection==2)
		{
			answer=true;
			claimInsurance();
		}
		else if(selection==3)
		{
			answer=true;
			accountInformation();
		}
		else if(selection==4)
		{
			answer=true;
			search();
		}
		else if(selection==5)
		{
			answer=true;
			exit(0);
		}
		else
		{
			printf("Wrong input entered\nEnter again\n");
		}
	}
}
