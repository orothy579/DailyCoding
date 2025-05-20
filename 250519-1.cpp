#include <iostream>
#include <queue>

using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int a[101][101]; // 1 ~ 100
static int n, m;
static bool visited[101][101] = {false};

void bfs(int i, int j)
{
  // clang-format off
  queue<pair<int, int> > q;
  // clang-format on
  q.push(make_pair(i, j));

  while (!q.empty())
  {
    int now[2];
    now[0] = q.front().first;
    now[1] = q.front().second;
    q.pop();
    visited[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
      int x = now[0] + dx[k];
      int y = now[1] + dy[k];

      if (x >= 1 && y >= 1 && x <= n && y <= m)
      {
        if (a[x][y] != 0 && !visited[x][y])
        {
          visited[x][y] = true;
          a[x][y] = a[now[0]][now[1]] + 1;
          q.push(make_pair(x, y));
        }
      }
    }
  }
}

int main(int argc, char **argv)
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
    {
      a[i][j] = s[j - 1] - '0';
    }
  }
  bfs(1, 1);
  cout << a[n][m] << endl;
}