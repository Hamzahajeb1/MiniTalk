#include <unistd.h>
#include <signal.h>
#include <limits.h>

static	int	ft_isspace(char c)
{
  if ((c >= 9 && c <= 13) || c == 32)
    return (1);
  return (0);
}

int	ft_atoi(const char *str)
{
  int					i;
  unsigned long long	nb;
  int					sign;

  i = 0;
  nb = 0;
  sign = 1;
  while (ft_isspace(str[i]) == 1)
    i++;
  if (str[i] == '-')
  {
    sign = -1;
    i++;
  }
  else if (str[i] == '+')
    i++;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
  {
    nb = (nb * 10) + str[i++] - 48;
    if (nb >= LLONG_MAX && sign == 1)
      return (-1);
    else if (nb >= LLONG_MAX && sign == -1)
      return (0);
  }
  return ((int)(nb * sign));
}

void	sig_send(int pid, char c)
{
  int	arr[8];
  int	j;
  int	i;

  j = c;
  i = 7;
  while (i >= 0)
  {
    if (j == 0 || (j & 1) == 0)
      arr[i] = 0;
    else if ((j & 1) == 1)
      arr[i] = 1;
    if (j > 0)
      j >>= 1;
    i--;
  }
  while (++i < 8)
  {
    if (arr[i] == 0)
      kill(pid, SIGUSR1);
    else
      kill(pid, SIGUSR2);
    usleep(100);
  }
}

int	main(int argc, char **argv)
{
  int	pid;

  if (argc != 3)
    write(1, "Args error", 10);
  else
  {
    pid = ft_atoi(argv[1]);
    if (pid == -1)
    {
      write(1, "forbidden PID!\n", 13);
      return 1;
    }
    while (argv[2] && *argv[2])
      sig_send(pid, *argv[2]++);
    sig_send(pid, '\n');
  }
  return (0);
}
