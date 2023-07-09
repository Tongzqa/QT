#include <iostream>
using namespace std;

// 抽象西瓜
class AbstractWatermelon {
public:
	virtual void PrintName() = 0;
	AbstractWatermelon() {
		cout << "抽象西瓜构造函数." << endl;
	}
	~AbstractWatermelon() {
		cout << "抽象西瓜析构函数." << endl;
	}
};

// 抽象桔子
class AbstractOrange {
public:
	virtual void PrintName() = 0;
	AbstractOrange() {
		cout << "抽象桔子构造函数." << endl;
	}
	~AbstractOrange() {
		cout << "抽象桔子析构函数." << endl;
	}
};

// 中国西瓜
class ChinaWatermelon :public AbstractWatermelon {
public:
	virtual void PrintName() {
		cout << "中国西瓜最好吃." << endl;
	}
	ChinaWatermelon() {
		cout << "中国西瓜构造函数." << endl;
	}
	~ChinaWatermelon() {
		cout << "中国西瓜析构函数." << endl;
	}
};

// 中国桔子
class ChinaOrange :public AbstractOrange
{
public:
	virtual void PrintName() {
		cout << "中国桔子最甜的.\n" << endl;
	}
	ChinaOrange() {
		cout << "中国桔子构造函数." << endl;
	}
	~ChinaOrange() {
		cout << "中国桔子析构函数" << endl;
	}
};

// 埃及西瓜
class EgyptWatermelon :public AbstractWatermelon {
public:
	virtual void PrintName() {
		cout << "埃及西瓜：早在四千年前就种植西瓜." << endl;
	}
	EgyptWatermelon() {
		cout << "埃及西瓜构造函数." << endl;
	}
	~EgyptWatermelon() {
		cout << "埃及西瓜析构函数." << endl;
	}
};

// 埃及桔子
class EgyptOrange :public AbstractOrange {
public:
	virtual void PrintName() {
		cout << "埃及桔子光照条件最好，供应高质量的桔子." << endl;
	}
	EgyptOrange() {
		cout << "埃及桔子构造函数." << endl;
	}
	~EgyptOrange() {
		cout << "埃及桔子析构函数." << endl;
	}
};


// 抽象工厂 主要针对产品转换
class AbstrctFactory {
public:
	virtual AbstractWatermelon* CreateWatermelon() = 0;
	virtual AbstractOrange* CreateOrange() = 0;

	AbstrctFactory() {
		cout << "抽象工厂构造函数." << endl;
	}
	~AbstrctFactory() {
		cout << "抽象工厂析构函数." << endl;
	}
};

// 中国工厂
class ChinaFactory :public AbstrctFactory
{
public:
	virtual AbstractWatermelon* CreateWatermelon() {
		return new ChinaWatermelon;
	}
	virtual AbstractOrange* CreateOrange() {
		return new ChinaOrange;
	}
	ChinaFactory() {
		cout << "中国工厂构造函数." << endl;
	}
	~ChinaFactory() {
		cout << "中国工厂析构函数." << endl;
	}


};

// 埃及工厂
class EgyptFactory :public AbstrctFactory {
public:
	virtual AbstractWatermelon* CreateWatermelon() {
		return new EgyptWatermelon;
	}
	virtual AbstractOrange* CreateOrange() {
		return new EgyptOrange;
	}
	EgyptFactory() {
		cout << "埃及工厂构造函数." << endl;
	}
	~EgyptFactory() {
		cout << "埃及工厂析构函数." << endl;
	}
};


int main()
{
	cout << "****************************************************************************" << endl;
	AbstrctFactory* cfactory = new ChinaFactory;
	AbstractWatermelon* cwatermelon = cfactory->CreateWatermelon();
	AbstractOrange* corange = cfactory->CreateOrange();
	cwatermelon->PrintName();
	corange->PrintName();

	delete corange; corange = nullptr;
	delete cwatermelon; cwatermelon = nullptr;
	delete cfactory; cfactory = nullptr;
	cout << "****************************************************************************" << endl;


	cout << "\n\n****************************************************************************" << endl;
	AbstrctFactory* efactory = new EgyptFactory;
	AbstractWatermelon* ewatermelon = efactory->CreateWatermelon();
	AbstractOrange* eorange = efactory->CreateOrange();
	ewatermelon->PrintName();
	eorange->PrintName();

	delete eorange; eorange = nullptr;
	delete ewatermelon; ewatermelon = nullptr;
	delete efactory; efactory = nullptr;
	cout << "****************************************************************************" << endl;





	return 0;
}
