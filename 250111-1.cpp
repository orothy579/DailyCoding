/*
  P1427
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  // string 으로 입력 받음 --> int로 입력 받으면 자릿수 나누기 곤란함
  string str;

  cin >> str;

  vector<int> A(str.size(), 0);

  // int로 바꿔줌
  for(int i = 0; i < str.size(); i++)
  {
    A[i] = stoi(str.substr(i,1));
  }

  for(int i = 0; i < str.size(); i++)
  {
    int max = i; // max는 index로 찾아 갈 것임
    for (int j = i + 1; i < str.size(); i++)
    {
      if(A[max] < A[j]) max = j; // i 이후부터 i보다 더 큰 녀석 있으면 그 녀석이 max
    }

    // index i 랑 max랑 swap
    int temp = A[max];
    A[max] = A[i];
    A[i] = A[max];
  }
}
