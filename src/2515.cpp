int closetTarget(vector<string>& words, string target, int startIndex) {
        int len = words.size();
        int i = startIndex;
        int mindist = len;
        int n = 0;

        while (n < len)
        {
            if (words[i] == target)
            {
                int dist1 = abs(i-startIndex);
                int dist2 = len-dist1;
                if (dist1 < mindist)
                    mindist = dist1;
                if (dist2 < mindist)
                    mindist = dist2;
            }
            ++i;
            ++n;
            if (i == len)
                i = 0;
        }

        return mindist != len ? mindist : -1;
    }