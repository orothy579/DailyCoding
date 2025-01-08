/*
  P1377
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  int N;

  cin >> N;

  vector< pair <int, int> > A(N+1);

  for (int i = 1; i < N+1; i++)
  {
    cin >> A[i].first;
    A[i].second = i;
  }

  sort(A.begin(), A.end());
  int max = 0;

  for (int i = 1; i < N+1; i++)
  {
    if (max < A[i].second - i)
    {
      max = A[i].second - i;
    }
  }

  cout << max + 1;
}
