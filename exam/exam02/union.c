#include <unistd.h>

void ft_union(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;
	int k = 0;
	int i = 0;
	int flag = 0;

	while (s1[len1] != '\0')
		++len1;
	while (s2[len2] != '\0')
	{
		s1[len1 + len2] = s2[len2];
		++len2;
	}
	s1[len1 + len2] = '\0';

	while(s1[i])
	{
		k = 0;
		while(k < i)
		{
			if(s1[i] == s1[k])
			{
				flag = 1;
				break;
			}
			++k;
		}
		if(flag == 0)
			write(1, &s1[i], 1);
		++i;
		flag = 0;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if(argc == 3)
		ft_union(argv[1], argv[2]);
	else
		write(1, "\n", 1);

	return(0);
}
