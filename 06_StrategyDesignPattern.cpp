#include<bits/stdc++.h>
using namespace std;
class DriveStrategy{
public:
	virtual void drive()=0;
};
class NormalDrive: public DriveStrategy{
public:
	void drive() override{
		cout<<"Normal drive capability"<<endl;
	}
};
class SpecialDrive: public DriveStrategy{
	public:
	void drive() override{
		cout<<"Special drive capability"<<endl;
	}
};
class Vehicle{
public:
	DriveStrategy *driveObj;
	 Vehicle(DriveStrategy *driveObj) : driveObj(driveObj) {}
	void drive(){
		driveObj->drive();
	}
};

class SportsVehicle : public Vehicle {
public:
    SportsVehicle() : Vehicle(new SpecialDrive()) {}
};

class PassengerVehicle : public Vehicle {
public:
    PassengerVehicle() : Vehicle(new NormalDrive()) {}
};

class OffsetVehicle : public Vehicle {
public:
    OffsetVehicle() : Vehicle(new SpecialDrive()) {}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	SportsVehicle spv;
	spv.drive();
	PassengerVehicle pv;
	pv.drive();
	return 0;
}