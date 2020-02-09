class TweetCounts {
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (mp.find(tweetName) != mp.end())
        {
            int ct = 0;
            int interval = 0;
            if (freq == "minute")
            {
                ct = (endTime-startTime+60)/60;
                interval = 60;
            }
            else if (freq == "hour")
            {
                ct = (endTime-startTime+3600)/3600;
                interval = 3600;
            }
            else
            {
                ct = (endTime-startTime+86400)/86400;
                interval = 86400;
            }
            vector<int> res(ct, 0);
            int len = mp[tweetName].size();
            for (int i = 0; i < len; ++i)
            {
                if (mp[tweetName][i] < startTime || mp[tweetName][i] >= endTime+1)
                    continue;
                res[(mp[tweetName][i]-startTime)/interval]++;
            }
            
            return res;
        }
        else
            return {};
    }
    private:
            map<string, vector<int>> mp;
};
