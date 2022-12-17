long long dividePlayers(vector<int>& skill) {
        int len = skill.size();
        sort(skill.begin(), skill.end());

        int n = len/2;
        int v = skill[0] + skill[len-1];
        long long sum = skill[0] * skill[len-1];
        for (int i = 1; i < n; ++i)
        {
            if (skill[i] + skill[len-1-i] != v)
                return -1;
            else
                sum += skill[i] * skill[len-1-i];
        }

        return sum;
    }