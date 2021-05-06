//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.emplace_back(INT_MAX);
    }

    void push(int val) {
        stack.emplace_back(val);
        minStack.emplace_back(min(val, *minStack.rbegin()));
    }

    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }

    int top() {
        return *(stack.rbegin());
    }

    int getMin() {
        return *(minStack.rbegin());
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
