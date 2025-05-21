#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<int> a;

  cin >> n;

  a.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int m;

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    bool found = false;
    int target;
    cin >> target;

    int start = 0;
    int end = a.size() - 1;

    while (start <= end)
    {
      int mid = (start + end) / 2;
      int mid_value = a[mid];
      if (mid_value > target)
      {
        end = mid - 1;
      }
      else if (mid_value < target)
      {
        start = mid + 1;
      }
      else
      {
        found = true;
        break;
      }
    }
    if (found)
    {
      cout << "1" << "\n";
    }
    else
    {
      cout << "0" << "\n";
    }
  }
}