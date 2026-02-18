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

vector<bool> is_prime;
void sieve(int n)
{
  is_prime.resize(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i)
  {
    if (is_prime[i])
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
  }
}

ll solve()
{
  int n;
  cin >> n;
  sieve(n);
  cout << (is_prime[n] ? "YES\n" : "NO\n");
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