#include <unistd.h>

void ft_inter(char *argv1, char *argv2)
{
	int i = 0;
	int j, k;
	int flag = 0;
	
	while(argv1[i])
	{
		j = 0;
		while(argv2[j])
		{
			if (argv1[i] == argv2[j])
			{
				k = 0;
				while(k < i)
				{
					if(argv1[i] == argv1[k])
					{
						flag = 1;
						break;
					}
					++k;
				}
				if(flag == 0)
				{
					write(1, &argv1[i], 1);
					break;
				}
			}	
			++j;
		}
		flag = 0;
		++i;
	}
	write(1, "\n", 1);
}


int main(int argc,char **argv)
{
	if(argc == 3)
		ft_inter(argv[1], argv[2]);
	else
		write(1, "\n", 1);

	return (0);
}	
