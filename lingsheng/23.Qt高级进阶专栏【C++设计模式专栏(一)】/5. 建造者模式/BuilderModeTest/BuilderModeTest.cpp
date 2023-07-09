
#include <iostream>
using namespace std;

#include "Phone.h"
#include "Director.h"
#include "Fbuilder.h"

int main()
{
    Fbuilder* huawei = new HuaweiBuilder;
    Fbuilder* iphone = new IphoneBuilder;
    Director* director = new Director;

    director->CreateFunc(huawei);
    director->CreateFunc(iphone);

    Phone* huaweiphone = huawei->GetPhone();
    Phone* iphonephone = iphone->GetPhone();

    huaweiphone->PrintCamera();
    huaweiphone->PrintScreen();
    huaweiphone->PrintBattery();

    cout << endl;

    iphonephone->PrintCamera();
    iphonephone->PrintScreen();
    iphonephone->PrintBattery();
    
    return 0;
}

