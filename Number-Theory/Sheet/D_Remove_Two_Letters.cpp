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
using namespace std;

ll solve()
{
  int n, count = 1;
  string st;
  cin >> n >> st;
  for (int i = 1; i < n - 1; ++i)
  {
    if (st[i - 1] == st[i + 1])
      continue;
    count++;
  }
  cout << count << endl;
}

int main()
{
  fast_io;

  int testCases = 1;
  std::cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}