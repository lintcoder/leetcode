bool squareIsWhite(string coordinates) {
        return ((coordinates[0]-'a')+(coordinates[1]-'1'))%2 == 0 ? false : true;
    }