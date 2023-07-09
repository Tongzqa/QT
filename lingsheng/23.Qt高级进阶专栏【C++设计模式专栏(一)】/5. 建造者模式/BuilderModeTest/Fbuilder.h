#pragma once

#include "Phone.h"

class Fbuilder // ����
{
public:
	Fbuilder();
	~Fbuilder();

protected:
	Phone* phone; // �绰����

public:
	virtual void buildCamera() = 0;
	virtual void buildBattery() = 0;
	virtual void buildScreen() = 0;

	virtual Phone* GetPhone();

};

class IphoneBuilder :public Fbuilder { // ƻ��������
public:
	IphoneBuilder();
	void buildCamera();
	void buildBattery();
	void buildScreen();
};

class HuaweiBuilder :public Fbuilder { // ��Ϊ������
public:
	HuaweiBuilder();
	void buildCamera();
	void buildBattery();
	void buildScreen();
};