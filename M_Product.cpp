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

int n_bags, times;
ll x;
std::vector<std::vector<int>> bags;
std::vector<int> sol;

void func(int bag_id)
{
  // Just to catch it before it overfits long long
  static auto is_valid = [](std::vector<int> s, ll x_val)
  {
    ll res = 1;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
      if (res > x_val)
        return false;
      res *= s[i];
    }
    return (res == x_val);
  };
  // base case
  if (sol.size() == n_bags)
  {
    if (is_valid(sol, x))
      times++;
    return;
  }
  // backtrack state
  for (int j = 0; j < bags[bag_id].size(); ++j)
  {
    sol.push_back(bags[bag_id][j]);
    func(bag_id + 1);
    sol.pop_back();
  }
}

ll solve()
{
  int bag_size;
  std::cin >> n_bags >> x;
  bags.resize(n_bags);
  for (int i = 0; i < n_bags; ++i)
  {
    std::cin >> bag_size;
    bags[i].resize(bag_size);
    for (int j = 0; j < bag_size; ++j)
      std::cin >> bags[i][j];
  }
  func(0);
  std::cout << times;
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