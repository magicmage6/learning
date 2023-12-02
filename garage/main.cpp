#include <iostream>
#include <vector>

using namespace std;

class Car {
  public:
    Car(int lp, int size = 1) : _lp(lp), _size(size) {}

    int plate() {
      return _lp;
    }

    int size() {
      return _size;
    }
  private:
    int _lp;
    int _size;
};


class Bus : public Car {
  public:
  Bus(int lp, int size = 2) : Car(lp, size) {
  }
};

template <class VehicleType>
class Garage {
  public:
    Garage(int spots) {
      _spots = spots;
      for (int i = 0; i < spots; i++) {
        _storage.push_back(VehicleType(-1));
      }
    }

    // parks vehicle in the garage and returns the spot
    // if multiple (consecutive) spots needed then returns the first spot
    // if no spots available then returns -1
    int parkVehicle(VehicleType v) {
      int lot_no = -1;
      for(int i = 0; i < _spots; ++i) {
        if (_available(i, v.size())) {
          _addVehicle(i, v);
          return i;
        }
      }
      return lot_no;
    }

    // removes vehicle from the garage and returns the first spot number
    // if vehicle is not present then returns -1
    int remove(VehicleType v) {
      int lot_no = -1;
      for(int i = 0; i < _spots; ++i) {
        if(_storage[i].plate() == v.plate()) {
          _addVehicle(i, VehicleType(-1, v.size()));
          return i;
        }
      }
      return -1;
    }


    void display() {
      for (int i = 0; i < _spots; i++) {
        cout << "lot #" << i;
        const int plate = _storage[i].plate();
        if (plate == -1) {
            cout << " empty" << endl;
        } else {
            cout << " plate " << plate << endl;
        }
    }
}

private:
    // Check if a lot started from lot_no is available for a vehicle size.
    // Check for several lot, if any of them is not empty, or is over the
    // garage capacity, it is not available.
    bool _available(int lot_no, int size) {
      for (int i = lot_no; i < lot_no + size; ++i) {
        if (i >= _spots || _storage[i].plate() != -1)
          return false;
      }
      return true;
    }

    // Add vehicle to a lot starting from lot_no with the size of the 
    // vehicle.
    void _addVehicle(int lot_no, VehicleType v) {
      for (int i = lot_no; i < lot_no + v.size() && i < _spots; ++i)
        _storage[i] = v;
    }

    int _spots;
    vector<VehicleType> _storage;
};

int main() {
    Garage<Bus> g(10);
    Bus b1(101, 2);
    cout << "parked " << b1.plate() << " at lot " << g.parkVehicle(b1) << endl;
    g.display();
    Bus b2(102, 3);
    cout << "parked " << b2.plate() << " at lot " << g.parkVehicle(b2) << endl;
    g.display();
    Bus b3(103, 4);
    cout << "parked " << b3.plate() << " at lot " << g.parkVehicle(b3) << endl;
    g.display();
    Bus b4(104, 2);
    cout << "parked " << b4.plate() << " at lot " << g.parkVehicle(b4) << endl;
    g.display();
    cout << "remove " << b2.plate() << " from lot " << g.remove(b2) << endl;
    g.display();
    cout << "remove " << b4.plate() << " from lot " << g.remove(b4) << endl;
    g.display();
    return 0;
}

