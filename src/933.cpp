class RecentCounter {
public:
    RecentCounter() {
        memset(calls, 0, sizeof(int)*10000);
        pos = -1;
    }
    
    int ping(int t) {
        int i;
        for (i = 0; i <= pos; ++i)
        {
            if (calls[i] >= t-3000 && calls[i] <= t)
            {
                break;
            }
        }
        
        calls[pos+1] = t;
        ++pos;
        return pos-i+1;
    }
    
    int calls[10000];
    int pos;
};