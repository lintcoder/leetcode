class Queue {
public:
    // Push element x to the back of queue.
    stack<int> first, second;
    void push(int x) {
        first.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (second.empty())
        {
            while (!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }
        second.pop();
    }

    // Get the front element.
    int peek(void) {
        if (second.empty())
        {
            while (!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }
        return second.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return first.empty() && second.empty();
    }
};