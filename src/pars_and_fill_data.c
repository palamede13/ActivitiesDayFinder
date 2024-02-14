#include "include/main.h"
// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //


bool check_str_nb_char(int n, char *str)
{
	if (!str)
		return (1);
	int i = 0;
	while(i <= n)
	{
		if (!*(str + i))
			return (1);
		i++;
	}
	return (0);
}

// Is this char a number?
bool is_num(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

// Parse date / is str on format DD/MM/YYYY
bool pars_date(char *str)
{
	if (check_str_nb_char(9, str))
		return (1);
	if (!(is_num(*str) && is_num(*(str + 1)) && (*(str + 2) == '/') && is_num(*(str + 3)) && is_num(*(str + 4)) && (*(str + 5) == '/') && is_num(*(str + 6)) && is_num(*(str + 7)) && is_num(*(str + 8)) && is_num(*(str + 9))))
		return (1);
	return (0);
}

// get day/mounth/year from format DD/MM/YYYY
int ft_get_day(char *str)
{
	int day = 0;

	if (pars_date(str))
		return (1);
	day = (*(str) - 48) * 10;
	day += (*(str + 1) - 48);
	return (day);
}

int ft_get_mounth(char *str)
{
	int mounth = 0;

	if (pars_date(str))
		return (1);
	str += 3;
	mounth = (*(str) - 48) * 10;
	mounth += (*(str + 1) - 48);
	return (mounth);
}

int ft_get_year(char *str)
{
	int year = 0;

	if (pars_date(str))
		return (1);
	str += 6;
	year = (*(str) - 48) * 1000;
	year += (*(str + 1) - 48) * 100;
	year += (*(str + 2) - 48) * 10;
	year += (*(str + 3) - 48);
	return (year);
}

// Is str on format DD/MM/YYYY and a valid date
bool is_valid_date(char *str)
{
	if (pars_date(str))
		return (1);

	int day = ft_get_day(str);
	int mounth = ft_get_mounth(str);
	int year = ft_get_year(str);

	if (day < 1 || day > 31)
		return (1);
	if (mounth < 1 || mounth > 12)
		return (1);
	if ((mounth < 7 && !(mounth % 2) && day == 31) || (mounth > 7 && (mounth % 2) && day == 31))
		return (1);
	if (mounth == 2 && (((year % 4) && day > 28) || day > 29))
		return (1);
	return (0);
}

// Actually get start date and fill date with it
void fill_date(char *str, t_data *data)
{
	data->StartDay = ft_get_day(str);
	data->StartMounth = ft_get_mounth(str);
	data->StartYear = ft_get_year(str);
}

// Get start date, verify if start date is valid and fill start date in data
bool get_date(t_data *data)
{
	char *str;

	str = readline("Day start \"DD/MM/YYYY\":");
	while (*str != 0)
	{
		if (!is_valid_date(str))
		{
			fill_date(str, data);
			return (0);
		}
		str = readline("Day start \"DD/MM/YYYY\":");
	}
	return (1);
}
// Ask and fill data if not from argv
int ask_and_fill_data(t_data *data)
{
// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //

	// char *prompt;
	// prompt = readline("")

	if(get_date(data))
		return (1);
	// if(number_of_day(data))
	// 	return (1);
	// if(day_needed(data))
	// 	return (1);
	// if(vacation_date(data))
	// 	return (1);
	// if (extra_exc_date(data))
	// 	return (1);
	return (0);
}
