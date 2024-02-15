#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdbool.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_date_exc
{
	int day;
	int mounth;
	int year;

	t_date_exc *next;
}	t_date_exc;

typedef struct s_data
{
	int StartDay;
	int StartMounth;
	int StartYear;
	int	number_of_days;
	// bit wise here : 01111111 : 1 = LU / 2 = MA / 4 = ME / 8 = JE / 16 = VE / 32 = SA / 64 = DI 
	char day_needed;

	t_date_exc first;
}	t_data;

// DEBUG FT
void	print_start_day(t_data *data);
void	print_number_of_days(t_data *data);
void	print_day_needed(t_data *data);

// PARS AND FILL FT
int		ask_and_fill_data(t_data *data);

// READLINE ????
char	*readline(const char *prompt);

#endif