bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int coldiff = abs(coordinate1[0]-coordinate2[0]);
        int rowdiff = abs(coordinate1[1]-coordinate2[1]);

        return (coldiff+rowdiff) % 2 == 0;
    }