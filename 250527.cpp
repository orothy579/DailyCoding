#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv)
{
  int n;
  cin >> n;
  priority_queue<int> plusPq;

  // clang-format off
  priority_queue<int, vector<int>, greater<int> > minusPq;
  // clang-format on
  int one = 0, zero = 0;

  for (int i = 0; i < n; i++)
  {
    int data;
    cin >> data;

    if (data > 1)
    {
      plusPq.push(data);
    }
    else if (data == 1)
    {
      one++;
    }
    else if (data == 0)
    {
      zero++;
    }
    else
    {
      minusPq.push(data);
    }
  }

  int sum = 0;

  while (plusPq.size() > 1)
  {
    int first = plusPq.top();
    plusPq.pop();
    int second = plusPq.top();
    plusPq.pop();
    sum += first * second;
  }

  if (!plusPq.empty())
  {
    sum += plusPq.top();
    plusPq.pop();
  }

  while (minusPq.size() > 1)
  {
    int first = minusPq.top();
    minusPq.pop();
    int second = minusPq.top();
    minusPq.pop();
    sum += first * second;
  }

  if (!minusPq.empty())
  {
    if (zero == 0)
    {
      sum += minusPq.top();
      minusPq.pop();
    }
  }

  sum += one;
  cout << sum << '\n';
}
