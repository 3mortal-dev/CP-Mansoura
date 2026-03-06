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

vi divisors(int n)
{
  vi divs;
  if (n == 0)
    return {};
  // i * i <= n is equivelent to i <= sqrt(n) but much faster as sqrt's complextiy is O(log(n))
  for (int i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      divs.push_back(i);
      // just to make sure a number isn't duplicated e.g.(n = 16, 4 * 4 ,insert single 4 only )
      if (i * i != n)
        divs.push_back(n / i);
    }
  }
  std::sort(all(divs));
  return divs;
}

bool is_prime(int n)
{
  if (n < 2)
    return false;
  // i * i <= n is equivelent to i <= sqrt(n) but much faster as sqrt's complextiy is O(log(n))
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

vi prime_factorization(int n)
{
  vi factors;
  // 2 is the only even number in prime numbers
  // so there's no need to check 2,3,4,5,6,...
  // we want to check all odds,2 => 2,  3,5,7,9,11,13,...
  // O(sqrt(n)) => O(sqrt(n)/2) not that much but quite good
  while (n % 2 == 0)
  {
    n /= 2;
    factors.push_back(2);
  }
  for (int i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      n /= i;
      factors.push_back(i);
    }
  }
  if (n > 1)
    factors.push_back(n);
  return factors;
}
std::map<int, int> freq_prime_factorization(int n)
{
  std::map<int, int> factors;
  while (n % 2 == 0)
  {
    n /= 2;
    factors[2]++;
  }
  for (int i = 3; i * i <= n; i += 2)
  {
    while (n % i == 0)
    {
      n /= i;
      factors[i]++;
    }
  }
  if (n > 1)
    factors[n]++;
  return factors;
}

ll get_num_of_divisors(int n)
{
  if (n == 0)
    return 0;
  std::map<int, int> freq_primes = freq_prime_factorization(n);
  ll res = 1;
  for (const auto &v : freq_primes)
  {
    res *= (v.second) + 1;
  }
  return res;
}

ll m_in_n(ll n, ll m)
{
  // The idea that u can just divide n/m and get number of m BUT
  // for example 78,5 78/5 = 16
  // U calculated if one 5 is multiplied by smt
  // but what if a 5 is multiplied by another 5 ????
  // that's why you need to redivide by 5, So it will be smt like this
  // 78/5 = 15 , (78/5)/5 = 3 , ((78/5)/5)/5 = 0
  // => when u reach 0 that means u got all (5 * x) && (5 * 5 * x) && (5 * 5 * 5 * x) and so o
  ll res = 0;
  while (n >= m)
  {
    res += n / m;
    n /= m;
  }
  return res;
}

// The idea beyond sieve is that u can have all prime numbers in O(n * log(log(n))) and then answer whatever queries u want
// u r testing all numbers from 0 -> n if it is prime u mark all its multiples false
// u r taking O(n) in the first loop and the second one is -> (n/i) -> (n/2, n/3, n/5, ...) for all prime i that takes log(log(n))
std::vector<bool> sieve_vector;
void sieve(int n)
{
  sieve_vector.resize(n + 1, true);
  sieve_vector[0] = sieve_vector[1] = false;

  for (int i = 2; i <= n; ++i)
  {
    if (sieve_vector[i])
      for (int j = i * i; j <= n; j += i)
        sieve_vector[j] = false;
  }
}

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

int main()
{
  linear_sieve(40);

  for (int i = 0; i < 41; ++i)
    std::cout << sieve_vector[i] << endl;
  return 0;
}