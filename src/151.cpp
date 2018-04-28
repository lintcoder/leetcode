void reverseWords(string &s) {
     int len = s.size();
     vector<string> word;

     int index = s.find_first_not_of(' ');
     if (index == string::npos)
     {
         s = "";
         return;
     }

     while (index != string::npos && index < len)
     {
     	int pos = s.find_first_of(' ', index);
     	if (pos == string::npos)
     	{
     		word.push_back(s.substr(index));
     		break;
     	}
     	else
     	{
     		word.push_back(s.substr(index, pos-index));
     		index = s.find_first_not_of(' ', pos);
     	}
     }
     len = word.size();
     s = "";
     for (int i = len-1; i > 0; --i)
         s += word[i] + " ";
     s += word[0];
    }