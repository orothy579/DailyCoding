#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  int n, k;
  cin >> n >> k;
  vector<int> a;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int coin = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] < k)
    {
      coin += k / a[i]; // 동전 개
      k = k % a[i];     // k 값 업데이트
    }
  }

  cout >> coin >> '\n';
}