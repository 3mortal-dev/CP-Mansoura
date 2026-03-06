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

ll solve()
{
  int n;
  cin >> n;
  if (n <= 3)
  {
    cout << "Ordinary Number\n";
    return 0;
  }
  ll even = 0, odd = 0;
  std::map<int, int> freq_primes = freq_prime_factorization(n);
  for (const auto &v : freq_primes)
  {
    if (v.second % 2 == 0)
      even++;
    else
      odd++;
  }
  if (even > odd)
    cout << "Psycho Number\n";
  else
    cout << "Ordinary Number\n";
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