ewq


level 01 -------------------------------------------------

void	ft_flag_wp(char **p, t_flag *t, va_list ap)
{
	int	num;

	num = 0;
	if (**p == '*' && (*p)++)
		//day04 Q1 : int넘어가는 수가 되면 어케됨?
		//아래처럼 처리를 해주까?
		num = va_arg(ap, int);
	else if (**p == '-' || ft_isdigit(**p))
		num = ft_atoi_moveaddress(p);
	if (t->dot == 1)
		t->pre = num;
	else
	{
		if (num < 0)
		{
			t->wid = num * (-1);
			t->minus = 1;
		}
		else
			t->wid = num;
	}
	if (t->minus == 1 && t->zero == 1)
			t->zero = 0;	
}

int ft_atoi_moveaddress(char **str)
{
	long long	num;
	int			sign;

	sign = 1;
	while (**str == '\t' || **str == '\n' || **str == '\v' || **str == '\f'
			|| **str == '\r' || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		//day04 Q2 : int범위 넘어가면 어떻게 처리 할까?
		num = num * 10 + (**str - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		(*str)++;
	}
	return (num * sign);
}
