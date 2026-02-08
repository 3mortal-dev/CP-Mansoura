#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define si std::set<ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

int trash;

int is_done(std::string s)
{
  int i = 0, sum = 0;
  for (; i < 10; ++i)
  {
    if (s[i] == '?')
      break;
    int int_s = s[i] - '0';
    sum += (i % 2 == 0) ? int_s : -1 * int_s; // instead of using to independent sums (odd,even)
  }
  if (i < 5)
    return 0;
  sum = abs(sum);
  int remaining = (9 - i + 1) / 2;
  if (remaining < sum)
    return i + 1;
  return 0;
}

void fun(std::string s)
{
  trash = std::min(trash, is_done(s));
  if (trash)
  {
    return;
  }
  for (int idx = 0; idx < s.length(); ++idx)
  {
    if (s[idx] == '?')
    {
      for (int i = 0; i <= 1; ++i)
      {
        s[idx] = '0' + i;
        fun(s);
      }
      return;
    }
  }
}

ll solve()
{
  std::string st;
  std::cin >> st;
  trash = INT16_MAX;
  fun(st);
  std::cout << trash << endl;
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