#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class Phone // �绰��
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
	string strCamera;	// ����ͷ
	string strBattery;	// ���
	string strScreen;	// ��Ļ
};
