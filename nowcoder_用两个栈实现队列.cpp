class Solution
{
public:
	void push(int node) {
		if (stack1.size() == 0) {
			while (stack2.size() > 0) {
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		stack1.push(node);
	}

	int pop() {
		if (stack2.size() == 0) {
			while (stack1.size()>0)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()) {
			return 0;
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
