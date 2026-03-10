#include <iostream>
#include <vector>
using namespace std;
class MinStack {
private:
  int *stack;
  int *minStack;
  int head;
  static const int MAX_N = 3e4;

public:
  MinStack() {
    stack = new int[MAX_N];
    minStack = new int[MAX_N];
    head = 0;
  }

  void push(int val) {
    stack[head] = val;
    minStack[head] = head == 0 ? val : min(minStack[head - 1], val);
    head++;
  }

  void pop() {
    if (head > 0) head--;
  }

  int top() {
    return head > 0 ? stack[head - 1] : NULL;
  }

  int getMin() {
    return head > 0 ? minStack[head - 1] : NULL;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */