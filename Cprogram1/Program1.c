/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Nathan Bui
 */
#include <stdio.h>
#include <string.h>

int main () {
	FILE *fp;
	fp = fopen("input.txt", "r");
	printf("Monthly Sales Report For 2022:\n Month	Sales\n");
	float sales_Num[12];
	for (int i = 0; i < 12; i++){
	  fscanf(fp, "%f", &sales_Num[i]);
	}
	char month[12][10] = {{"January"}, {"February"},
		{"March"}, {"April"}, {"May"},
		{"June"}, {"July"}, {"August"},
		{"September"}, {"October"}, {"November"},
		{"December"}};
	for (int i = 0; i < 12; i++)
	{
	  fputs(month[i], stdout);
	  printf("  :  $%.2f\n", sales_Num[i]);
	}

	printf("\n\nSales Summary: \n");
	printf("Minimum Sales");
	char month_low[20];
	float min = 100000000000000000;
	for (int i = 0; i < 12; i++)
	{
	  if (sales_Num[i] < min)
	  {
		  min = sales_Num[i];
		  strcpy(month_low, month[i]);
	  }
	}
	printf("\t$%.2f    (", min);
	fputs(month_low, stdout);
	printf(")");

	printf("\nMaximum Sales");
		char month_high[20];
		float max = 0;
		for (int i = 0; i < 12; i++)
		{
		  if (sales_Num[i] > max)
		  {
			  max = sales_Num[i];
			  strcpy(month_high, month[i]);
		  }
		}
		printf("\t$%.2f    (", max);
		fputs(month_high, stdout);
		printf(")");

	printf("\nAverage Sales: \t");
	float sum = 0;
	for (int i = 0; i < 12; i++){
		sum += sales_Num[i];
	}
	float avg = sum / 12;
	printf("$%.2f", avg);

	printf("\n\nSix-Month Moving Average Report: \n");
	for (int i = 0; i < 7; i++)
	{
		float six_mo_sum = 0;
		fputs(month[i], stdout);
		printf("  -  ");
		fputs(month[i + 5], stdout);
		for (int j = 0; j < 6; j++)
		{
			six_mo_sum += sales_Num[i+j];
		}
		float six_mo_avg = six_mo_sum / 6;
		printf("  $%.2f\n", six_mo_avg);
	}
	printf("\n\nSales Report(Highest to Lowest)");
	char new_month_list[12][20];
	float new_nums[12];
	for (int i = 0; i < 12; i++)
	{
		strcpy(new_month_list[i], month[i]);
		new_nums[i] = sales_Num[i];
	}
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12 - i - 1; j++)
		{
		  if (new_nums[j] < new_nums[j+1])
		  {
			  float tmp;
			  char temp[20];
			  tmp = new_nums[j + 1];
			  strcpy(temp, new_month_list[j + 1]);
			  new_nums[j + 1] = new_nums[j];
			  strcpy(new_month_list[j + 1], new_month_list[j]);
			  new_nums[j] = tmp;
			  strcpy(new_month_list[j], temp);
		  }
		}
	}
	for (int i = 0; i < 12; i++)
	{
		printf("\n$%.2f   ", new_nums[i]);
		fputs(new_month_list[i], stdout);
	}
	return 0;
}

