int countOperations(int num1, int num2) {
        int ct = 0;
        while (num1 != 0 && num2 != 0)
        {
            if (num1 >= num2)
            {
                int tmp = num1/num2;
                num1 = num1 - tmp*num2;
                ct += tmp;
            }
            else
            {
                int tmp = num2/num1;
                num2 = num2 - tmp*num1;
                ct += tmp;
            }
        }
        
        return ct;
    }