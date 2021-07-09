string largestOddNumber(string num) {
        int len = num.size();
        int index = -1;
        bool flag = false;
        for (int i = len-1; i >= 0; --i)
        {
            int tmp = num[i]-'0';
            switch (tmp)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 9:
                    index = i;
                    flag = true;
                    break;
                default:
                    break;
            }
            if (flag)
                break;
        }
        
        if (index == -1)
            return "";
        else
            return num.substr(0, index+1);
    }