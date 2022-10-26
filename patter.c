

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {


	// squre

	/*

	int row, column;

	printf("enter no. of row:");
	scanf("%d", &row);


	printf("enter no. of column:");
	scanf("%d", &column);


	for (int i = 0;i < row;i++)
	{


		for (int j = 0;j <= column;j++)
		{
			printf("*");
		}


		printf("*\n");
	}

	*/



	// upper right triangle
	
	/*
	int row = 0;
	
	printf("enter no. of row:");
	scanf("%d", &row);

	for (int i = 0;i <row;i++)
	{


		for (int j = 0;j<i;j++)
		{
			printf("*");

		}


		printf("\n");
	}
	*/

	// lower right triangle 

	/*
	int row = 0;

	printf("enter no. of row:");
	scanf("%d", &row);

	for (int i = row;i >0;i--)
	{


		for (int j = 0;j < i;j++)
		{
			printf("*");

		}


		printf("\n");
	}
	*/

	//Rhombus
/*
	int row = 0;

	printf("enter no. of row:");
	scanf("%d", &row);

	for (int i = 0;i < row;i++)
	{
		for ( int k = 0;k < i;k++) {
		
			printf(" ");

		}


		for (int j = row-1;j>0;j--)
		{
			printf("*");

		}


		printf("\n");
	}

	*/


	//cross pattern

/*
	int num;

	printf("enter a num:");
	scanf_s("%d", &num);	
	int m = num * 2 - 1;
	int end = num;

	for (int i = 1;i <= m;i++)
	{	

		for (int j = 1;j <= m;j++)
		{	//012345678

			if (i == j || j == end - 1 + 1)
			{

				printf("*");
			}
			else {

				printf(" ");
			}
		}
		printf("\n");




	}
	*/


	//pyramid pattern

	/*
	
	int num;
	int end = 0;
	printf("enter a num:");
	scanf_s("%d", &num);

	//num = num * 2 - 1;
	end = num;
	
	for (int i = 1;i <= num;i++) {	//012345678

			for (int j = 1;j <= end - 1;j++) {	//012345678

					printf(" ");


			}
			for (int k = 1;k <= i * 2 - 1;k++) {

				printf("*");
			}
				end--;
			printf("\n");


	}

	*/

	return 0;
}