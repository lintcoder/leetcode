vector<int> numberOfLines(vector<int>& widths, string S) {
        int len = S.size();
        int line = 1, sz = 0;
        for (int i = 0; i < len; ++i)
        {
        	int n = widths[S[i]-'a'];
        	if (sz + n <= 100)
        		sz += n;
        	else
        	{
        		line++;
        		sz = n;
        	}
        }

        return {line, sz};
    }