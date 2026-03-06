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

/*
  The core idea is :
  We can get any even number by adding 2 prime numbers ( called Goldbach's Conjecture)
  so we are seeking to fix first 2 numbers so the second 2 numbers be even when added(because we can get the second 2 numbers by the previous line)
  so for example if the number N is even -> we fix 2,2 so N-4 will even and we then search for the other 2 numbers
  if the number N is odd -> we fix 2,3 so N-5 will be even also and continue.
*/

std::vector<bool> linear_sieve_vector;
vi primes;
void linear_sieve(int n)
{
  linear_sieve_vector.resize(n + 1, true);
  linear_sieve_vector[0] = linear_sieve_vector[1] = false;

  for (int i = 2; i <= n; ++i)
  {
    if (linear_sieve_vector[i])
      primes.push_back(i);
    for (int j = 0; j < primes.size(); ++j)
    {
      if (primes[j] * i > n)
        break;

      linear_sieve_vector[primes[j] * i] = false;

      if (i % primes[j] == 0)
        break;
    }
  }
}

ll solve()
{
  linear_sieve(10e6 + 5);
  ll n = 50;
  while (cin >> n)
  {
    ll n1, n2, n3 = 0, n4 = 0;
    if (n < 8)
    {
      cout << "Impossible.\n";
      continue;
    }
    if (n % 2 == 0)
      n1 = 2, n2 = 2, n -= 4;
    else
      n1 = 2, n2 = 3, n -= 5;
    for (int i = 2; i < n; ++i)
    {
      if (linear_sieve_vector[i] && linear_sieve_vector[n - i])
      {
        n3 = i, n4 = n - i;
        break;
      }
    }
    if (n3 != 0)
      cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    else
      cout << "Impossible.";
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