#include <iostream>
using namespace std;

template <typename T>
class Stack
{
public:
  Stack(int capacity)
  {
    size = 0;
    arr = new T[capacity];
  }

  ~Stack()
  {
    delete[] arr;
  }

  void push(T num)
  {
    arr[size++] = num;
  }

  void pop()
  {
    size--;
  }

  T top()
  {
    return arr[size - 1];
  }

private:
  int size;
  T *arr;
};

int main()
{
  Stack<int> s(10);
  s.push(2);
  s.push(5);
  s.push(21);
  s.pop();
  int x = s.top();
  cout << x << endl;
}