string fractionAddition(string expression) {
        vector<int> numerator, denominator;
        int len = expression.size();
        int i, pos;

        if (expression[0] == '-')
        {
        	pos = expression.find_first_of("/", 1);
    		numerator.push_back(-1*stoi(expression.substr(1, pos - 1)));
    		i = pos + 1;
        }
        else
        {
        	pos = expression.find_first_of("/", 0);
        	numerator.push_back(stoi(expression.substr(0, pos)));
        	i = pos + 1;
        }	
        while (true)
        {
        	pos = expression.find_first_of("+-", i);
        	if (pos != string::npos)
        	{
        		denominator.push_back(stoi(expression.substr(i, pos - i)));
        		i = pos;
        	}	
        	else
        	{
        		denominator.push_back(stoi(expression.substr(i)));
        		break;
        	}
        	if (expression[i] == '-')
        	{
        		pos = expression.find_first_of("/", i);
        		numerator.push_back(-1*stoi(expression.substr(i+1, pos - (i+1))));
        		i = pos + 1;
        	}
        	else
            {
                pos = expression.find_first_of("/", i);
                numerator.push_back(stoi(expression.substr(i, pos - i)));
                i = pos + 1;
            }
        }

        int sz = denominator.size();
        int res_n = 0, res_d = 0;
        if (sz == 1)
        {
        	int r = gcd(abs(numerator[0]), denominator[0]);
        	res_n = numerator[0]/r;
        	res_d = denominator[0]/r;
        }
        else
        {
        	int r = denominator[0];
        	for (int i = 1; i < sz; ++i)
        		r = r / gcd(r, denominator[i]) * denominator[i];

        	res_d = r;
        	for (int i = 0; i < sz; ++i)
        		res_n += r/denominator[i]*numerator[i];

        	
    		r = gcd(abs(res_n), res_d);
        	res_n = res_n/r;
        	res_d = res_d/r;
	    
        }
        return to_string(res_n) + "/" + to_string(res_d);
    }

    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int r = b;
            b = a % b;
            a = r;
        }

        return a;
    }