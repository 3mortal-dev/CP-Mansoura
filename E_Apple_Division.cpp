
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define ll long long
#define fast_io                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr)
#define vi std::vector<ll>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

using namespace std;

vector<int> nums;
int n;
ll diff = INT64_MAX;

void repeat(int i, ll sumA, ll sumB)
{
  if (i == n)
  {
    diff = min(diff, llabs(sumA - sumB));
    return;
  }
  repeat(i + 1, sumA + nums[i], sumB);
  repeat(i + 1, sumA, sumB + nums[i]);
}

ll solve()
{
  cin >> n;
  nums.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  repeat(0, 0, 0);
  cout << diff << endl;

  return 0;
}

int main()
{
  fast_io;
  int testCases = 1;
  while (testCases--)
  {
    solve();
  }
  return 0;
}