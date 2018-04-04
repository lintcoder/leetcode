int findShortestSubArray(vector<int>& nums) {
     int len = nums.size();
     map<int, vector<int>> mp;
     for (int i = 0; i < len; ++i)
     {
     	if (mp.find(nums[i]) == mp.end())
     		mp.insert(pair<int, vector<int>>(nums[i], vector<int>(1, i)));
     	else
            mp[nums[i]].push_back(i);
     }
        
     int maxlen = 0;
     for (auto iter = mp.begin(); iter != mp.end(); ++iter)
     {
     	if (iter->second.size() > maxlen)
     		maxlen = iter->second.size();
     }

     auto iter = mp.begin();
     while (iter != mp.end() && iter->second.size() != maxlen)
     	++iter;
     int shortlength = iter->second[maxlen - 1] - iter->second[0] + 1;
     ++iter;

     for (; iter != mp.end(); ++iter)
     {
     	if (iter->second.size() == maxlen)
     	{
     		int dist = iter->second[maxlen - 1] - iter->second[0] + 1;
     		if (dist < shortlength)
     			shortlength = dist;
     	}
     }

     return shortlength;
    }