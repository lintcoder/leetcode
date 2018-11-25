class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto iter = lower_bound(interval_begin.begin(), interval_begin.end(), end);
        if (iter == interval_begin.begin())
        {
            interval_begin.insert(interval_begin.begin(), start);
            interval_end.insert(interval_end.begin(), end);
            return true;
        }
        else
        {
            int pos = iter-interval_begin.begin()-1;
            if (start < interval_end[pos])
                return false;
            interval_begin.insert(iter, start);
            interval_end.insert(interval_end.begin()+pos+1, end);
            return true;
        }
    }

private:
	vector<int> interval_begin;
	vector<int> interval_end;
};