#include "../includes/push_swap.h"



int	arg_is_num(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && ft_isdigit(av[i]))
		return (0);
	return (1);
}


// int input_check(char **av)
// {
//     int i;

//     i = 1;
// }



void write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}




//error utils

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}