#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(long nb)
{
  char	i;

  if (nb / 10 > 0)
    ft_putnbr(nb / 10);
  i = nb % 10 + '0';
  write(1, &i, 1);
}

void	handler(int sig)
{
  static int	i;
  static int	j;
  int			n;

  if (sig == SIGUSR1)
    n = 0;
  else
    n = 1;
  j = (j << 1) + n;
  i++;
  if (i == 8)
  {
    write(1, &j, 1);
    i = 0;
    j = 0;
  }
}

int main(void) {
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    write(1, "Hello everything is established well, Here's the PID => ", 56);
    ft_putnbr(getpid());
    write(1, "\n", 1);
     while (1)
         pause();

    return 0;
}

// void handler(int sig) {
//     static int i = 0;
//     static int j = 0;
//     int n = (sig == SIGUSR1) ? 0 : 1;

//     j = (j << 1) + n;
//     i++;
//     if (i == 8) {
//         write(1, &j, 1);
//         i = 0;
//         j = 0;
//     }
// }

// int main(void) {
//     struct sigaction sa;
//     sa.sa_handler = handler;
//     sa.sa_flags = 0;
//     sigemptyset(&sa.sa_mask);

//     sigaction(SIGUSR1, &sa, NULL);
//     sigaction(SIGUSR2, &sa, NULL);

//     printf("Hello, everything is established well. Here's the PID: %d\n", getpid());

//     while (1)
//         pause(); // Wait for signals without consuming CPU

//     return 0;
// }
