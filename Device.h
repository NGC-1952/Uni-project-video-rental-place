#include "pch.h"
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>


using namespace std;

class Device {

private:
	string name;
	string picName;
	string descrip; 
	bool stock;
	int pricePerDay;
	int daysRented;

public:
	Device();
	Device(int price, bool inStock, string descrip, string picName, string name);
	~Device();

	string getName();
	bool getStock();

	void getParameters();
	void setRent();
	void setDaysRented(int d);
};