vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        size_t len = A.size();
        vector<bool> flag(len, false);
        vector<int> res(len, 0);
        
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            if (A[i]%2 == 0)
            {
                flag[i] = true;
                sum += A[i];
            }
        }
            
        len = queries.size();
        for (int i = 0; i < len; ++i)
        {
            if (flag[queries[i][1]] == true && abs(queries[i][0])%2 == 0)
            {
                A[queries[i][1]] += queries[i][0];
                sum += queries[i][0];
                res[i] = sum;
            }
            else if (flag[queries[i][1]] == true && abs(queries[i][0])%2 == 1)
            {
                sum -= A[queries[i][1]];
                A[queries[i][1]] += queries[i][0];
                res[i] = sum;
                flag[queries[i][1]] = false;
            }
            else if (flag[queries[i][1]] == false && abs(queries[i][0])%2 == 0)
            {
                A[queries[i][1]] += queries[i][0];
                res[i] = sum;
            }
            else
            {
                A[queries[i][1]] += queries[i][0];
                sum += A[queries[i][1]];
                res[i] = sum;
                flag[queries[i][1]] = true;
            }
        }
        
        return res;
    }