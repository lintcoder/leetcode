int uniqueMorseRepresentations(vector<string>& words) {
        const string morsecode[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
        								".---","-.-",".-..","--","-.","---",".--.","--.-",
        								".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> transformations;
        int len = words.size();
        for (int i = 0; i < len; ++i)
        {
            string trans;
            int sz = words[i].size();
            for (int j = 0; j < sz; ++j)
                trans += morsecode[words[i][j]-'a'];
            transformations.insert(trans);
        }

        return transformations.size();
    }