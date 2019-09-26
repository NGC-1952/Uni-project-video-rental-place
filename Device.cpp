#include "pch.h"
#include "Device.h"

Device::Device()
{
}

Device::Device(int price, bool inStock, string descrip, string picName, string name)
	: pricePerDay(price), stock(inStock), descrip(descrip), picName(picName), name(name)
{
}

Device::~Device()
{
}

string Device::getName() {
	return name;
}

bool Device::getStock()
{
	return stock;
}

void Device::getParameters() {

	cv::Mat img = cv::imread(picName);
	fstream description;
	string line;
	description.open(descrip, ios::in );

	cout << " The " << name << "." << endl;

	if(description.is_open()) while (getline(description, line)) cout << line << endl;
	else cout << "Failed to open the file." << endl;

	description.close();

	cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
	cv::imshow(name, img);

	if (img.empty()) cout << "Could not open or find the image" << endl;
	
	cout << "\n The price of rent : " << pricePerDay << " $ per day." << endl;

	if (stock) cout << " The device is currently in stock." << endl;
	else	   cout << " The device is currently out of stock." << endl;
	
	cv::waitKey(0);
	cv::destroyWindow(name);
}

void Device::setRent() { stock = !stock; }

void Device::setDaysRented(int d) { daysRented = d; }
