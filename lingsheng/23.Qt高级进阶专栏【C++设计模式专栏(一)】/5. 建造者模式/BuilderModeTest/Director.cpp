
#include "Director.h"

Director::Director() {

}

// ��һ�ֳ�ʼ����Director::Director(Fbuilder* builder):dbuilder(builder)
Director::Director(Fbuilder* builder) {
	dbuilder = builder;
}

Director::~Director() {

}

void Director::CreateFunc(Fbuilder* builder)
{
	builder->buildCamera();
	builder->buildBattery();
	builder->buildScreen();
}

void Director::CreateFunc()
{
	dbuilder->buildCamera();
	dbuilder->buildBattery();
	dbuilder->buildScreen();
}
