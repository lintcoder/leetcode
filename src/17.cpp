vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> res;
        if (len == 0)
            return res;
        string dict[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int num[10] = {0,0,3,3,3,3,3,4,3,4};
        
        string s;
        search(digits, 0, len, dict, num, s, res);
        
        return move(res);
    }
    
    void search(const string& digits, int ct, int len, const string* dict, const int* num, string s, vector<string>& res)
    {
        if (ct < len)
        {
            int index = digits[ct]-'0';
            int n = num[index];
            for (int i = 0; i < n; ++i)
                search(digits, ct+1, len, dict, num, s+dict[index][i], res);
        }
        else
            res.push_back(s);
    }