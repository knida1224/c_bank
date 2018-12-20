// Kyle Nida
// Z 23410025
// program2.c -[Program 2–The Bank]
// COP2220
// 03/12/2017

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h> 
#define CREDITLIMIT 3000

//Greet the user
void Greeting();

// Displays the list of integer options available
// prompts for the user’s choice and sets the value of the choicePtr
void RunChoices(int *choicePtr);


//Asks if they want another transaction 
//sets the value of againPtr to (y or n) 
void MakeTransaction(char *againPtr);

//Asks the user which type of account they would like to access and sets the
//value of the the character accountPtr 
void SelectAccount(char *accountPtr);

//Prompts the user for the amount to deposit 
//and adds that value to the amount in the bank account
void AddMoney(double *moneyPtr);

//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed 
void RemoveMoney(double *moneyPtr, char account );

//Displays the user’s current account balance for all three accounts
void DisplayBalance(double checking, double savings, double credit);

int main()
{
	double checking = 650;
	double savings = 750;
	double credit = -700;
	int trans;
	char selectacct = '0';
	double money;
	char again;
	char * accountPtr = &selectacct;
	double *moneyPtr = &money;
	
	Greeting();
	do {

		DisplayBalance(checking, savings, credit);
		RunChoices(&trans); //gives a num
		if (trans == 1)
		{
			SelectAccount(accountPtr); //gives a letter
			if (selectacct == 'C')
			{
				double * moneyPtr = &checking;
				AddMoney(moneyPtr);
				DisplayBalance(checking, savings, credit);
			}
			else if (selectacct == 'S')
			{
				double * moneyPtr = &savings;
				AddMoney(moneyPtr);
				DisplayBalance(checking, savings, credit);
			}
			else
			{
				double * moneyPtr = &credit;
				AddMoney(moneyPtr);
				DisplayBalance(checking, savings, credit);
			}

		}
		else if (trans == 2) {
			SelectAccount(&selectacct); //gives a letter
			if (selectacct == 'C')
			{
				moneyPtr = &checking;
				RemoveMoney(moneyPtr, selectacct);
				DisplayBalance(checking, savings, credit);

			}
			else if (selectacct == 'S')
			{
				moneyPtr = &savings;
				RemoveMoney(moneyPtr, selectacct);
				DisplayBalance(checking, savings, credit);
			}
		}
		if (selectacct == 'R')
		{
			moneyPtr = &credit;
			RemoveMoney(moneyPtr, selectacct);
			DisplayBalance(checking, savings, credit);
		}
		
		

		printf("WOULD YOU LIKE TO MAKE ANOTHER TRANSCATION (Y/N): ");
		scanf(" %c", &again);

		printf("\n    THANK YOU FOR CHOOSING MINI BANK\n\n");
		

	} while (again == 'Y' || again == 'y' );
	

	
	
	return 0;

}

// function definition
void Greeting() 
{           
	printf("                    WELCOME TO MINI BANK \n");
	printf("                  ************************\n\n");

}
void DisplayBalance(double checking, double savings, double credit)
{

		printf("\n  PERSONAL ACCOUNT BALANCE");
		
		printf("\n\n    1).CHECKING: %.2lf", checking);
		printf("\n    2).SAVINGS:  %.2lf", savings);
		printf("\n    3).CREDIT:  %.2lf",credit);
		printf("\n\n************************************************\n\n");

}

void RunChoices(int *choicePtr)
{
	int choice;
	printf("SELECT OPTION:\n");
	printf("\n1).DEPOSIT\n");
	printf("2).WITHDRAWL\n");
	
	printf("\nENTER YOUR OPTION HERE: ");
	scanf("%d", &choice);
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	*choicePtr = choice;


}

void MakeTransaction(char *againPtr)
{
	printf("\n\nWOULD YOU LIKE TO MAKE ANY TRANSACTION TODAY:Y/N");
	scanf(" %c", againPtr);
	*againPtr = toupper(*againPtr); 
}
void SelectAccount(char *accountPtr)
{
	printf("\nWHICH ACCOUNT WOULD YOU LIKE TO ACCESS?\n");
	printf("		C for CHECKING\n");
	printf("		S for SAVINGS\n");
	printf("		R for CREDIT\n");
	printf("\nENTER YOUR OPTION HERE: ");
	scanf(" %c", &*accountPtr);
	*accountPtr = toupper(*accountPtr);

}


void AddMoney(double *moneyPtr)
{
	double add;
	printf("\nPLEASE ENTER THE AMOUNT YOU WANT TO DEPOSIT:");
	scanf("%lf", &add);
	*moneyPtr=*moneyPtr + add;

}
	void RemoveMoney(double *moneyPtr, char letter)
	{
		double account;
		printf("\nHOW MUCH MONEY WOULD YOU LIKE TO WITHDRAW TODAY?");
		scanf("%lf", &account);
		
			if (letter == 'R' && *moneyPtr-account>=-CREDITLIMIT)
			{
				*moneyPtr =*moneyPtr- account;
									
			}
				
			else if (letter == 'C' && *moneyPtr -account>=0) {
				*moneyPtr = *moneyPtr - account ;
			
			}
			else if (letter == 'S' &&  *moneyPtr - account >= 0) {
				*moneyPtr = *moneyPtr - account;
			}
			else {
				printf("\n\n\n  !!! YOU DO NOT HAVE ENOUGH MONEY AVAILABLE !!!  \n\n\n" );
			}
	}
