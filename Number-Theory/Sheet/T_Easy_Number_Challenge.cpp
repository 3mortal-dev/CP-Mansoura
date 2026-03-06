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

std::map<int, int> freq_prime_factorization(int n)
{
  std::map<int, int> factors;
  while (n % 2 == 0)
  {
    n /= 2;
    factors[2]++;
  }
  for (int i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      n /= i;
      factors[i]++;
    }
  }
  if (n > 1)
    factors[n]++;
  return factors;
}

ll get_num_of_divisors(int n)
{
  if (n == 0)
    return 0;
  std::map<int, int> freq_primes = freq_prime_factorization(n);
  ll res = 1;
  for (const auto &v : freq_primes)
  {
    res *= (v.second) + 1;
  }
  return res;
}

ll solve()
{
  int a, b, c, count = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= b; ++j)
      for (int k = 1; k <= c; ++k)
        count += get_num_of_divisors(i * j * k);
  cout << count;
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