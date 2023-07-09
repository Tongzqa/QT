#pragma once

#include "Fbuilder.h"

class Director {
public:
	Director();
	Director(Fbuilder* builder);
	~Director();

	void CreateFunc(Fbuilder* builder);
	void CreateFunc();

private:
	Fbuilder *dbuilder;
};