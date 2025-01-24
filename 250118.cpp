/*
  P11399
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
  int n ;
  cin >> n ; 
  vector<int> a(n,0);
  vector<int> s(n,0);

  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
  }

  for(int i = 1; i < n; i++)
  {
    int ip = i ;
    int iv = a[i];
    for(int j = i-1 ; j >= 0 ; j--)
    {
      if(a[j] < a[i])
      {
        ip = j + 1;
        break;
      }
      if ( j == 0 )
      {
        ip = 0;
      }
    }
    for(int j = i; j > ip ; j--)
    {
      a[j] = a[j-1];
    }
    a[ip] = iv;
  }
  s[0] = a[0];

  for(int i = 1; i < n ; i++)
  {
    s[i] = s[i-1] + a[i];
  }

  int sum = 0 ;

  for(int i = 0; i < n ; i++)
  {
    sum = sum + s[i];
  }

  cout << sum;

}