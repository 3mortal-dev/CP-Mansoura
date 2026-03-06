#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr);            \
  std::cout.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"
#define endl '\n'
using namespace std;

vi prime_factorization(ll n)
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
  return factors;
}

ll solve()
{
  ll n;
  cin >> n;
  vi a = prime_factorization(n);
  if (a.size() == 2)
  {
    cout << 2;
    return 0;
  }
  else if (a.size() <= 1)
  {
    cout << 1 << endl
         << 0;
  }
  else
  {
    cout << 1 << endl
         << a[0] * a[1];
  }
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