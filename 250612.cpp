#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
  vector<string> result;
  stringstream mystream(input);
  string splitdata;

  while (getline(mystream, splitdata, delimiter))
  {
    result.push_back(splidata);
  }
  return result;
}

int mySum(string a)
{
  int sum = 0;
  vector<string> tmp = split(a, '+');

  for (int i = 0; i < tmp.size(); i++)
  {
    sum += stoi(tmp[i]);
  }

  return sum;
}

int main(int argc, char **argv)
{
  int ans = 0;
  vector<string> input;
  cin >> input;
  vector<string> str = split(input, '-');
  int tmp = mySum(str[i]);

  for (int i = 0; i < str.size(); i++)
  {
    if (i == 0)
    {
      ans += tmp;
    }
    else
    {
      ans -= tmp;
    }
  }
  cout << ans << "\n";
}