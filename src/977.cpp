vector<int> sortedSquares(vector<int>& A) {
        auto cmp = [](int a, int b) {
            return abs(a) < abs(b);
        };
        
        sort(A.begin(), A.end(), cmp);
        transform(A.begin(), A.end(), A.begin(), [](int n) {return n*n;});
        return A;
    }