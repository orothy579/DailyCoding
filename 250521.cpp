#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  int start = 0;
  int end = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (start < a[i])
    {
      start = a[i];
    }
    end += a[i];
  }
  while (start <= end)
  {
    int middle = (start + end) / 2;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      if (sum + a[i] > middle)
      {
        count++;
        sum = 0;
      }
      sum += a[i];
    }
    if (sum != 0)
    {
      count++;
    }
    if (count > m)
    {
      start = middle + 1;
    }
    else
    {
      end = middle - 1;
    }
  }
  cout << start << "\n";
}