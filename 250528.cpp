#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
  int n;
  cin >> n;

  // clang-format off
  vector<pair<int, int> > a(n);
  // clang-format on

  for (int i = 0; i < n; i++)
  {
    cin >> a[i].second;
    cin >> a[i].first;
  }

  sort(a.begin(), a.end());

  int count = 0;
  int end = -1;

  for (int i = 0; i < n; i++)
  {
    if (a[i].second >= end)
    {
      end = a[i].first;
      count++;
    }
  }
  cout << count << '\n';
}