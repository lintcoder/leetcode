vector<int> distributeCandies(int candies, int num_people) {
        int turn = 1;
        while (true)
        {
            int t = (1+num_people*turn)*num_people*turn/2;
            if (t >= candies)
                break;
            ++turn;
        }
        
        vector<int> res(num_people, 0);
        for (int i = 1; i <= num_people; ++i)
            res[i-1] = i*(turn-1) + (turn-1)*(turn-2)*num_people/2;
        int i = 0;
        candies -= (1+(turn-1)*num_people)*(turn-1)*num_people/2;
        while (candies > 0 && i < num_people)
        {
            int n = i+1+(turn-1)*num_people;
            if (n <= candies)
            {
                res[i] += n;
                candies -= n;
            }
            else
            {
                res[i] += candies;
                break;
            }
            ++i;
        }
        
        return res;
    }