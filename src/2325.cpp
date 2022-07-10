string decodeMessage(string key, string message) {
        array<char, 26> transTb{};
        array<bool, 26> flag{};
        
        int len = key.size();
        int j = 0;
        for (int i = 0; i < len; ++i)
        {
            if(key[i] != ' ' && flag[key[i]-'a'] == false)
            {
                transTb[key[i]-'a'] = 'a'+j;
                flag[key[i]-'a'] = true;
                ++j;
                if(j == 26)
                    break;
            }
        }
        
        int mlen = message.size();
        for (int i = 0; i < mlen; ++i)
        {
            if(message[i] != ' ')
                message[i] = transTb[message[i]-'a'];
        }
        
        return move(message);
    }