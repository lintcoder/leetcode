vector<int> findRightInterval(vector<Interval>& intervals) {
        int len = intervals.size();
        if (len <= 1)
        	return {-1};

        struct Elem
        {
        	Interval* val;
        	int pos;
        	Elem(Interval* v = nullptr, int p = -1) : val(v), pos(p){}
        };

        auto cmp = [](const Elem& a, const Elem& b) {
        	return a.val->start < b.val->start || (a.val->start == b.val->start && a.val->end < b.val->end);
        };

        vector<int> res(len, -1);
        vector<Elem> vec(len, Elem());
        for (int i = 0; i < len; ++i)
        {
        	vec[i].val = &intervals[i];
        	vec[i].pos = i;
        }
        sort(vec.begin(), vec.end(), cmp);

        auto cmp2 = [](const Elem& a, const Elem& b) {
        	return a.val->start < b.val->end;
        };

        Elem tmp(new Interval(), 0);
        for (int i = 0; i < len-1; ++i)
        {
        	tmp.val->end = vec[i].val->end;
        	auto p = lower_bound(vec.begin()+i+1, vec.end(), tmp, cmp2);
        	if (p != vec.end())
        		res[vec[i].pos] = p->pos;
        }

        return res;
    }