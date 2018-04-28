string multiply(string num1, string num2) {
     int len1 = num1.size();
     int len2 = num2.size();
     if (len1 == 0 || len2 == 0)
     	return "";
     if (num1 == "0" || num2 == "0")
        return "0";

     vector<string> subsum;
     vector<int> digitlen;
     int sum, ct;
     for (int i = len2-1; i >= 0; --i)
     {
        if (num2[i] == '0')
            continue;
        sum = 0;
        ct = 0;
     	string s(len2-1-i, '0');
     	for (int j = len1-1; j >= 0; --j)
     	{
     		sum = (num2[i]-'0') * (num1[j]-'0') + ct;
     		s.push_back(sum%10+'0');
     		ct = sum/10;
     	}
     	if (ct > 0)
     		s.push_back(ct+'0');
     	subsum.push_back(s);
     	digitlen.push_back(s.size());
     }

     string res;
     int len = subsum.size();
     int i = 0;
     ct = 0;
     while (true)
     {
     	sum = 0;
     	bool flag = false;
     	for (int j = 0; j < len; ++j)
     	{
     		if (i < digitlen[j])
     		{
     			sum += subsum[j][i] - '0';
     			flag = true;
     		}
     	}
     	if (!flag)
     		break;
     	sum += ct;
     	res.push_back(sum%10+'0');
     	ct = sum/10;
     	++i;
     }
     if (ct > 0)
     	res.push_back(ct+'0');

     reverse(res.begin(), res.end());
     return res;
   }