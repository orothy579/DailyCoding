#include <iostream>
#include <vector>

using namespace std;

static int n, e;
// clang-format off
static vector<vector<int> > a;
// clang-format on
static bool arrive = false;
static vector<bool> visited;
void dfs(int now, int depth);

int main(int argc, char **argv)
{
  cin >> n >> e;
  a.resize(n);
  visited = vector<bool>(n, false);

  // undirected linked-list에 그래프 데이터 저장
  for (int i = 0; i < e; i++)
  {
    int e1, e2;
    cin >> e1 >> e2;
    a[e1].push_back(e2);
    a[e2].push_back(e1);
  }

  for (int i = 0; i < n; i++)
  {
    dfs(i, 1);
    if (arrive)
    {
      break;
    }
  }
  cout << (arrive ? "1" : "0") << '\n';
}

void dfs(int now, int depth)
{
  if (depth == 5 || arrive)
  {
    arrive = true;
    return;
  }
  visited[now] = true;

  // a[now]에 있는 원소들을 하나씩 i에 넣어서 반복해라
  for (int i : a[now])
  {
    if (!visited[i])
    {
      dfs(i, depth + 1);
    }
  }
  visited[now] = false;
}