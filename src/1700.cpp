int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> stu(students.begin(), students.end());
        
        int len = sandwiches.size();
        int remain = len;
        int i = 0, j = 0;
        while (i < len)
        {
            for (j = 0; j < remain; ++j)
                if (sandwiches[i] == stu[j])
                    break;
            if (j == remain)
                break;
            stu.insert(stu.end(), stu.begin(), stu.begin()+j);
            stu.erase(stu.begin(), stu.begin()+j+1);
            ++i;
            --remain;
        }
        
        return remain;
    }