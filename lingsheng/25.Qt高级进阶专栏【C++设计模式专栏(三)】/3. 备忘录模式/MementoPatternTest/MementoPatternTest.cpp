
#include <iostream>
#include <string>
using namespace std;

class Memento {  // 备忘录
public:
    Memento(string name, int age) {
        this->mname = name;
        this->mage = age;
    }

    string getname() {
        return mname;
    }
    int agetage() {
        return mage;
    }

    void setname(string name) {
        this->mname = name;
    }
    void setage(int age) {
        this->mage = age;
    }

private:
    string mname;
    int mage;
};


class Person { // 原发器
public:
    Person(string name, int age) {
        this->mname = name;
        this->mage = age;
    }

    string getname() {
        return mname;
    }
    int agetage() {
        return mage;
    }

    void setname(string name) {
        this->mname = name;
    }
    void setage(int age) {
        this->mage = age;
    }

    Memento* creatememento() {
        return new Memento(mname, mage);
    }

    void setmemento(Memento* memento) {
        this->mname = memento->getname();
        this->mage = memento->agetage();
    }

    void dispfunc() {
        cout << "姓名:" << mname << ",年龄:" << mage << endl;
    }


private:
    string mname;
    int mage;
};


class Caretaker { // 备忘录管理者
public:
    Caretaker(Memento* memto) {
        this->mmemento = memto;
    }

    Memento* getMemento() {
        return this->mmemento;
    }

    void setmemento(Memento* memto) {
        this->mmemento = memto;
    }

private:
    Memento* mmemento;
};


int main()
{
    Person* p = new Person("张三", 22);
    p->dispfunc();

    Caretaker* caretaker = new Caretaker(p->creatememento());
    p->setname("王刚");
    p->dispfunc();

    p->setmemento(caretaker->getMemento());
    p->dispfunc();

    delete caretaker;
    delete p;

    return 0;
}

