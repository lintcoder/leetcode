vector<string> findOcurrences(string text, string first, string second) {
        int i = 0;
        int sz = text.size();
        
        vector<string> res;
        while (i <sz)
        {
            int pos = text.find(' ', i);
            if (pos != string::npos)
            {
                string w1 = text.substr(i, pos-i);
                if (w1 == first)
                {
                    int pos2 = text.find(' ', pos+1);
                    if (pos2 != string::npos && pos2 <= sz-2)
                    {
                        string w2 = text.substr(pos+1, pos2-pos-1);
                        if (w2 == second)
                        {
                            int pos3 = text.find(' ', pos2+1);
                            if (pos3 != string::npos)
                            {
                                res.push_back(text.substr(pos2+1, pos3-pos2-1));
                                i = pos+1;
                            }    
                            else
                            {
                                res.push_back(text.substr(pos2+1));
                                break;
                            }    
                        }
                        else
                            i = pos+1;
                    }
                    else
                        break;
                }
                else
                    i = pos+1;
            }
            else
                break;
        }
        
        return res;
    }