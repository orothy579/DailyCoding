/*
  P2750
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int& n1, int& n2)
{
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

int main(int argc, char* argv[])
{
  int n;
  vector<int> numbers;

  cin >> n;

  for(int i = 0 ; i < n ; i++)
  {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }

  for (int i = 0 ; i < n-1 ; i++)
  {
    for ( int j = 0 ; j < n-1 ; j ++)
    {
      if(numbers[j] > numbers[j+1]) swap(numbers[j] , numbers[j+1]);
    }
  }

  for(int i = 0 ; i < n ; i++)
  {
    cout << numbers[i] << endl;
  }
  
}