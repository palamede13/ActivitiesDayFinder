#include "include/main.h"

void print_start_day(t_data *data)
{
	printf("Day: %d\nMounth: %d\nYear: %d\n", data->StartDay, data->StartMounth, data->StartYear);
}

void print_number_of_days(t_data *data)
{
	printf("Number of days : %d\n", data->number_of_days);
}

void print_day_needed(t_data *data)
{
	int nb = data->day_needed;
	printf("VALUE : %d\n", data->day_needed);
	while(nb > 0)
	{
		if (nb % 2 == 1)
		{
			printf("LUNDI");
			nb -= 1;
			if (nb > 0)
				printf("/");
		}
		if (nb % 4 == 2)
		{
			printf("MARDI");
			nb -= 2;
			if (nb > 0)
				printf("/");
		}
		if (nb % 8 == 4)
		{
			printf("MERCREDI");
			nb -= 4;
			if (nb > 0)
				printf("/");
		}		
		if (nb % 16 == 8)
		{
			printf("JEUDI");
			nb -= 8;
			if (nb > 0)
				printf("/");
		}		
		if (nb % 32 == 16)
		{
			printf("VENDREDI");
			nb -= 16;
			if (nb > 0)
				printf("/");
		}		
		if (nb % 64 == 32)
		{
			printf("SAMEDI");
			nb -= 32;
			if (nb > 0)
				printf("/");
		}		
		if (nb % 128 == 64)
		{
			printf("DIMANCHE");
			nb -= 124;
		}
	}
	printf("\n");
}

void print_date_excluded(t_date_exc *first)
{
	printf("Days exluded :\n");
	while (first)
	{
		printf("%d/%d/%d excluded\n", first->day, first->mounth, first->year);
		first = first->next;
	}
}