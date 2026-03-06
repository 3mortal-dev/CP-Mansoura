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

std::vector<bool> sieve_vector;
void sieve(int n)
{
  sieve_vector.assign(n + 1, true);
  sieve_vector[0] = sieve_vector[1] = false;

  for (ll i = 2; i * i <= n; ++i)
  {
    if (sieve_vector[i])
      for (ll j = i * i; j <= n; j += i)
        sieve_vector[j] = false;
  }
  int counter = 0;
  for (ll i = 2; i <= n; ++i)
  {
    if (sieve_vector[i])
    {
      counter++;
      if (counter % 100 == 1)
        std::cout << i << '\n';
    }
  }
}

ll solve()
{
  sieve(1e8);
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