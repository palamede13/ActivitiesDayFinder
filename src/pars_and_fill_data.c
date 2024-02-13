#include include/main.h
t_date_exc	date_exc;
t_data		data;

// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //

// Is this char a number?
bool is_num(char c)
{
	if (c < 47 && c > 58)
		return (0);
	return (1);
}
// Parse date
bool pars_date(char *str)
{
	int	day = 0;
	int	mounth = 0;
	int year = 0;

	if (is_num(*str))
		day = ((*str) - 48 ) * 10;
	else
		return (0);

	return (1);
}
// Parse input from argv
bool pars_input(int argc, char **argv)
{
	int i = 1;
	if (argc < 4)
	{
		printf("Wrong data input, please enter them manually or quit (ctrl + c)\n");
		return (0);
	}
	if (pars_date(argv[i]))
	(

		i++;
	)
	else
	(
		printf("Wrong date start input, please enter them manually or quit (ctrl + c)\n");
		return (0);
	)
	i++;
	while (i < argc)
	{
	}
}

// Fill input from argv
void fill_input(int argc, char **argv, t_date_exc	*date_exc, t_data *data)
{

}

// Ask and fill data if not from argv
ask_and_fill_data(t_data *data, t_data_exc *date_exc)
{

}