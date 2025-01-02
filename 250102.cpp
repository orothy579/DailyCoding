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
    sum += numbers[i] - 48;
  }

  cout << sum ;

}
