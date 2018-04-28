int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            int pos1 = version1.find('.', i);
            int pos2 = version2.find('.', j);
            if (pos1 == string::npos)
            {
                if (pos2 == string::npos)
                    return docmp(version1.substr(i), version2.substr(j));
                else
                {
                    string mainversion2 = version2.substr(j, pos2 - j);
                    int res = docmp(version1.substr(i), mainversion2);
                    if (res != 0)
                        return res;
                    else
                        return -1 * is_subversion_zero(version2.substr(pos2 + 1));
                }
            }
            else
            {
                string subversion1 = version1.substr(i, pos1 - i);
                if (pos2 == string::npos)
                {
                    int res = docmp(subversion1, version2.substr(j));
                    if (res != 0)
                        return res;
                    else
                        return is_subversion_zero(version1.substr(pos1 + 1));
                }
                else
                {
                    string subversion2 = version2.substr(j, pos2 - j);
                    int res = docmp(subversion1, subversion2);
                    if (res != 0)
                        return res;
                    else
                    {
                        i = pos1 + 1;
                        j = pos2 + 1;
                    }
                }
            }
        }
        return 0;
    }

    int docmp(const string& version1, const string& version2)
    {
        int first_num1 = version1.find_first_not_of('0');
        int first_num2 = version2.find_first_not_of('0');
        string v1, v2;
        if (first_num1 == string::npos)
            v1 = "0";
        else
            v1 = version1.substr(first_num1);
        if (first_num2 == string::npos)
            v2 = "0";
        else
            v2 = version2.substr(first_num2);
        int len1 = v1.size();
        int len2 = v2.size();
        if (len1 < len2)
            return -1;
        else if (len1 == len2)
        {
            if (v1 < v2)
                return -1;
            else if (v1 == v2)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }

    int is_subversion_zero(const string& str)
    {
        int len = str.size();
        for (int i = 0; i < len; ++i)
        {
            if (str[i] != '0' && str[i] != '.')
                return 1;
        }
        return 0;
    }