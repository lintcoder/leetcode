int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int accum[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        
        int m1 = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0')-1;
        int d1 = (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0');
        int m2 = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0')-1;
        int d2 = (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0');
        int m3 = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0')-1;
        int d3 = (arriveBob[3]-'0')*10 + (arriveBob[4]-'0');
        int m4 = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0')-1;
        int d4 = (leaveBob[3]-'0')*10 + (leaveBob[4]-'0');
        
        int start1 = accum[m1]+d1, end1 = accum[m2]+d2;
        int start2 = accum[m3]+d3, end2 = accum[m4]+d4;
        
        if (start1 < start2)
        {
            if (start2 <= end1)
            {
                if (end1 < end2)
                    return end1-start2+1;
                else
                    return end2-start2+1;
            }
            else
                return 0;
        }
        else
        {
            if (start1 <= end2)
            {
                if (end2 < end1)
                    return end2-start1+1;
                else
                    return end1-start1+1;
            }
            else
                return 0;
        }
    }