/*
** number_functions.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Tue Apr 25 10:33:23 2017 Régis Berthelot
** Last update Tue Apr 25 10:34:18 2017 Régis Berthelot
*/

int	nbr_extract_from(char *str, int *i)
{
  int	value;

  value = 0;
  while (str[*i] != '\0')
    {
      if (!(str[*i] >= '0' && str[*i] <= '9'))
	break ;
      value = (value * 10) + (str[*i] - 48);
      *i += 1;
    }
  *i -= 1;
  return (value);
}
