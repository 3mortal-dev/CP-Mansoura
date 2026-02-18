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

si prime_factorization(int n)
{
  si factors;
  while (n % 2 == 0)
  {
    n /= 2;
    factors.emplace(2);
  }
  for (int i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      n /= i;
      factors.emplace(i);
    }
  }
  if (n > 1)
    factors.emplace(n);
  return factors;
}

ll solve()
{
  int n, count = 0;
  std::cin >> n;
  for (int i = 6; i <= n; ++i)
  {
    if (prime_factorization(i).size() == 2)
      count++;
  }
  std::cout << count;
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