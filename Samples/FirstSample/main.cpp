
#include "..\..\EventLibrary\Event.h"
using namespace std;

class Car {
private:


	string name;
	int numberOfSeats;
public:
	Event<Car> NameChanged;
	Event<Car> NumberOfSeatsChanged;
	void SetName(string name) {
		this->name = name;

		NameChanged(*this);

	}

	string GetName() {
		return this->name;
	}
	void SetNumberOfSeats(int seats) {
		this->numberOfSeats = seats;
		NumberOfSeatsChanged(*this);
	}
	int GetNumberOfSeats() {
		return this->numberOfSeats;
	}
	Car(string name, int seats) {
		this->name = name;
		this->numberOfSeats = seats;
	}

};
int main()
{
	
	Car car("Renault", 4);
	car.NameChanged += [](Car sender) {cout << sender.GetName(); };
	car.NumberOfSeatsChanged += [](Car sender) {cout << sender.GetNumberOfSeats()<<endl; };
	car.SetName("Nissan");
	getchar();

	return 0;
}