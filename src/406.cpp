vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };

        sort(people.begin(), people.end(), cmp);

        list<pair<int, int>> list_people(people.begin(), people.end());

        int len = list_people.size();
        auto iter = list_people.begin();
        int i = 0, j = 0;
        while (i < len)
        {
            if (i == iter->second)
                iter++;
            else
            {
                pair<int, int> p(*iter);
                iter = list_people.erase(iter);
                auto insertpos = list_people.begin();
                advance(insertpos, p.second);
                list_people.insert(insertpos, p);
            }
            ++i;
        }

        people.assign(list_people.begin(), list_people.end());
        return people;
    }