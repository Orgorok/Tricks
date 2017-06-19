# include <stdlib.h>
# include <stdio.h>

typedef struct s_struct 	// Doit se trouver dans le header
{							// //
	int		ac;				// //
	char	**av;			// //
}				t_struct;	// //

t_struct *ft_main_struct(void)
{
	static t_struct	*v;				// Declaration en static afin de conserver les valeurs a chaque rappel;

	if (!v)							// Au premier appel : Si n existe pas = creation, puis dans tous les cas = renvoie du pointeur;
		if (!(v = (t_struct *)malloc(sizeof(t_struct))))
			exit (0);
	return (v);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	ft_main_struct();               // Declaration de la structure;

	ft_main_struct()->ac = argc;	// Assignation des valeurs;
	ft_main_struct()->av = argv;	// //

	printf("\nargc = %d, ac = %d\n\n", argc, ft_main_struct()->ac);	// Verification de l attribution de données aux valeurs de la structure;
	printf("name_exe = %s\n", ft_main_struct()->av[0]);				// //
	while (ft_main_struct()->av[i])									// //
	{																// //
		printf("arg %d : %s\n", i, ft_main_struct()->av[i]);		// //
		i++;														// //
	}																// //
	return (0);
}
