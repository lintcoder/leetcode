string generateTheString(int n) {
        if (n == 1)
            return "a";
        else if (n%2 == 0)
            return string(1, 'a') + string(n-1, 'b');
        else
            return string(n, 'a');
    }