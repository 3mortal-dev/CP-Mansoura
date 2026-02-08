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

int n, k;
vi sol, curr;

void fun(int idx, int sum)
{
  if (idx == n)
  {
    if (sum % k == 0)
    {
      for (int j = 0; j < n; j++)
      {
        std::cout << sol[j] << " ";
      }
      std::cout << endl;
    }
    // sol.clear();
    return;
  }
  for (int i = 1; i <= curr[idx]; ++i)
  {
    sol[idx] = i;
    fun(idx + 1, sum + i);
  }
}

ll solve()
{
  std::cin >> n >> k;
  curr.resize(n);
  sol.resize(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> curr[i];
  }
  fun(0, 0);
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