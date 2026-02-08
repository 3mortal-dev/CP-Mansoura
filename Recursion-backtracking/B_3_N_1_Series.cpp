
#include <bits/stdc++.h>

int f(int num)
{
  static int x = 0; // Same as a global variable
  x++;
  if (num == 1)
  {
    std::cout << x;
    return 1;
  }
  if (num % 2 == 0) // Even
  {
    return f(num / 2);
  }
  else // Odd
  {
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