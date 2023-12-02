#include <iostream>
#include <vector>

using namespace std;

class Car {
  public:
    Car(int lp, int size = 1) {
      _lp = lp;
      _size = size;
    }

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
        bool available = true;
        for (int j = i; j < i + v.size(); ++j) {
            if (j >= _spots) {
                return -1;
            }
            if (_storage[i].plate() != -1) {
                available = false;
                break;
            }
        }
        if (available) {
          lot_no = i;
          break;
        }
      }
      if (lot_no != -1) {
        for (int i = lot_no; i < lot_no + v.size(); ++i) {
          _storage[i] = v;
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
          lot_no = i;
          break;
        }
      }
      if (lot_no != -1) {
        for (int i = lot_no; i < _spots; ++i) {
          if (_storage[i].plate() == v.plate()) {
            _storage[i] = VehicleType(-1);
          }
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

