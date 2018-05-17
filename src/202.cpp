bool isHappy(int n) {
        set<int> st;
        int sum = 0;
        while (true)
        {
            sum = 0;
            while (n != 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1)
                break;
            if (st.find(sum) == st.end())
            {
                st.insert(sum);
                n = sum;
            }
            else
                break;
        }
        return sum == 1;
    }