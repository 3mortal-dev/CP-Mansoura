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

int prime_factorization(ll n)
{
  vi factors;
  while (n % 2 == 0)
  {
    n /= 2;
    factors.push_back(2);
  }
  for (ll i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      n /= i;
      factors.push_back(i);
    }
  }
  if (n > 1)
    factors.push_back(n);
  return factors.size();
}

ll solve()
{
  vi pre(1e6 + 5);
  for (int i = 1; i <= 1e6; ++i)
    pre[i] += prime_factorization(i) + pre[i - 1];
  int n;
  while (cin >> n)
    cout << pre[n] << '\n';
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