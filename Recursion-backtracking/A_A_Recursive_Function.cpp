#include <bits/stdc++.h>

int f(int num)
{
  if (num == 0 || num == 1)
    return 1;
  return num * f(num - 1);
}

void solve()
{
  int n;
  std::cin >> n;
  std::cout << f(n);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int testCases = 1;
  // cin >> testCases;
  while (testCases--)
  {
    solve();
  }

  return 0;
}