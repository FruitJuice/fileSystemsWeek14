// fileSystems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <stdio.h>
#include "time.h"
#include "stdlib.h"

FILE *openFile(char *filename, char *mode);
void closeFile(FILE *fptr);
double balanceGen();

struct account
{
	int ID;
	double balance;
};

int main()
{
	srand((unsigned)time(NULL));
	int i;
	struct account accounts[101];

	FILE *fptr;
	FILE *nfptr;

	fptr = openFile("C:\\Users\\andri\\numbers.txt","r");
	for(i = 0; i < 15; i++)
	{
		fscanf(fptr, "%d %lf", &accounts[i].ID, &accounts[i].balance);
	}

	closeFile(fptr);
	for (i = 0; i < 15; i++) 
	{ 
		printf("%d \t %.2lf \n", accounts[i].ID, accounts[i].balance);
	}


	nfptr = openFile("C:\\Users\\andri\\newnumbers.txt", "w");
	for (i = 0; i < 101; i++)
	{
		fprintf(nfptr, "%d\t%.2lf\n", i, balanceGen());
	}
	closeFile(nfptr);

	nfptr = openFile("C:\\Users\\andri\\newnumbers.txt", "r");
	
	i = 0;
	while (!feof(nfptr))
	{
		fscanf(nfptr, "%d %lf", &accounts[i].ID, &accounts[i].balance);
		i++;
	}


	closeFile(nfptr);

	printf("\n\nNEW ACCOUNTS WITH NEGATIVE BALANCE\n");
	printf("-----\t-----\t-----\t-----\n\n");


	for (i = 0; i < 101; i++)
	{
		if (accounts[i].balance < 0)
		{
			printf("%d \t %.2lf \n", accounts[i].ID, accounts[i].balance);
		}
	}
	return 0;
}	

double balanceGen()
{
	int randBal;
	int sign;
	sign = rand() % 2;
	randBal = rand() % 20000;
	if (sign == 0)
	{
		randBal *= -1;
	}
	return randBal;
}


FILE *openFile(char *filename, char *mode)
{
	FILE *fptr = fopen(filename, mode);
	if (fptr == NULL)
	{
		printf("Error opening file!\n");
	}
	return fptr;
}

void closeFile(FILE *fptr)
{
	fclose(fptr);
}

