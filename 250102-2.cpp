/*
  P1546
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  int n = 0;
  long max = 0;
  long sum = 0;

  vector<int> numbers;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }

  for (int i = 0; i < n; i++)
  {
    if( max < numbers[i] ) max = numbers[i];
    sum += numbers[i];
  }

  double result = sum * 100.0 / max / n;
  cout << result << endl;

}