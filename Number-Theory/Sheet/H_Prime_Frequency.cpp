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

ll solve(int case_num)
{
  bool flag = 0;
  string st;
  map<char, int> freq;
  cin >> st;
  cout << "Case " << case_num << ": ";
  for (auto &&ch : st)
    freq[ch]++;

  for (auto &&pair : freq)
  {
    if (is_prime(pair.second))
    {
      flag = 1;
      cout << pair.first;
    }
  }

  if (!flag)
    cout << "empty";
  return 0;
}

int main()
{
  fast_io;

  int testCases = 1;
  std::cin >> testCases;
  for (int i = 1; i <= testCases; i++)
  {
    solve(i);
    // if (i != testCases)
    cout << endl;
  }
  return 0;
}