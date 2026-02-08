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

ll n, mini, maxi, diff, solu = 0;
std::vector<ll> nums, sol;

void func(ll curr_min, ll curr_max, ll curr_sum, ll place_holder, ll count)
{
  static auto is_valid = [&](ll curr_min, ll curr_max, ll curr_sum, ll count)
  {
    return (curr_sum <= maxi) && (curr_sum >= mini) && (curr_max - curr_min >= diff) && (count >= 2);
  };

  // Base case

  if (is_valid(curr_min, curr_max, curr_sum, count))
  {
    solu++;

    // for (const auto &v : sol)
    //   std::cout << v << " ";
    // std::cout << endl;
  }

  else if (curr_sum > maxi)
    return;

  // Backtrack state
  for (int i = place_holder; i < n; i++)
  {
    count++;
    func(std::min(curr_min, nums[i]), std::max(curr_max, nums[i]), curr_sum + nums[i], i + 1, count + 1);
  }
}

ll solve()
{
  std::cin >> n >> mini >> maxi >> diff;
  nums.resize(n);
  for (int i = 0; i < n; ++i)
    std::cin >> nums[i];
  func(INT32_MAX, 0, 0, 0, 0);
  std::cout << solu;
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