#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static int n, e, start;
// clang-format off
static vector<vector<int> > a;
// clang-format on
static vector<bool> visited;

void dfs(int node)
{
  cout << node << " ";
  visited[node] = true;
  for (int i : a[node])
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
}

void bfs(int node)
{
  queue<int> q;
  q.push(node);
  visited[node] = true;

  while (!q.empty())
  {
    int cur_node = q.front();
    // pop 하면서 탐색 배열 출력
    q.pop();
    cout << cur_node << " ";

    // 인접 노드 큐에 삽입
    for (int i : a[cur_node])
    {
      if (!visited[i])
      {
        // 삽입 하면서 방문 배열은 true로
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main(int argc, char **argv)
{
  cin >> n >> e >> start;
  a.resize(n + 1);

  for (int i = 0; i < e; i++)
  {
    int e1, e2;
    cin >> e1 >> e2;
    a[e1].push_back(e2);
    a[e2].push_back(e1);
  }

  for (int i = 1; i <= n; i++)
  {
    sort(a[i].begin(), a[i].end());
  }

  visited = vector<bool>(n + 1, false);
  dfs(start);
  cout << "\n";

  visited = vector<bool>(n + 1, false);
  bfs(start);
}