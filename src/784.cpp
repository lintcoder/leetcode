vector<string> letterCasePermutation(string S) {
        vector<string> res;
        vector<int> letterpos;

        int len = S.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
        	if (isalpha(S[i]))
        	{
        		letterpos.push_back(i);
        		++ct;
        	}
        }
        if (ct == 0)
        {
        	res.push_back(S);
        	return res;
        }

        doPermutation(S, 1, ct, letterpos, res);

        return res;
    }

    void doPermutation(string& S, int n, int ct, const vector<int>& pos, vector<string>& res)
    {
        if (n == ct)
        {
            res.push_back(S);
            if (islower(S[pos[n-1]]))
                S[pos[n-1]] = toupper(S[pos[n-1]]);
            else
                S[pos[n-1]] = tolower(S[pos[n-1]]);
            res.push_back(S);
        }
        else
        {
            doPermutation(S, n+1, ct, pos, res);
            if (islower(S[pos[n-1]]))
                S[pos[n-1]] = toupper(S[pos[n-1]]);
            else
                S[pos[n-1]] = tolower(S[pos[n-1]]);
            doPermutation(S, n+1, ct, pos, res);
        }
    }