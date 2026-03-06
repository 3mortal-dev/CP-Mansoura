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

bool is_beautiful(ll n)
{
  int k = 0;
  while (n >= pow(2, k + 1))
  {
    k++;
  }
  int l = 0;
  while (n - pow(2, k) >= 0)
  {
    n -= pow(2, k);
    k--, l++;
  }
  return (l - k == 2) && (n == 0);
}

vi divisors(int n)
{
  vi divs;
  if (n == 0)
    return {};
  for (int i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      divs.push_back(i);
      if (i * i != n)
        divs.push_back(n / i);
    }
  }
  std::sort(all(divs), greater<int>());
  return divs;
}

ll solve()
{
  ll n;
  cin >> n;
  vi divs = divisors(n);
  for (auto v : divs)
  {
    if (is_beautiful(v))
    {
      cout << v;
      return 0;
    }
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