#include<iostream>
#include<vector>

class ParkingSpot;

class Car{
	public:
	int vehicle_number{};
	Car(int vehicle_number):vehicle_number(vehicle_number){};
};


class ParkingSpot{
	bool isFree{};
	Car* car;
	int id;
	public:
		ParkingSpot(int id):id(id),isFree(true){};
		int get_id(){
			return id;
		}
		bool  get_status(){
			return isFree ;
		}
		
		void unassign_car(){
			isFree= true;
		}

		void assign_car(Car* _car){
			isFree = false;
			car=_car;
		}

		Car* get_car(){
			return car;
		}

};

class ParkingLot{
	int number_of_spots;
	std::vector<ParkingSpot*> parking_spots;
	public:
		ParkingLot(int number_of_spots):number_of_spots(number_of_spots){
			parking_spots.resize(number_of_spots);
			// does it initialize with nullptr
			for(int i=0;i<number_of_spots;i++){
				parking_spots[i] = new ParkingSpot(i);
			}
		};
		
		
		bool  assign_car(Car *car){
			for(int i=0;i<number_of_spots;i++){
				if(parking_spots[i]->get_status() ){
					parking_spots[i]->assign_car(car);
					return true;
				}
			}

			return false;
		};


		void unassign_car(int spot){
			parking_spots[spot]->unassign_car();
		}

		void display(){
			for(int i=0;i<number_of_spots;i++){
				std::cout<< parking_spots[i]->get_id() <<"  has   "<<std::endl;;
				if( (parking_spots[i]->get_status()) ){
					std::cout<<" no car \n";
				}else{
					std::cout<<"  Car with number " <<parking_spots[i]->get_car()->vehicle_number <<" \n";
				}
			}

			std::cout<<std::endl;		
		}

};

int main(){
	
	Car* car1 = new Car(1111);
	Car* car2 = new Car(2222);
	Car* car3 = new Car(4444);
	Car* car4 = new Car(5555);
	Car* car5 = new Car(3333);
	
	ParkingLot parkingLot = ParkingLot(3);

	parkingLot.assign_car(car1);
	parkingLot.display();
	parkingLot.assign_car(car2);
	parkingLot.assign_car(car3);

	parkingLot.assign_car(car4);
	parkingLot.display();
	parkingLot.unassign_car(2);
	parkingLot.assign_car(car4);
	parkingLot.display();


}
