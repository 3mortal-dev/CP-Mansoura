#include <bits/stdc++.h>

const int n = 5;
int x[n + 1];

bool isValid(int row, int col)
{
  for (int i = 1; i < row; i++)
  {
    if (x[i] == col || i - x[i] == row - col /*diagonal*/ || i + x[i] == row + col /*off-diagonal*/)
      return false;
  }
  return true;
}

void N_Queens(int k)
{
  for (int i = 1; i <= n; i++)
  {
    if (isValid(k, i))
    {
      x[k] = i;

      if (n == k)
      {
        for (int i = 1; i <= n; i++)
        {
          std::cout << x[i];
        }
        std::cout << "\n";
        return;
      }

      N_Queens(k + 1);
      x[k] = 0;
    }
  }
}

int main()
{
  N_Queens(1);
}