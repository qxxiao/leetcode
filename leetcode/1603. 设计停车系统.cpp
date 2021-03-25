class ParkingSystem
{
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (big)
            {
                big--;
                return true;
            }
            return false;
        case 2:
            if (medium)
            {
                medium--;
                return true;
            }
            return false;
        case 3:
            if (small)
            {
                small--;
                return true;
            }
            return false;
        default:
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */