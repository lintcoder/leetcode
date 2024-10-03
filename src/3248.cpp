int finalPositionOfSnake(int n, vector<string>& commands) {
        int len = commands.size();
        int r = 0, c = 0;
        map<string, int> mp{{"UP", 0}, {"RIGHT", 1}, {"DOWN", 2}, {"LEFT", 3}};

        for (int i = 0; i < len; ++i)
        {
            switch (mp[commands[i]])
            {
                case 0:
                    r -= 1;
                    break;
                case 1:
                    c += 1;
                    break;
                case 2:
                    r += 1;
                    break;
                case 3:
                    c -= 1;
                    break;
                default:
                    break;
            }
        }

        return r*n + c;
    }