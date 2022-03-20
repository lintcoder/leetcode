vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        
        for (int i = 0; i < m; ++i)
        {
            int col = m-1-i;
            int j = n-1, k = n-1, idx = n;
            bool flag = false;
            while (j >= 0)
            {
                if (box[i][j] == '.')
                {
                    if (!flag)
                    {
                        idx = j;
                        flag = true;
                    }
                }
                else if (box[i][j] == '*')
                {
                    idx = n;
                    flag = false;
                    res[k][col] = '*';
                }
                else
                {
                    if (idx != n)
                    {
                        res[idx][col] = '#';
                        --idx;
                    }
                    else
                        res[k][col] = '#';
                }
                --j;
                --k;
            }
        }
        
        return res;
    }