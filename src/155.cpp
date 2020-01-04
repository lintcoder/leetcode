class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        len = 0;
    }
    
    void push(int x) {
        st.push_back(x);
        ++len;
        if (len == 1)
            minval = x;
        else
            minval = x < minval ? x : minval;
    }
    
    void pop() {
        if (len > 0)
        {
            --len;
            st.erase(--st.end());
            if (len > 0)
            {
                auto lim = st.end();
                int t = *st.begin();
                for (auto iter = st.begin(); iter != lim; ++iter)
                    if (*iter < t)
                        t = *iter;
                minval = t;
            }
        }
    }
    
    int top() {
        if (len > 0)
            return st.back();
        else
            return 0;
    }
    
    int getMin() {
        if (len > 0)
            return minval;
        else
            return 0;
    }
    
    list<int> st;
    int minval;
    int len;
};