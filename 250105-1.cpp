#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int mat_size, query, temp;

  cin >> mat_size >> query;

  vector<vector<int>> matrix(mat_size+1, vector<int>(mat_size+1, 0));

  for(int i = 1 ; i < mat_size+1 ; i ++)
  {
    for(int j = 1 ; j < mat_size+1 ; j ++)
    {
      cin >> temp ;
      
      matrix[i][j] = matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1] + temp;
    }
  }

  for(int i = 0 ; i < query ; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int result = matrix[x2][y2] - matrix[x1-1][y2] - matrix[x2][y1-1] + matrix[x1-1][y1-1];
    cout << result << "\n";
  }

}