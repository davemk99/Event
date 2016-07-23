#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <algorithm>
#include "..\EventLibrary\Event.h"
using namespace std;

class Car {
private:


	string name;
	int numberOfSeats;
public:
	Event NameChanged;
	Event NumberOfSeatsChanged;
	void SetName(string name) {
		this->name = name;

		NameChanged(this);

	}

	string GetName() {
		return this->name;
	}
	void SetNumberOfSeats(int seats) {
		this->numberOfSeats = seats;
		NumberOfSeatsChanged(this);
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
	car.NameChanged += [](void* sender) {cout << ((Car*)sender)->GetName(); };
	car.NumberOfSeatsChanged += [](void* sender) {cout << ((Car*)sender)->GetNumberOfSeats(); };
	car.SetName("Nissan");
	getchar();

	return 0;
}