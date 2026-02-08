#include <iostream>

int rec(int n)
{
  if (n <= 0)
    return 0;
  std::cout << "\nFuck u " << n; // calling phase (ascending)
  rec(n - 1);
  std::cout << n << " "; // returning phase (descending)
}

int rec1(int n)
{
  static int x = 0;
  if (n > 0)
  {
    x++;
    return rec1(n - 1) + x;
    std::cout << x << std::endl;
  }
  return 0;
}

int main()
{
  std::cout << rec1(5);
}