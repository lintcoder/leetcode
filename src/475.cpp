int findRadius(vector<int>& houses, vector<int>& heaters) {
        int num1 = houses.size();
        int num2 = heaters.size();
        if (num1 == 0 || num2 == 0)
        	return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int min_radius = 0, rad = 0;
        int i = 0, j = 0;
        if (houses[i] < heaters[j])
        {
        	min_radius = heaters[j] - houses[i];
        	++i;
        	while (i < num1 && houses[i] < heaters[j])
        		++i;
        }
        while (i < num1)
        {
        	if (houses[i] == heaters[j])
        		++i;
        	else
        	{
                if (j == num2)
                    break;
        		else
        		{
        			int rlimit = heaters[j + 1];
        			if (houses[i] < rlimit)
        			{
        				int lrad = houses[i] - heaters[j];
        				int rrad = heaters[j + 1] - houses[i];
        				int tmp = lrad < rrad ? lrad : rrad;
        				if (tmp > rad)
        					rad = tmp;
        				++i;
        			}
        			else if (houses[i] == rlimit)
        				++i;
        			else
        			{
        				if (rad > min_radius)
        					min_radius = rad;
        				++j;
        			}
        		}
        	}
        }
        if (rad > min_radius)
            min_radius = rad;
        if (i < num1)
        {
            int tmp = houses[num1 - 1] - heaters[num2 - 1];
            if (tmp > min_radius)
                min_radius = tmp;
        }
    
        return min_radius;
    }