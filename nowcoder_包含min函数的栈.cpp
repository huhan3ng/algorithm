#include<stack>
class Solution {
    stack<int> a;
    stack<int> b;
public:
    void push(int value) {
        a.push(value);
        if(b.empty()){
            b.push(value);
        } else {
            if(value<=b.top()){
                b.push(value);
            } else {
                b.push(b.top());
            }
        }
    }
    void pop() {
        a.pop();
        b.pop();
    }
    int top() {
        return a.top();
    }
    int min() {
        return b.top();
    }
};