#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> a; // 약수를 저장할 벡터

  // 1부터 n까지 반복하여 약수 찾기
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    { // i가 n의 약수이면
      a.push_back(i);
    }
  }

  // k번째 약수 출력 (1-based index)
  if (k <= a.size())
  {
    cout << a[k - 1] << endl; // k번째 약수 (벡터는 0-based index)
  }
  else
  {
    cout << "0" << endl; // k번째 약수가 존재하지 않으면 0 출력
  }

  return 0;
}
