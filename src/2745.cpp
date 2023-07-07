int longestString(int x, int y, int z) {
        int common = x < y ? x : y;
        int diff = x > common ? 1 : (y > common ? 1 : 0);
        return (common*2 + diff + z) * 2;
    }