/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: g658k761
 */


#include <stdio.h>
#include <stdlib.h>

void salesReport(const char* months[], float nums[])
{

	printf("Monthly sales report for 2022: \n");
	printf("Month     Sales \n");
	for(int i = 0; i < 12; i++)
	{
		printf("%-9s $%5.2f\n", months[i], nums[i]);
	}
}

void salesSummary(const char* months[], float nums[])
{


	printf("Sales summary: \n");
	int ma = 0;
	float maximum = nums[0];
	for(int i = 0; i < 12; i++)
	{
		if(nums[i] > maximum)
		{
			maximum = nums[i];
			ma = i;
		}
	}

	int mi = 0;
	float minimum = nums[0];
	for(int i = 0; i < 12; i++)
	{
		if(nums[i] < minimum)
		{
			minimum = nums[i];
			mi = i;
		}
	}

	float sum;

	for(int i = 0; i < 12; i++)
	{
		sum += nums[i];
	}
	float average = sum/12;

	printf("Minimum sales: $%5.2f (",  minimum);
	printf("%s", months[mi]);
	printf(") \n");
	printf("Maximum sales: $%5.2f (",maximum);
	printf("%s", months[ma]);
	printf(") \n");
	printf("Average sales: $%5.2f \n", average);
}

void sixMonth(const char* months[], float nums[], int start)
{
    float average = 0;

    for(int i = start; i < start + 6; i++)
    {
        average += nums[i];
    }

    average = average/6;

    printf("\n%-9s - %-9s $%.2f", months[start], months[start + 5], average);

}

void highToLow(const char* months[], float nums[])
{
	printf("Sales Report (Highest to Lowest): \n");
    printf("Month      Sales\n");
	float num;
	char* mon;
	for(int i = 0; i < 12; i++)
	{
		for(int j = i + 1; j < 12; j++)
		{
			if(nums[i] < nums[j])
			{
				num = nums[i];
				nums[i] = nums[j];
				nums[j] = num;

                mon = months[i];
                months[i] = months[j];
                months[j] = mon;

			}
		}
		printf("%-9s  $%5.2f\n", months[i], nums[i]);
	}
}

int main()
{
	FILE *myFile;
	myFile = fopen("input.txt", "r");

	//read file into the array

	float numArr[12];
	const char* monthsArr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


	for(int i = 0; i < 12; i++)
	{
		fscanf(myFile, "%f", &numArr[i]);
	}

    int start = 0;

	salesReport(monthsArr, numArr);
	printf("\n");
	salesSummary(monthsArr, numArr);
	printf("\n");

    printf("Six-month Moving Average Report: ");
    for(int i = 0; i <= 6; i++)
    {
        sixMonth(monthsArr, numArr, start + i);  
    }

	printf("\n\n");
	highToLow(monthsArr, numArr);


	fclose(myFile);

	return 0;
}
