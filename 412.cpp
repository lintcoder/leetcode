vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0 && i % 5 != 0)
            res.push_back("Fizz");
        else if (i % 3 != 0 && i % 5 == 0)
            res.push_back("Buzz");
        else if (i % 15 == 0)
            res.push_back("FizzBuzz");
        else
            res.push_back(int2str(i));
    }
    return res;
}

string int2str(int n)
{
    string s;
    while (n != 0)
    {
        s.push_back(n % 10 + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
