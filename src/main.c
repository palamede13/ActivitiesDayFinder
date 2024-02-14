#include "include/main.h"

int main(int argc, char **argv)
{
	t_data		data;
	(void)		argc;
	(void)		argv;
	// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //
	if(ask_and_fill_data(&data))
		return (0);
	print_start_day(&data);
}