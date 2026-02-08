
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

ll f(ll num)
{
  if (num == 1)
  {
    std::cout << num;
    return 1;
  }
  if (num % 2 == 0) // Even
  {
    std::cout << num << ' ';
    return f(num / 2);
  }
  else // Odd
  {
    std::cout << num << ' ';
    return f(3 * num + 1);
  }
}

void solve()
{
  int n;
  std::cin >> n;
  f(n);
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