#include <iostream>
#include <vector>

using namespace std;

// clang-format off
static vector<vector<int> > linked_list;
// clang-format on
static vector<bool> visited;
void DFS(int v);

int main(int argc, char **argv)
{
  int n, e;

  cin >> n >> e;
  linked_list.resize(n + 1);
  visited = vector<bool>(n + 1, false);

  for (int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    linked_list[u].push_back(v);
    linked_list[v].push_back(u);
  }

  int count = 0;

  for (int i = 1; i < n + 1; i++)
  {
    if (!visited[i])
    {
      count++;
      DFS(i);
    }
  }
  cout << count << "\n";
}

void DFS(int v)
{
  if (visited[v])
  {
    return;
  }

  visited[v] = true;

  for (int i : linked_list[v])
  {
    if (visited[i] == false)
    {
      DFS(i);
    }
  }
}