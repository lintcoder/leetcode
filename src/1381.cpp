class CustomStack {
public:
    CustomStack(int maxSize) {
        maxCap = maxSize;
        curSz = 0;
        dq.assign(maxCap, -1);
    }
    
    void push(int x) {
        if (curSz < maxCap)
        {
            dq[curSz++] = x;
        }
    }
    
    int pop() {
        if (curSz > 0)
        {
            --curSz;
            return dq[curSz];
        }
        else
            return -1;
    }
    
    void increment(int k, int val) {
        if (curSz < k)
            k = curSz;
        for (int i = 0; i < k; ++i)
            dq[i] += val;
    }
private:
    deque<int> dq;
    int maxCap;
    int curSz;
};