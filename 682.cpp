int calPoints(vector<string>& ops) {
        int len = ops.size();
        vector<int> points(len, 0);

        int sum = 0;
        int j = 0;
        for (int i = 0; i < len; ++i)
        {
        	if (j > 0 && ops[i] == "C")
        	{
        		--j;
        	}
        	else if (j >= 1 && ops[i] == "D")
        	{
        		points[j] = points[j - 1]*2;
        		++j;
        	}
        	else if (j >= 2 && ops[i] == "+")
        	{
        		points[j] = points[j - 2] + points[j - 1];
        		++j;
        	}
        	else
        		points[j++] = stoi(ops[i]);
        }

        for (int i = 0; i < j; ++i)
        	sum += points[i];

        return sum;
    }