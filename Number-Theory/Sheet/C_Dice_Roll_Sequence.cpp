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

int mini = INT32_MAX;

int is_seq(const vi &arr)
{
  for (int i = 0; i < arr.size() - 1; ++i)
  {
    if (arr[i] + arr[i + 1] == 7 || arr[i] == arr[i + 1])
      return i;
  }
  return -1;
}

void func(vi arr, int t)
{
  if (t >= mini)
    return;
  int val = is_seq(arr);
  if (val == -1)
  {
    mini = std::min(mini, t);
    return;
  }
  int temp = arr[val];
  for (int i = 1; i <= 6; ++i)
  {
    if (arr[val] == i)
      continue;
    arr[val] = i;
    func(arr, t + 1);
  }
  arr[val] = temp;
}

ll solve()
{
  int n;
  std::cin >> n;
  vi arr(n);
  for (int i = 0; i < n; ++i)
    std::cin >> arr[i];
  func(arr, 0);
  std::cout << mini << endl;
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  std::cin >> testCases;
  while (testCases--)
  {
    mini = INT32_MAX;
    solve();
  }
  return 0;
}