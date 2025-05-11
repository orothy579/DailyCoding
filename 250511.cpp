#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  vector<int> a;

  int n;
  int nums;
  int count = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> nums;
    a.push_back(nums);
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      // swap
      if (a[j] > a[j + 1])
      {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
        count++;
      }
    }
  }

  cout << count << endl;
}