#include <iostream>
#include <vector>

using namespace std;

static vector<int> a;
static vector<int> tmp;

void merge_sort(int s, int e)
{
  if ( e - s < 1)
  {
    return;
  }

  int m = s + ( e - s ) / 2;

  merge_sort(s,m);
  merge_sort(m+1,e);

  for (int i = s; i <= e; i++)
  {
    tmp[i] = a[i];
  }

  int k = s;
  int index1 = s;
  int index2 = m + 1;

  while(index1 <= m && index2 <= e)
  {
    if(tmp[index1] > tmp[index2])
    {
      a[k] = tmp[index2];
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

  while(index1 <= m)
  {
    a[k] = tmp[index1];
    k++;
    index1++;
  }

  while(index2 <= e)
  {
    a[k] = tmp[index2];
    k++;
    index2++;
  }
}

int main(int argc, char* argv[])
{
  int n;
  cin >> n;
  a = vector<int>(n+1, 0);
  tmp = vector<int>(n+1, 0);

  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  merge_sort(1,n);

  for(int i = 1; i <= n ; i++)
  {
    cout << a[i] << "\n";
  }
}