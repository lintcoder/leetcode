string replaceWords(vector<string>& dict, string sentence) {
        auto cmp = [](string& a, string& b) {
        	return a.size() < b.size();
        };
        sort(dict.begin(), dict.end(), cmp);

        string res;
        int index = 0;
        int len = sentence.size();
        int num = dict.size();
        while (index < len)
        {
                string replacestr;
        		int pos = sentence.find(' ', index);
        		if (pos == string::npos)
        		{
        			replacestr = sentence.substr(index);
        			findRoot(dict, num, replacestr);
        			res += " " + replacestr;
        			break;
        		}
        		else
        		{
        			replacestr = sentence.substr(index, pos - index);
        			findRoot(dict, num, replacestr);
        			res += " " + replacestr;
        			index = pos + 1;
        		}
        }

        return res.substr(1);
    }

    void findRoot(const vector<string>& dict, int num, string& replacestr)
    {
    		int len = replacestr.size();
    		for (int i = 0; i < num; ++i)
    		{
    			int sz = dict[i].size();
    			if (sz < len && dict[i] == replacestr.substr(0, sz))
    			{
    				replacestr = dict[i];
    				break;
    			}
    		}
    }