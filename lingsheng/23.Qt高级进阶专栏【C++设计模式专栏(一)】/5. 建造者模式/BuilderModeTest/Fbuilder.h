#pragma once

#include "Phone.h"

class Fbuilder // 基类
{
public:
	Fbuilder();
	~Fbuilder();

protected:
	Phone* phone; // 电话对象

public:
	virtual void buildCamera() = 0;
	virtual void buildBattery() = 0;
	virtual void buildScreen() = 0;

	virtual Phone* GetPhone();

};

class IphoneBuilder :public Fbuilder { // 苹果派生类
public:
	IphoneBuilder();
	void buildCamera();
	void buildBattery();
	void buildScreen();
};

class HuaweiBuilder :public Fbuilder { // 华为派生类
public:
	HuaweiBuilder();
	void buildCamera();
	void buildBattery();
	void buildScreen();
};