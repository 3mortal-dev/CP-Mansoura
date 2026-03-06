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

std::vector<bool> linear_sieve_vector;
vi primes;
void linear_sieve(int n)
{
  linear_sieve_vector.resize(n + 1, true);
  linear_sieve_vector[0] = linear_sieve_vector[1] = false;

  for (int i = 2; i <= n; ++i)
  {
    if (linear_sieve_vector[i])
      primes.push_back(i);
    for (int j = 0; j < primes.size(); ++j)
    {
      if (primes[j] * i > n)
        break;

      linear_sieve_vector[primes[j] * i] = false;

      if (i % primes[j] == 0)
        break;
    }
  }
}

int increases(vi vec)
{
  int count = 0;
  for (auto &&v : vec)
  {
    if (!linear_sieve_vector[v])
    {
      count += *upper_bound(all(primes), v) - v;
    }
  }
  return count;
}

ll solve()
{
  linear_sieve(10e5 + 5);
  int n, m, mini = INT32_MAX;
  cin >> n >> m;
  vi temp;
  vector<vi> mat(n, vi(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> mat[i][j];
  for (auto row : mat)
    mini = min(increases(row), mini);
  for (int j = 0; j < m; ++j)
  {
    for (int i = 0; i < n; ++i)
    {
      temp.push_back(mat[i][j]);
    }
    mini = min(increases(temp), mini);
    temp.clear();
  }
  cout << mini;
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