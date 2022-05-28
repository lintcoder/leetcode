string largestGoodInteger(string num) {
        int len = num.size();
        int i = 1, ct = 1;
        char c = num[0];
        char goodchar = ' ';
        
        while (i < len)
        {
            if (num[i] == c)
            {
                ++ct;
                if (ct == 3)
                {
                    if (goodchar == ' ')
                        goodchar = c;
                    else if (c > goodchar)
                        goodchar = c;
                    
                    int j = i+1;
                    while (j < len && num[j] == c)
                        ++j;
                    if (j == len)
                        break;
                    else
                    {
                        c = num[j];
                        ct = 1;
                        i = j+1;
                    }
                }
                else
                    ++i;
            }
            else
            {
                c = num[i];
                ct = 1;
                ++i;
            }
        }
        
        if (goodchar != ' ')
            return string(3, goodchar);
        else
            return "";
    }