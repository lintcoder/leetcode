vector<int> constructRectangle(int area) {
    vector<int> length(2, 0);
    int limit = sqrt(area);
    int i = limit;
    while (i <= area)
    {
        if (area % i == 0)
            break;
        else
            ++i;
    }
    int j = area / i;
    if (i > j)
    {
        length[0] = i;
        length[1] = j;
    }
    else
    {
        length[0] = j;
        length[1] = i;
    }
    return length;
}
