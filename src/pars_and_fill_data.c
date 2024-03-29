#include "include/main.h"
// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //
int	ft_atoi(const char *str)
{
	int		signe;
	long	nb;
	long	a;

	a = 0;
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			signe *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + (*str - '0');
		str++;
	}
	return (nb = signe * a);
}

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
bool get_start_date(t_data *data)
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

// Verify if its only numbers
bool str_is_num(char* str)
{
	int i = 0;
	if (!str)
		return (1);
	while(str[i])
	{
		if (!is_num(str[i]))
			return (1);
		i++;
	}
	return (0);
}

// Fill nb of days in data
void	fill_nb_of_days(char *str, t_data *data)
{
	data->number_of_days = ft_atoi(str);
}

// Ask and fill data with number of the day
bool number_of_day(t_data *data)
{
	char *str;

	str = readline("Number of day wanted :");
	while (*str != 0)
	{
		if (!str_is_num(str))
		{
			fill_nb_of_days(str, data);
			return (0);
		}
		str = readline("Number of day wanted :");
	}
	return (1);
}

// check format CHARCHAR/CHARCHAR/CHARCHAR....
bool check_format_CCslashCC(char *str)
{
	int i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		i++;
		if ((((i % 3) == 0) && str[i-1] != '/') || ((i % 3) && (str[i-1] < 'A' || str[i-1] > 'Z')))
			return (1);
	}
	if (i > 20 || (i % 3) != 2)
		return (1);
	return (0);
}

// check and fill days needed
bool is_valid_day_needed_and_fill(char *str, t_data *data)
{
	int i = 0;

	if (!str)
		return (1);
	if (check_format_CCslashCC(str))
		return (1);
	while(str[i] && str[i + 1])
	{
		if (str[i] == 'L' && str[i + 1] == 'U')
		{
			if (data->day_needed % 2)
				return (1);
			data->day_needed += 1;
		}
		if (str[i] == 'M' && str[i + 1] == 'A')
		{
			if (data->day_needed % 4 == 2)
				return (1);
			data->day_needed += 2;
		}
		if (str[i] == 'M' && str[i + 1] == 'E')
		{
			if (data->day_needed % 8 == 4)
				return (1);
			data->day_needed += 4;
		}
		if (str[i] == 'J' && str[i + 1] == 'E')
		{
			if (data->day_needed % 16 == 8)
				return (1);
			data->day_needed += 8;
		}
		if (str[i] == 'V' && str[i + 1] == 'E')
		{
			if (data->day_needed % 32 == 16)
				return (1);
			data->day_needed += 16;
		}
		if (str[i] == 'S' && str[i + 1] == 'A')
		{
			if (data->day_needed % 64 == 32)
				return (1);
			data->day_needed += 32;
		}
		if (str[i] == 'D' && str[i + 1] == 'I')
		{
			if (data->day_needed % 128 == 64)
				return (1);
			data->day_needed += 64;
		}
		i += 3;
	}
	return (0);
}

// Ask and fill days needed
bool day_needed(t_data *data)
{
	char *str;

	str = readline("Day needed \"LU/MA/ME/JE/VE/SA/DI\" :");
	while (*str != 0)
	{
		if (!is_valid_day_needed_and_fill(str, data))
			return (0);
		data->day_needed = 0;
		str = readline("Wrong input, please take care of the format. Day needed \"LU/MA/ME/JE/VE/SA/DI\" :");
	}
	return (1);
}

//check vacation date (DD/MM/YYYY-DD/MM/YYYY)
bool check_vacation_date_format_and_date(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	if (i != 21)
		return (1);
	if (str[10] != '-')
		return (1);
	str[10] = 0;
	if (pars_date(str) | pars_date(str + 11))
		return (1);
	if (is_valid_date(str) && is_valid_date(str + 11))
		return (1);
	if (ft_get_year(str) > ft_get_year(str + 11))
		return (1);
	if (ft_get_mounth(str) > ft_get_mounth(str + 11))
		return (1);
	if (ft_get_day(str) > ft_get_day(str + 11))
		return (1);
	return (0);
}

// Get the day right before to sort excluded days
t_date_exc *get_day_exc_right_before(t_date_exc *first)
{
	
}

// Get vacation date from string to struct (day mounth year)
void	add_vacation_date_to_date_exc(t_data *data, char *str)
{
	char *start = str;
	char *end = str + 11;
	str + 10 = 0;
	int day_start = ft_get_day(str);
	int mounth_start = ft_get_mounth(str);
	int year_start = ft_get_year(str);
	int day_end = ft_get_day(end);
	int mounth_end = ft_get_mounth(end);
	int year_end = ft_get_year(end);

	t_date_exc *current = get_day_exc_right_before(data->first);



	if (data->first)
	{
		while (current->year < year_start)
			current = current->next;
		while (current->mounth < mounth_start)
			current = current->next;
		while (current->day < day_start)
			current = current->next;
		while (year_start < year_end)
		{
			while ((mounth_start < mounth_end) || (year_start != year_end))
			{
				while ((day_start < day_end) || (mounth_start != mounth_end))
				{
					if ()
				}
				if (mounth_start < 12)
					mounth_start++;
				else
				{
					mounth_start = 1;
					year_start++;
				}
			}

		}
		last = lst_last(data->first);
		fill_from_start_to_end_date_exc(last, str)
		last->next = new;
	}
	else
	{
		data->first = new;
		fill_from_start_to_end_date_exc(last, str)
	}
	new->day = ft_get_day(str);
	new->mounth = ft_get_mounth(str);
	new->year = ft_get_year(str);
}

// check and fill vacation date
bool vacation_date_check_and_fill(char *str, t_data *data)
{
	char start[10];
	char end[10];

	if (check_vacation_date_format_and_date(str))
		return (1);
	add_vacation_date_to_date_exc(data, str);
	return (0);
}

// Ask check and fill vacation date
bool get_vacation_dates(t_data *data)
{
	char *str;

	str = readline("Vacations date (one by one) \"DD/MM/YYYY-DD/MM/YYYY\" (f to end this part):");
	while (*str != 'f')
	{
		if (!vacation_date_check_and_fill(str, data))
		{

			printf("Vacations date done, next one?")
		}
		else
			printf("Wrong format, please try again");
		str = readline("Vacations date (one by one) \"DD/MM/YYYY-DD/MM/YYYY\" (f to end this part) :");
	}
	return (0);
}
// Ask and fill data if not from argv
int ask_and_fill_data(t_data *data)
{
// Date start DD/MM/YYYY // Number of date wanted N // Day wanted LU/MA/ME/JE/VE/SA/DI // Vacation date (DD/MM/YYYY-DD/MM/YYYY)// Extra excluded date DD/MM/YYYY //

	// if(get_start_date(data))
		// return (1);
	// if(number_of_day(data))
	// 	return (1);
	// if(day_needed(data))
	// 	return (1);
	if (get_vacation_dates(data))
		return (1);
	// if(vacation_date(data))
	// 	return (1);
	// if (extra_exc_date(data))
	// 	return (1);
	return (0);
}
