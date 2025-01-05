#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int mat_size, query;

  cin >> mat_size >> query;

  vector<vector<int>> matrix(mat_size, vector<int>(mat_size, 0));

  for(int i = 0 ; i < mat_size ; i ++)
  {
    for(int j = 0 ; j < mat_size ; j ++)
    {
      cin >> matrix[i][j] ;
    }
  }




}