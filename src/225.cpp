class Stack {
    private:
        deque<int> dq[2];
        int flag = 0;
        int topelem;
        int size = 0;
public:
    // Push element x onto stack.
    void push(int x) {
        dq[flag].push_back(x);
        topelem = x;
        ++size;
    }

    // Removes the element on top of the stack.
    void pop() {
        if (size > 0)
        {
            int i = 1;
            while (i < size - 1)
            {
                dq[1 - flag].push_back(dq[flag].front());
                dq[flag].pop_front();
                ++i;
            }
            if (i == size - 1)
            {
                int val = dq[flag].front();
                dq[1 - flag].push_back(val);
                dq[flag].pop_front();
                topelem = val;
            }
            dq[flag].pop_front();
            
            flag = 1 - flag;
            --size;
        }
    }

    // Get the top element.
    int top() {
        return topelem;
    }

    // Return whether the stack is empty.
    bool empty() {
        return size == 0;
    }
};