/*
  P11720
*/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  int n = 0;
  int sum = 0;
  string numbers;
  cin >> n;
  cin >> numbers;


  for(int i = 0 ; i < n ; i++)
  {
    sum += numbers[i] - 48; // string 에 하나씩 접근해, 숫자로 더해줌. why? 각 인덱스 별로 접근하면 char형이고, 이는 문자이기 때문에 48씩 뺴줘야 함.
  }

  cout << sum ;

}
