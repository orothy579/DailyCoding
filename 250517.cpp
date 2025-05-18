#include <iostream>

using namespace std;

static int n;

bool is_prime(int number)
{
  for (int i = 2; i <= number / 2; i++)
  {
    if (number % i == 0)
      return false;
  }
  return true;
}

void dfs(int number, int cur_n)
{
  if (cur_n == n)
  {
    if (is_prime(number))
    {
      cout << number << "\n";
    }
    return;
  }

  for (int i = 1; i <= 9; i++)
  {
    if (i % 2 != 0 && is_prime(number * 10 + i))
    {
      dfs(number * 10 + i, cur_n + 1);
    }
  }
}

int main(int argc, char **argv)
{

  cin >> n;
  dfs(2, 1);
  dfs(3, 1);
  dfs(5, 1);
  dfs(7, 1);
}
