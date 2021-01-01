string interpret(string command) {
        stringstream ss;
        int len = command.size();
        int i = 0;
        while (i < len)
        {
            if (command[i] == 'G')
            {
                ss << 'G';
                ++i;
            }
            else if (command[i] == '(')
            {
                if (command[i+1] == ')')
                {
                    ss << 'o';
                    i += 2;
                }
                else
                {
                    ss << "al";
                    i += 4;
                }
            }
        }
        
        return ss.str();
    }