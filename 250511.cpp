#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int s, int e);
vector<int> a;
vector<int> tmp;
int n;
static long result;

int main(int argc, char **argv)
{

  cin >> n;

  a = vector<int>(n + 1, 0);
  tmp = vector<int>(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  result = 0;
  merge_sort(0, n - 1);

  cout << result << endl;
}

void merge_sort(int s, int e)
{
  if (e - s < 1)
  {
    return;
  }

  int m = s + (e - s) / 2;
  merge_sort(s, m);
  merge_sort(m + 1, e);

  for (int i = s; i <= e; i++)
  {
    tmp[i] = a[i];
  }

  int k = s;
  int index1 = s;
  int index2 = m + 1;

  while (index1 <= m && index2 <= e)
  {
    if (tmp[index1] > tmp[index2])
    {
      a[k] = tmp[index2];
      result = result + index2 - k;
      k++;
      index2++;
    }
    else
    {
      a[k] = tmp[index1];
      k++;
      index1++;
    }
  }

  while (index1 <= m)
  {
    a[k] = tmp[index1];
    k++;
    index1++;
  }
  while (index2 <= e)
  {
    a[k] = tmp[index2];
    k++;
    index2++;
  }
}