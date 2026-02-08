#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;

bool solve()
{
  string a;
  stack<char> st;
  cin >> a;
  if (a.size() % 2 == 1)
    return false;
  for (int i = 0; i < a.size() / 2; ++i)
  {
    st.emplace(a[i]);
  }
  int half = a.size() / 2;
  for (int i = half; i < a.size(); ++i)
  {
    if (st.top() == '(' && a[i] == ')')
    {
      st.pop();
      continue;
    }
    else if (st.top() == ')' && a[i] == '(')
    {
      st.pop();
      continue;
    }
    return false;
  }
  return true;
}

int main()
{
  cout << "\033[48;5;17m\033[97m   \033[0m" << endl;

  return 0;
}