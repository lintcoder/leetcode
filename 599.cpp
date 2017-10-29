vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        using SI = map<string, int>;
        SI mp1, mp2;
        int len1 = list1.size(), len2 = list2.size();
        if (len1 == 0 || len2 == 0)
            return {};
        
        for (int i = 0; i < len1; ++i)
        {
            mp1.insert(pair<string, int>(list1[i], i));
        }
        for (int i = 0; i < len2; ++i)
        {
            mp2.insert(pair<string, int>(list2[i], i));
        }
        
        vector<string> res;
        int index = 0, ct = 0;
        int maxindex = 0;
        for (int i = 0; i < len1; ++i)
        {
            if (mp2.find(list1[i]) != mp2.end())
            {
                string s = list1[i];
                int sumindex = mp1[s] + mp2[s];
                if (maxindex == 0)
                {
                    if (ct == 0)
                    {
                        maxindex = sumindex;
                        ct++;
                        res.push_back(s);
                    }
                }
                else
                {
                    if (maxindex == sumindex)
                    {
                        res.push_back(s);
                        ct++;
                    }
                    else if (maxindex > sumindex)
                    {
                        res.push_back(s);
                        maxindex = sumindex;
                        index = ct;
                        ct++;
                    }
                }
            }
        }
        
        return vector<string>(res.begin() + index, res.end());
    }