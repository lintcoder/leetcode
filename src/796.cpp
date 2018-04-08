bool rotateString(string A, string B) {
        int lenA = A.size();
        int lenB = B.size();
        if (lenA != lenB)
            return false;
        if (lenA == 0 && lenB == 0)
            return true;
        int index = 0;
        while (index < lenA && (index = B.find(A[0], index)) != string::npos)
        {
            if (A.substr(0, lenB - index) == B.substr(index) && A.substr(lenB-index) == B.substr(0, index))
                return true;
            index++;
        }
        return false;
    }