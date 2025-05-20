#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

static int n;
// clang-format off
static vector<vector<pair<int, int> > > a;
// clang-format on
static vector<bool> visited;
static vector<int> dist_vec;

void bfs(int node)
{
  queue<int> q;
  q.push(node);
  visited[node] = true;

  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    for (pair<int, int> i : a[now])
    {
      if (!visited[i.first])
      {
        visited[i.first] = true;
        q.push(i.first);
        dist_vec[i.first] = dist_vec[now] + i.second;
      }
    }
  }
}

int main(int argc, char **argv)
{
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    int node;
    cin >> node;
    pair<int, int> e;
    while (true)
    {
      cin >> e.first;
      if (e.first == -1)
      {
        break;
      }
      cin >> e.second;
      a[node].push_back(e);
    }
  }

  visited = vector<bool>(n + 1, false);
  dist_vec = vector<int>(n + 1, 0);

  bfs(1);

  int max = 1;

  for (int i = 2; i <= n; i++)
  {
    if (dist_vec[max] < dist_vec[i])
    {
      max = i;
    }
  }

  visited = vector<bool>(n + 1, false);
  dist_vec = vector<int>(n + 1, 0);

  bfs(max);
  sort(dist_vec.begin(), dist_vec.end());
  cout << dist_vec[n] << '\n';
}