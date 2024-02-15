#include "include/main.h"

void init(t_data *data)
{
	data->StartDay = 0;
	data->StartMounth = 0;
	data->StartYear = 0;
	data->number_of_days = 0;
	data->day_needed = 0;
}

int main(int argc, char **argv)
{
	t_data		data;
	(void)		argc;
	(void)		argv;
	// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //
	init(&data);
	if(ask_and_fill_data(&data))
		return (0);
	
	
	// DEBUG PART
	// print_start_day(&data);
	// print_number_of_days(&data);
	// print_day_needed(&data);
}