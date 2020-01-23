vector<string> generateParenthesis(int n) {
        if (n <= 0)
            return {};
        
        vector<string> res;
        string s;
        generate(s, 0, 0, n, res);
        
        return res;
    }
    
    void generate(const string& s, int left, int right, int n, vector<string>& res)
    {
        if (left == n && right == n)
            res.push_back(s);
        else
        {
            if (left < n)
            {
                string tmp(s);
                tmp.push_back('(');
                generate(tmp, left+1, right, n, res);
            }
            if (left > right)
            {
                string tmp(s);
                tmp.push_back(')');
                generate(tmp, left, right+1, n, res);
            }
        }
    }