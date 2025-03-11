#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int n, k;
  cin >> n >> k;
  vector<int> a;

  // n / i
  for (int i = 1; i < n; i++)
  {
    if (n / i == 0)
    {
      a.push_back(i);
    }
    // i를 기억하기, i가 곧 약수
    // vector의 인덱스 1부터에 i를 push
    // vector[k] 미존재시 0출력
  }
}