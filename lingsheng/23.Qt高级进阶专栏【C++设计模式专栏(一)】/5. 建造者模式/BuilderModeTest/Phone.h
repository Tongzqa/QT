#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class Phone // 电话类
{
public:
	Phone();
	~Phone();

	void setCamera(string camera);
	void setBattery(string battery);
	void setScreen(string screen);

	void PrintCamera();
	void PrintBattery();
	void PrintScreen();

private:
	string strCamera;	// 摄像头
	string strBattery;	// 电池
	string strScreen;	// 屏幕
};
