#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 0;
  int num = 0;

  cin >> n;
  int nums[10001] = {0};

  for (int i = 1; i <= n; i++)
  {
    cin >> num;
    nums[num]++;
  }

  for (int i = 1; i <= 10000; i++)
  {
    if (nums[i] != 0)
    {
      for (int j = 0; j < nums[i]; j++)
      {
        cout << i << "\n";
      }
    }
  }
}