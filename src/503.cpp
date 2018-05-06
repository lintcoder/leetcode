vector<int> nextGreaterElements(vector<int>& nums) {
         vector<int> res;
         int sz = nums.size();

         for (int i = 0; i < sz; ++i)
         {
            if (!findNextGreater(nums, res, nums[i], (i+1)%sz, (i+sz-1)%sz, sz))
                res.push_back(-1);
         }

         return res;
     }

     bool findNextGreater(const vector<int>& nums, vector<int>& res, int val, int p, int q, int sz)
     {
        if (p == q)
        {
            if (nums[p] > val)
            {
                res.push_back(nums[p]);
                return true;
            }
            else
                return false;
        }
        else if (p == q - 1)
        {
            if (nums[p] > val)
            {
                res.push_back(nums[p]);
                return true;
            }
            if (nums[q] > val)
            {
                res.push_back(nums[q]);
                return true;
            }
            return false;
        }
        else if (p < q)
        {
            int mid = (p + q)/2;
            if (findNextGreater(nums, res, val, p, mid-1, sz))
                return true;
            if (nums[mid] > val)
            {
                res.push_back(nums[mid]);
                return true;
            }
            return findNextGreater(nums, res, val, mid+1, q, sz);
        }
        else
        {
            return findNextGreater(nums, res, val, p, sz - 1, sz) || findNextGreater(nums, res, val, 0, q, sz);
        }

     }