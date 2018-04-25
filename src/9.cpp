bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int sum = 0;
        while (true)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
            if (sum == 0)
                return false;
            if (sum == x)
                return true;
            else if (sum > x)
                break;
            else
            {
                if (x < 10)
                    return false;
            }
        }
        return sum == x * 10 + sum % 10;
    }