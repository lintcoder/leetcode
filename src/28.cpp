int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        if (len1 < len2)
            return -1;
        if (len2 == 0)
            return 0;
        
        int i = 0, pos = 0;
        bool flag = false;
        while (i < len1)
        {
            pos = haystack.find(needle[0], i);
            if (pos == string::npos || len1 - pos < len2)
                break;
            else
            {
                if (haystack.substr(pos, len2) == needle)
                {
                    flag = true;
                    break;
                }
                else
                    i = pos + 1;
            }
        }
        if (flag)
            return pos;
        else
            return -1;
    }