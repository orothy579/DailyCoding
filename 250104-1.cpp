#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int data, query, i , j;
  vector<int> datas;
  vector<int> S; // 부분합 저장

  S.push_back(0);

  cin >> data >> query;

  for ( int i = 0; i < data; i++ )
  {
    int temp = 0;
    cin >> temp;
    S.push_back(S[i] + temp);
  }

  for( int k  = 0 ; k < query ; k ++ )
  {
    cin >> i >> j;
    cout << S[j] - S[i-1] << endl;
  }

}