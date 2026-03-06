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

bool is_prime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

ll solve()
{
  // We can solve with 2 numbers only btw
  int n;
  cin >> n;
  if (n < 3)
  {
    cout << 1 << endl;
    while (n--)
      cout << 1 << " ";
    return 0;
  }
  cout << 2 << endl;
  for (int i = 1; i <= n; ++i)
  {
    if (is_prime(i + 1))
      cout << 2 << " ";
    else
      cout << 1 << " ";
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