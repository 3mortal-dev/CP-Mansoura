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

ll divisors(int n)
{
  ll sum = 0;
  for (int i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      sum += i;
      if (i * i != n)
        sum += (n / i);
    }
  }
  return sum;
}

ll solve()
{
  int n;
  std::cin >> n;
  std::cout << divisors(n) - n << endl;
  return 0;
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