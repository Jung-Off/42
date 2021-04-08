

first

------------------------------------------------
int ft_format(char *p, t_flag *t, va_list ap)
{
	if (*p == 'd' || *p == 'i')
		return (format_d(t, va_arg(ap, int)));
	return (0);
	//...
}

int solved_mallocsize(t_flag *t, char *d)
{
	int re_i;

	re_i = t->wid >= t->pre ? t->wid : t->pre;
	re_i = ft_strlen(d) >= re_i ? ft_strlen(d) : re_i;

	return (re_i);
}

char *ft_put_malloc(char *str_d, char **print_d, int index, t_flag *t)
{
	int i;
	
	i = ft_strlen(str_d);	
	while(i - 1 >= 0)
	{
		*print_d[index--] = str_d[i--]; 
		if(str_d[0] == '-')
			break;
	}
	if(t->pre > i)
	{	
		t->pre -= i;
		while((t->pre)--)
			index--;
	}
	while(index >= 0)
	{	
		if(str_d[0] == '-')
			*print_d[index--] = '-';
		*print_d[index--] = ' ';
	}
	return (*print_d);
}

int format_d(t_flag *t, int d)
{
	char	*print_d;
	char	*str_d;

	int		malloc_size;
	int		len_d;

	len_d = 0;
	str_d = ft_itoa(d);
	malloc_size = solved_mallocsize(t, str_d);	
	if(!(print_d = (char*)malloc(sizeof(char) * (malloc_size + 1))))
		return (0);
	ft_memset(print_d, '0', malloc_size);
	print_d[malloc_size--] = 0;
	/*
	//아마도 고쳐야됨//
	print_d = ft_put_malloc(str_d, &print_d, malloc_size, t);
	*/
	while(*print_d)
	{
		write(1, &print_d, 1);
		len_d++;
	}
	return (len_d);
}


level up ---------------------------------------

char *ft_flag_minus(char *p, t_flag *t)
{
	while(!ft_isdigit(*p))
	{
		if (*p == '-')
			t->minus = 1;
		else if (*p == '0')
			t->zero = 1;
		if (t->minus == 1 && t->zero == 1)
			t->zero = 0;
		(*p)++;
	}
	return (p);
}

level up 1--------------------------------------------

void ft_flag_lineup_zero(char **p, t_flag *t)
{
	while (**p == '0' || **p == '-')
	{
		if (**p == '-')
			t->minus = 1;
		else if (**p == '0')
			t->zero = 1;
		if (t->minus == 1 && t->zero == 1)
			t->zero = 0;
		(*p)++;
	}
}


level up 2--------------------------------------------------------

void ft_flag_w(char **p, t_flag *t, va_list ap)
{
	int num;

	num = 0;
	if (**p == '*' && (*p)++)
		num = va_arg(ap, int);
	//else if (**p >= '0' && **p <= '9')
	while (**p >= '0' && **p <= '9')
	{
		num = num * 10 + (**p - '0');
		(*p)++;
	}
	if (num < 0)
	{
		num *= -1;
		t->minus = 1;
		t->wid = num;
	}
	else
		t->wid = num;
}

void ft_flag_p(char **p, t_flag *t, va_list ap)
{
	//long long?!!!
	//으로 처리하는 방식을 어떻게 해결하는게 베스트 일까 싶다:
	int			num;
	int			sign;

	sign = 1;
	num = 0;
	if (**p == '*' && (*p)++)
		num = va_arg(ap, int);
	else if ((**p == '-' && (*p)++))
		sign *= -1;
	while (**p >= '0' && **p <= '9')
	{
		num = num * 10 + (**p - '0');
		(*p)++;
	}
		t->pre = sign * num;
}

ft_flag_p 와 ft_flag_w 함수 하나로 만들기
level up 2.5------------------------------------------------------



void ft_flag_p(char **p, t_flag *t, va_list ap)
{
	int			num;

	num = 0;
	if (**p == '*' && (*p)++)
		num = va_arg(ap, int);
	else
		num = ft_atoi(*p);
	t->pre = num;
}
이런식으로 atoi를 할려면 주소도 옮겨줘야되

level up 3 ----------------------------------


void	malloc_init(char **print_d, char *str_d, int size, t_flag *t)
{
	if (t->zero == 1 || (t->pre) >= ft_strlen(str_d))
		ft_memset(*print_d, '0', size);
	else if (t->wid >= ft_strlen(str_d))
		ft_memset(*print_d, ' ', size);
}
