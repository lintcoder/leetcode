public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (mp.find(key) != mp.end())
        	mp[key] = val;
        else
        	mp.insert(pair<string, int>(key, val));
    }
    
    int sum(string prefix) {
    	    int len = prefix.size();
    	    if (len == 0)
    	    	return 0;
    	    
    	    int count = 0;
        for (auto elem : mp)
        	if (elem.first.substr(0, len) == prefix)
        		count += elem.second;

        	return count;
    }
private:
	map<string, int> mp;