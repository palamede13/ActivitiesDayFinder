#include include/main.h

int main(int argc, char **argv)
{
	t_date_exc	date_exc;
	t_data		data;
	// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //
	if (argc > 1 && pars_input(argc, argv))
	(
		fill_input(argc, argv, &data, &date_exc);
	)
	else
	(
		ask_and_fill_data(&data, &date_exc);
	)

}