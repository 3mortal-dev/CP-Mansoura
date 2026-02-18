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

bool is_prime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

ll solve()
{
  ll n;
  std::cin >> n;
  ll s = sqrtl(n);
  if (s * s != n || n < 2)
  {
    no;
    return 0;
  }
  if (!is_prime((int)s))
  {
    no;
    return 0;
  }
  yes;
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