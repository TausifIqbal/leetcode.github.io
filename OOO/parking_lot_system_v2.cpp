#include<iostream>
#include<vector>
#include<string>

class ParkingSpot;


enum class  VehicleType { CAR, BIKE, TRUCK};

enum class  SpotType { SMALL, MEDIUM, LARGE};

class Vehicle{
	std::string license{};
	VehicleType type{};
	public:
	Vehicle(VehicleType type, std::string license):type(type),license(license){};

	virtual ~Vehicle()=default;

	VehicleType getType(){
		return type;
	}

	std::string getLicense(){
		return license;
	}
};
class Bike:public Vehicle{
	public:
	Bike(std::string license):Vehicle(VehicleType::BIKE,license){};
};

class Truck:public Vehicle{
	public:
	Truck(std::string license):Vehicle(VehicleType::TRUCK,license){};
};
class Car:public Vehicle{
	public:
	Car(std::string license):Vehicle(VehicleType::CAR,license){};
};

class ParkingSpot{
	bool isFree{};
	Vehicle* parkedVehicle;
	int id{};
	SpotType spotType{};
	public:
		ParkingSpot(int id, SpotType spotType):id(id), spotType(spotType), isFree(true){};

		int get_id(){
			return id;
		}
		bool  available(){
			return isFree;
		}
		SpotType getSpotType(){
			return spotType;
		}
		
		bool canFit(Vehicle *_vehicle){
			if(_vehicle->getType() == VehicleType::BIKE ){
				return true;
			}
			if(_vehicle->getType() == VehicleType::CAR  && spotType != SpotType::SMALL){
			       return true;
		      	}
			if(_vehicle->getType() == VehicleType::TRUCK && spotType == SpotType::LARGE){
				return true;
			}
			return false;		
		}

		void unpark(){
			isFree= true;
		}

		bool park(Vehicle* _vehicle){
			if(canFit(_vehicle)){
				isFree = false;
				parkedVehicle=_vehicle;
				return true;
			}
			return false;
		}

		Vehicle* getVehicle(){
			return parkedVehicle;
		}
};

class ParkingFloor{

	int id{};
	std::vector<ParkingSpot*> spots;
	int numSpots{};

	public:
		ParkingFloor(int id,int numSpots):id(id),numSpots(numSpots){
			spots.emplace_back(new ParkingSpot(0,SpotType::SMALL));
			spots.emplace_back(new ParkingSpot(1,SpotType::SMALL));
			spots.emplace_back(new ParkingSpot(2,SpotType::MEDIUM));
			spots.emplace_back(new ParkingSpot(3,SpotType::LARGE));

		}

		bool parkVehicle(Vehicle * _vehicle){
			for(int i=0;i<numSpots;i++){
				if(spots[i]->available()  && spots[i]->park(_vehicle) ){
						return true;
				}
			}
			return false;
		}
	
		bool  unparkVehicle(std::string license ){
			for(int i=0;i<numSpots;i++){
				if( !spots[i]->available()  && spots[i]->getVehicle()->getLicense() == license){
					spots[i]->unpark();
					return true;
				}
			}
			return false;
		}

		bool hasFreeSpot(){
			for(int i=0;i<numSpots;i++){
				if(spots[i]->available()){
					return true;
				}
			}
			return false;
		}

		void display(){
			for(int j=0;j<numSpots;j++){
				auto parking_spot = spots[j];
				std::cout<<"ParkingSpot " <<parking_spot->get_id() <<" ";
				if( (parking_spot->available()) ){
					std::cout<<" no vehicle \n";
				}else{
					std::cout<<"  vehicle  with number " <<parking_spot->getVehicle()->getLicense() <<" \n";
				}
			}	
		}
};


class ParkingLot{
	int number_of_floors;
	int number_of_spots =4;
	std::vector<ParkingFloor*> parking_floors;
	public:
		ParkingLot(int number_of_floors):number_of_floors(number_of_floors){
			parking_floors.resize(number_of_floors);
			// does it initialize with nullptr
			for(int i=0;i<number_of_floors;i++){
				parking_floors[i] = new ParkingFloor(i,number_of_spots);
			}
		};
		
		
		bool  park(Vehicle *vehicle){
			for(int i=0;i<number_of_floors;i++){
				if(parking_floors[i]->hasFreeSpot() && parking_floors[i]->parkVehicle(vehicle)){
					return true;
				}
			}
			std::cout<<" Vehicle can't be parked"<<std::endl;
			return false;
		};


		void unpark(std::string license){
			for(int i=0;i<number_of_floors;i++){
				if( parking_floors[i]->unparkVehicle(license)){
					std::cout<<" Vehicle with license " <<license<< " has been unparked"<<std::endl;
					return;
				}
			}

			std::cout<<"No such vehicle with license " <<license<<std::endl;

		}

		void display(){
			for(int i=0;i<number_of_floors;i++){
				std::cout<<" Floor  number " << i <<std::endl;
				parking_floors[i]->display();

			
			}

			std::cout<<std::endl;		
		}

};

int main(){
	

	Vehicle* car1 =  new Car("CAR123432");
	Vehicle* bike1 = new Bike("BIK123432");
	Vehicle* truck1 = new Truck("TRU123432");
	Vehicle* car2 = new Car("CAR223432");
	Vehicle* bike2 = new Bike("BIK223432");
	Vehicle* truck2 = new Truck("TRU223432");
	Vehicle* car3 = new Car("CAR323432");
	Vehicle* bike3 = new Bike("BIK323432");
	Vehicle* truck3 = new Truck("TRU323432");




	ParkingLot parkingLot = ParkingLot(2);

	parkingLot.park(car1);
	parkingLot.display();
	parkingLot.park(car2);
	parkingLot.park(bike3);
	parkingLot.park(car3);
	parkingLot.park(bike1);
	parkingLot.park(bike2);
	parkingLot.park(truck1);
	parkingLot.park(truck2);
	parkingLot.display();
	parkingLot.park(truck3);

	parkingLot.unpark("CAR223432");
	parkingLot.park(truck3);

	parkingLot.park(car2);
	parkingLot.display();
}
