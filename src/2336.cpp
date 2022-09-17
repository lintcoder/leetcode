class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for(int i = 0; i < 1001; ++i)
            arr[i] = 1;
        curSmallest = 1;
    }
    
    int popSmallest() {
        int rt = curSmallest;
        arr[curSmallest] = 0;
        for(int i = rt+1; i <= 1000; ++i)
        {
            if(arr[i] == 1)
            {
                curSmallest = i;
                break;
            }
        }
        
        return rt;
    }
    
    void addBack(int num) {
        if(num <= 1000 && arr[num] == 0)
        {
            arr[num] = 1;
            if(num < curSmallest)
                curSmallest = num;
        }
    }
private:
    int arr[1001];
    int curSmallest;
};