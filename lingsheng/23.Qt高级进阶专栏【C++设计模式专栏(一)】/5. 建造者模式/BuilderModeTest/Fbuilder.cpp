#include "Fbuilder.h"

Fbuilder::Fbuilder(){

}

Fbuilder::~Fbuilder() {

}

Phone* Fbuilder::GetPhone()
{
	return phone;
}




IphoneBuilder::IphoneBuilder() {
	phone = new Phone;
}
void IphoneBuilder::buildCamera() {
	phone->setCamera("Iphone Camera Created.");
}
void IphoneBuilder::buildBattery() {
	phone->setBattery("Iphone Battery Created.");
}
void IphoneBuilder::buildScreen() {
	phone->setScreen("Iphone Screen Created.");
}



HuaweiBuilder::HuaweiBuilder() {
	phone = new Phone;
}
void HuaweiBuilder::buildCamera() {
	phone->setCamera("Huawei Camera Created.");
}
void HuaweiBuilder::buildBattery() {
	phone->setBattery("Huawei Battery Created.");
}
void HuaweiBuilder::buildScreen() {
	phone->setScreen("Huawei Screen Created.");
}
