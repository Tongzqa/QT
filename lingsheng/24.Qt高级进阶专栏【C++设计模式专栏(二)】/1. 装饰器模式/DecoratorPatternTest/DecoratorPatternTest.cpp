
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    virtual void show() = 0;
};

// 汽车：装饰器的基类
class CarDecorator :public Car {
    CarDecorator(Car* p) :pCar() {
    }

private:
    Car* pCar;
};

// 4个实体的汽车类
class Volkswagen :public Car {
public:
    void show() {
        cout << "大众汽车配置：基本配置";
    }
};

class Byd :public Car {
public:
    void show() {
        cout << "比亚迪汽车配置：基本配置";
    }
};

class Benz :public Car {
public:
    void show() {
        cout << "奔驰汽车配置：基本配置";
    }
};

class Toyota :public Car {
public:
    void show() {
        cout << "丰田汽车配置：基本配置";
    }
};

// 装饰器1：自动泊车入位
class ConcreteDecorator1 :public Car {
public:
    ConcreteDecorator1(Car* p) :pCar(p) {
    }
    void show() {
        pCar->show();
        cout << "，自动泊车入位";
    }
private:
    Car* pCar;
};

// 装饰器2：自动刹车
class ConcreteDecorator2 :public Car {
public:
    ConcreteDecorator2(Car* p) :pCar(p) {
    }
    void show() {
        pCar->show();
        cout << "，自动刹车";
    }
private:
    Car* pCar;
};

// 装饰器3：车联网
class ConcreteDecorator3 :public Car {
public:
    ConcreteDecorator3(Car* p) :pCar(p) {
    }
    void show() {
        pCar->show();
        cout << "，车联网";
    }
private:
    Car* pCar;
};

// 装饰器4：道路交通标识识别
class ConcreteDecorator4 :public Car {
public:
    ConcreteDecorator4(Car* p) :pCar(p) {
    }
    void show() {
        pCar->show();
        cout << "，道路交通标识识别";
    }
private:
    Car* pCar;
};

int main()
{
    Car* pobj1 = new ConcreteDecorator1(new Volkswagen());
    pobj1 = new ConcreteDecorator2(pobj1);
    pobj1->show();
    cout << endl;

    Car* pobj2 = new ConcreteDecorator1(new Benz());
    pobj2 = new ConcreteDecorator2(pobj2);
    pobj2 = new ConcreteDecorator3(pobj2);
    pobj2 = new ConcreteDecorator4(pobj2);
    pobj2->show();
    cout << endl;


    return 0;
}

