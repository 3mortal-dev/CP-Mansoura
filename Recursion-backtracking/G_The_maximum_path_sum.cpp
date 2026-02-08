#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

int n, m;
ll sum = INT32_MIN;
bool not_visited = false;

void rec(std::vector<vi> &maze, const ll current_sum, const int curr_i, const int curr_j)
{
  if (curr_i == n - 1 && curr_j == m - 1)
  {
    sum = std::max(sum, current_sum + maze[curr_i][curr_j]);
    return;
  }

  if (curr_i >= n || curr_j >= m)
    return;

  rec(maze, current_sum + maze[curr_i][curr_j], curr_i + 1, curr_j);
  rec(maze, current_sum + maze[curr_i][curr_j], curr_i, curr_j + 1);
}

ll solve()
{
  std::cin >> n >> m;
  std::vector<vi> maze(n, vi(m));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      std::cin >> maze[i][j];
    }
  }
  rec(maze, 0, 0, 0);
  std::cout << sum;
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  // cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}