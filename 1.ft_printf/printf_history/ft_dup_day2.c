
first
------------------------------------------------------------
init_flag(&t);
	va_start (ap, p);

while (p[i])
	{
		if (p[i] == '%')
		{
			p = ft_flag_minus(&p[i + 1], &t);
			p = ft_flag_width(&p[i], &t);
			if (p[i++] == '.')
				p = ft_flag_width(&p[i], &t);
		}
		write (1, &p[i], 1);
		++i;
		//여기에 조건이 필요//
		flag_init (&t);
	}
	va_end (ap);
	return (i);
}

char *ft_flag_width(char *p, t_flag *t)
{
	int num;
	//예외처리
	if (*p == '*' && p++)
		num = va_arg(ap, int);
	while (ft_isdigit(*p++))
		num = num * 10 + (*p - '0');
	if (num <= 0)
	{
		if(t->input = 0)
		{
			t->minus = 1;
			t->wid = (-1) *num;
		}


	if (t->input = 0)
		t->wid = num;
		t->input = 1;
	else
		t->pre = num;
	return (p);
}

char *ft_flag_minus(char *p, t_flag *t)
{
	while(!ft_isdigit(*p) && p++)
	{
		if (*p == '-')
			t->minus = 1;
		else if (*p == '0')
			t->zero = 1;
		if (t->minus == 1 && t->zero == 1)
			t->zero = 0;
	}
	return (p);
}

first - > level up 1
---------------------------------------------------------------

void ft_parse(char *p, t_flag *t);
{
	int i;

	i = 0;
	if (p[i] == '0' || p[i] == '-')
		p = ft_flag_lineup_zero(p, &t);
	if (ft_isdigit(p))
		p = ft_flag_width(p, &t);
	if (p[i] == '.' && i++)
		p = ft_flag_width(p, &t);
}

int ft_printf(char *p, ...)
{
	va_list ap;
	int i;
	t_flag t;

	i = 0;
	init_flag(&t);
	va_start (ap, p);
	while (p[i])
	{
		if (p[i] == '%' && i++)
			ft_parse(p, &t);
		write (1, &p[i], 1);
		++i;
		//여기에 조건이 필요//
		flag_init (&t);
	}
	va_end (ap);
	return (i);
}

1 -> level up 2
------------------------------------------------------

void ft_parse(char *p, t_flag *t);
{
	int i;

	i = 0;
	if (p[i] == '0' || p[i] == '-')
		ft_flag_lineup_zero(&p, &t);
	if (ft_isdigit(p))
		ft_flag_width(&p, &t);
	if (p[i] == '.' && i++)
		ft_flag_width(&p, &t);
}

int ft_printf(char *p, ...)
{
	va_list ap;
	int i;
	t_flag t;

	i = 0;
	init_flag(&t);
	va_start (ap, p);
	while (p[i])
	{
		if (p[i] == '%' && i++)
			ft_parse(p, &t);
		write (1, &p[i], 1);
		++i;
		//여기에 조건이 필요//
		flag_init (&t);
	}
	va_end (ap);
	return (i);
}

2 -> level up 3
----------------------------------------------------

void ft_parse(char **p, t_flag *t);
{
	if (**p == '0' || **p == '-')
		ft_flag_lineup_zero(p, &t);
	if (ft_isdigit(**p))
		ft_flag_width(p, &t);
	if (**p == '.' && (*p)++)
		ft_flag_width(p, &t);
}

----------------------------------

first -> level up 4
-------------------------------------------

void ft_flag_w(char **p, t_flag *t)
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
		t->pre = 1;
		t->wid = num;	
	}
	else	
		t->wid = num;
}

void ft_flag_p(char **p, t_flag *t)
{
	long long	num;
	int			sign;

	num = 0;
	if (**p == '*' && (*p)++)
		t->pre = va_arg(ap, int);
	else if ((**p == '-' && (*p)++))
		sign *= -1;
	while (**p >= '0' && **p <= '0')
	{	
		num = num * 10 + (**p - '0');
		(*p)++;
	}
		t->pre = num;
}

level up 5
----------------------------------------------


int ft_format(char *p, t_flag *t, va_list ap)
{
	if (*p == 'd' || *p == 'i')
		return (format_d(t, ap));
}


int format_d(t_flag *t, va_list ap)
{
	int d;
  	d = va_arg(ap, int);
