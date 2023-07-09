
#include <iostream>
using namespace std;

// Subject：目标接口
class Person {
public:
	virtual void RentHouse() = 0;
};

//realSubject：具体的目标对象
class Amy :public Person {
public:
	void RentHouse() {
		cout << "Amy想要租房：一套豪华别墅。" << endl;
	}
};

//realSubject：具体的目标对象
class Sunny :public Person {
public:
	void RentHouse() {
		cout << "Sunny想要租房：一套豪华别墅。" << endl;
	}
};

// Proxy：代理对象
class Proxy :public Person {
public:
	Proxy(Person* person) :objPerson(person) {
		cout << "调用Proxy代理对象类的构造函数。" << endl;
	}
	void RentHouse() {
		objPerson->RentHouse();

		cout << "解决方案：找Proxy中介公司来代理找豪华别墅。" << endl;
	}

private:
	Person* objPerson;
};

int main()
{
	Person* amy = new Amy;
	Person* proxyamy1 = new Proxy(amy);
	proxyamy1->RentHouse();
	cout << endl;

	Person* sunny = new Sunny;
	Person* proxyamy2 = new Proxy(sunny);
	proxyamy2->RentHouse();
	cout << endl;

	return 0;
}

