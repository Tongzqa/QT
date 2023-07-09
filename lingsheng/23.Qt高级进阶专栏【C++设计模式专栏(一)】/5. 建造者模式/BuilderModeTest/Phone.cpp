#include "Phone.h"

Phone::Phone(){
	cout << "调用Phone类的构造函数." << endl;
}

Phone::~Phone() {
	cout << "调用Phone类的析构函数." << endl;
}



void Phone::setCamera(string camera) {
	strCamera = camera;
}

void Phone::setBattery(string battery) {
	strBattery = battery;
}

void Phone::setScreen(string screen)
{
	strScreen = screen;
}



void Phone::PrintCamera() {
	cout << "Camera-->" << strCamera.c_str() << endl;
}

void Phone::PrintBattery() {
	cout << "Battery-->" << strBattery.c_str() << endl;
}

void Phone::PrintScreen() {
	cout << "Screen-->" << strScreen.c_str() << endl;
}

