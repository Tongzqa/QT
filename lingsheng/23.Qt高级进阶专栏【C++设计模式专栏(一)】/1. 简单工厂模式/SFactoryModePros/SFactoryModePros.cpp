// SFactoryModePros.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 抽象汽车
class AbstractCar
{
public:
    virtual void ShowCarName() = 0;
};

// 具体产品的汽车继承-->抽象汽车类，并且对它方法进行重写操作
// 凯美瑞
class Camry :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Camry Car." << endl;
    }
};

// 迈腾
class Magotan :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Magotan Car." << endl;
    }
};

// 奥迪
class Audi :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Audi Car." << endl;
    }
};

// 奔驰
class Benz :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Benz Car." << endl;
    }
};

// 通过传递参数来确定需要生成那汽车
// 汽车工厂
class CarFactory
{
public:
    static AbstractCar* CreateCarFunc(string cname)
    {
        if (cname == "Camry")
            // 具体生产细节......
            return new Camry;
        else if (cname == "Magotan")
            // 具体生产细节......
            return new Magotan;
        else if (cname == "Audi")
            // 具体生产细节......
            return new Audi;
        else if (cname == "Benz")
            // 具体生产细节......
            return new Benz;
        else
            return nullptr;           

    }   
};




int main()
{
    // 创建工厂
    CarFactory* fty = new CarFactory;

    // 创建汽车
    AbstractCar* car;

    // 指定工厂需要创建的汽车
    car = fty->CreateCarFunc("Benz");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Camry");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Audi");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Magotan");
    car->ShowCarName();
    delete car;






    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
