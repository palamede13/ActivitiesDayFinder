#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
// # include <readline/readline.h>
// # include <readline/history.h>

typedef struct s_date_exc
{
	int i;
}	t_date_exc;

typedef struct s_data
{
	t_date_exc dateExc;
}	t_data;

void print_start_day(t_data *data);

int ask_and_fill_data(t_data *data);

#endif