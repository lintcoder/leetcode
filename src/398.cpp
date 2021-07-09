Solution(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            elems[nums[i]].vals.push_back(i);
            elems[nums[i]].len++;
        }
    }
    
    int pick(int target) {
        int len = elems[target].len;
        
        return elems[target].vals[rand()%len];
    }
    
    struct Elem
    {
        vector<int> vals;
        int len;
        Elem():vals({}), len(0){}
    };
    map<int, Elem> elems;