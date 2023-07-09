// 单例模型
/*
#include <iostream>
using namespace std;

class TestA {
public: // 唯一public接口设置为静态，用户不需要创建对象直接类名进行访问
	static TestA* GetInstnace() {
		return data;
	}

private: // 主要目的：不让用户自已创建对象，必须把构造函数进行设成私有化
	TestA()
	{
		data = new TestA;
	}

private:
	static TestA* data;
};

TestA* TestA::data = NULL; // TestA类的外部初始化操作

int main()
{
	TestA::GetInstnace();

	return 0;
}
*/

#include <iostream>
using namespace std;
// 懒汉式
class SingleTonlazy {
private:
	SingleTonlazy() {
		cout << "执行操作：懒汉式构造函数被调用." << endl;
	}

public:
	static SingleTonlazy* GetInstance() {
		if (pSingletontest == NULL)
		{
			pSingletontest = new SingleTonlazy;
		}
		return pSingletontest;
	}

private:
	static SingleTonlazy* pSingletontest;
};
SingleTonlazy* SingleTonlazy::pSingletontest = NULL;


// 饿汉式
class Singletonhungry {
private:
	Singletonhungry() {
		cout << "执行操作：饿汉式构造函数被调用." << endl;
	}

public:
	static Singletonhungry* GetInstance() {
		return pSingletontest;
	}

private:
	static Singletonhungry* pSingletontest;
};
// Singletonhungry类外部初始化的时候直接创建对象
Singletonhungry* Singletonhungry::pSingletontest = new Singletonhungry;

void TestFunction1() {
	SingleTonlazy* pobj1 = SingleTonlazy::GetInstance();
	SingleTonlazy* pobj2 = SingleTonlazy::GetInstance();

	if (pobj1 == pobj2)
	{
		cout << "pobj1和pobj2两个指针指向同一块内存单元：则为单例模式." << endl;
	}
	else
	{
		cout << "pobj1和pobj2两个指针指向不是同一块内存单元：不是单例模式." << endl;
	}
}

void TestFunction2() {
	Singletonhungry* pobj1 = Singletonhungry::GetInstance();
	Singletonhungry* pobj2 = Singletonhungry::GetInstance();

	if (pobj1 == pobj2)
	{
		cout << "pobj1和pobj2两个指针指向同一块内存单元：则为单例模式." << endl;
	}
	else
	{
		cout << "pobj1和pobj2两个指针指向不是同一块内存单元：不是单例模式." << endl;
	}
}


int main()
{
	cout << "main()函数开始执行.\n" << endl;

	TestFunction1();
	TestFunction2();

	cout << "\nmain()函数结束执行.\n" << endl;

	return 0;
}