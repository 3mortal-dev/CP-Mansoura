#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"
#define endl '\n'

ll n, m, x, mini = INT32_MAX;
vi cost;
std::vector<std::vector<ll>> xp;

void func(vi sum, const int curr_row, const ll curr_cost)
{
  auto is_valid = [&](vi sum)
  {
    for (int i = 0; i < m; ++i)
      if (sum[i] < x)
        return 0;
    return 1;
  };
  if (is_valid(sum))
  {
    mini = std::min(mini, curr_cost);
    return;
  }
  for (int i = curr_row; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      sum[j] += xp[i][j];
    func(sum, i + 1, curr_cost + cost[i]);
    for (int j = 0; j < m; ++j)
      sum[j] -= xp[i][j];
  }
}

ll solve()
{
  std::cin >> n >> m >> x;
  vi test(m, 0);
  cost.resize(n);
  xp.resize(n, vi(m));
  for (int i = 0; i < n; ++i)
  {
    std::cin >> cost[i];
    for (int j = 0; j < m; ++j)
      std::cin >> xp[i][j];
  }
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
      test[i] += xp[j][i];
    if (test[i] < x)
    {
      std::cout << -1;
      return 0;
    }
  }
  func(vi(m, 0), 0, 0);
  std::cout << mini;
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  // std::cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}