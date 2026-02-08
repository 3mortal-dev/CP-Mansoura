
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

ll modularExponentiation(ll base, ll expo)
{
  /*
  time O(n)
  space O(1) + recursion stack calls
  */
  static ll X = 1000000007;
  static ll res = 1;
  // Base case
  if (expo == 0)
    return res;
  if (expo % 2 == 1)
    res = ((base % X) * (res % X)) % X;
  base = ((base % X) * (base % X)) % X;
  expo /= 2;
  return modularExponentiation(base, expo);
}

void solve()
{
  // ll n, m;
  // std::cin >> n >> m;
  // std::cout << ((ll)pow(n % X, m) % X);
  /*
    Correct logic but ll won't fit.
    Because, if n = 1 billion the first term will be 1 billion and u still didn't touch m.
    Suppose m is another 1 billion. How the f*** any data type will store that shit ??
  */
  ll n, m;
  std::cin >> n >> m;
  std::cout << modularExponentiation(n, m);
}

int main()
{
  fast_io;

  int testCases = 1;
  // cin >> testCases;
  while (testCases--)
  {
    solve();
  }
  return 0;
}