class ParkingSystem {
public:
    int parking[3];
    ParkingSystem(int big, int medium, int small) {
        parking[0] = big;
        parking[1] = medium;
        parking[2] = small;
    }
    
    bool addCar(int carType) {
        return (parking[carType - 1]--) > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */