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

ll target;

bool func(ll val)
{
  if (val == target)
    return 1;
  if (val % 3 != 0)
    return 0;
  return func(val / 3) || func((2 * val) / 3);
}

ll solve()
{
  si s;
  int val;
  std::cin >> val >> target;
  if (func(val))
    yes;
  else
    no;
  return 0;
  // ====================== TLE ======================
  // if (val == target)
  // {
  //   yes;
  //   return 0;
  // }
  // s.emplace(val);
  // int iterations = 0;
  // const int max_iterations = 100000;
  // while (iterations++ < max_iterations)
  // {
  //   if (s.find(target) != s.end())
  //   {
  //     yes;
  //     return 0;
  //   }

  //   bool flag = 0;
  //   for (auto it = s.begin(); it != s.end(); ++it)
  //   {
  //     if (*it % 3 == 0)
  //     {
  //       flag = 1;
  //       ll temp = *it / 3;
  //       s.erase(it);
  //       s.emplace(temp);
  //       s.emplace(temp * 2);
  //       break;
  //     }
  //   }
  //   if (flag == 0)
  //   {
  //     no;
  //     return 0;
  //   }
  // }
  // no;
  // return 0;
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