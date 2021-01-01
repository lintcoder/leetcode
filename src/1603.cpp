class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        mbig = big;
        mmedium = medium;
        msmall = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1)
        {
            if (mbig > 0)
            {
                --mbig;
                return true;
            }
            else
                return false;
        }
        else if (carType == 2)
        {
            if (mmedium > 0)
            {
                --mmedium;
                return true;
            }
            else
                return false;
        }
        else
        {
            if (msmall > 0)
            {
                --msmall;
                return true;
            }
            else
                return false;
        }
    }
    
private:
    int mbig;
    int mmedium;
    int msmall;
};
