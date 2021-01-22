
// Question) 1603. Design Parking System


// Implementation

// 1st Approach in C++

class ParkingSystem {
public:
    vector<int> parking;
    ParkingSystem(int big, int medium, int small) {
        parking = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(parking[carType-1]){
          parking[carType-1] = parking[carType-1] - 1;
            return true;  
        } 
        else return false;
    }
};

