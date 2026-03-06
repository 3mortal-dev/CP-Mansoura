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
  int n;
  cin >> n;
  // 10000th prime is 104,729
  linear_sieve(104729 + 100);
  cout << primes[n - 1] << endl;
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