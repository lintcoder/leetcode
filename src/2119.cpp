bool isSameAfterReversals(int num) {
        return num >= 10 ? num%10 != 0 : true;
    }