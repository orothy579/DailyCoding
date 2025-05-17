#include <iostream>

bool is_prime(int number)
{
  for (int i = 0; i < number / 2; i++)
  {
    if (number % i == 0)
      return false;
  }
  return true;
}

void dfs(int number, int n)
{
  int n_count = 0;
  if (n_count == n)
  {
    if (is_prime(number))
    {
      cout << number;
      break;
    }
    for (int i = 0; i <= 9; i++)
    {
      if(??)
    }
  }
}

int main(int argc, char **argv)
{
  int n;

  cin >> n;
}
