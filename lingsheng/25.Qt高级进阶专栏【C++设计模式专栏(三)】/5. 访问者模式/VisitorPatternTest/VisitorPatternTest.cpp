
#include <iostream>
#include <vector>
using namespace std;

// 具体元素（具体访问者实现accept()方法
class ConcreteElementA; 
class ConcreteElementB;

class Visitor { // 抽象访问者类
public:
    virtual void VisitConcreteElementA(ConcreteElementA *pelementA) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* pelementB) = 0;
};


class ConreteVisitor1 :public Visitor { // 具体访问者类（实现每个抽象访问者声明操作）
public:
    void VisitConcreteElementA(ConcreteElementA* pelementA);
    void VisitConcreteElementB(ConcreteElementB* pelementB);
}; 
void ConreteVisitor1::VisitConcreteElementA(ConcreteElementA* pelementA)
{
    cout << "执行ConreteVisitor1::VisitConcreteElementA(...)函数." << endl;
}
void ConreteVisitor1::VisitConcreteElementB(ConcreteElementB* pelementB)
{
    cout << "执行ConreteVisitor1::VisitConcreteElementB(...)函数." << endl;
}


class ConreteVisitor2 :public Visitor { // 具体访问者类（实现每个抽象访问者声明操作）
public:
    void VisitConcreteElementA(ConcreteElementA* pelementA);
    void VisitConcreteElementB(ConcreteElementB* pelementB);
};
void ConreteVisitor2::VisitConcreteElementA(ConcreteElementA* pelementA)
{
    cout << "执行ConreteVisitor2::VisitConcreteElementA(...)函数." << endl;
}
void ConreteVisitor2::VisitConcreteElementB(ConcreteElementB* pelementB)
{
    cout << "执行ConreteVisitor2::VisitConcreteElementB(...)函数." << endl;
}





class Element { // 抽象元素（一般是抽象类或接口，此方法以一个抽象访问者作为参数
public:
    virtual void Accept(Visitor* pvisitor) = 0;
};

class ConcreteElementA :public Element {
public:
    ConcreteElementA() {
        cout << "执行ConreteElementA()构造函数." << endl;
    }
    void Accept(Visitor* pvisitor);
};
void ConcreteElementA::Accept(Visitor* pvisitor)
{
    pvisitor->VisitConcreteElementA(this);     
}


class ConcreteElementB :public Element {
public:
    ConcreteElementB() {
        cout << "执行ConreteElementB()构造函数." << endl;
    }
    void Accept(Visitor* pvisitor);
};
void ConcreteElementB::Accept(Visitor* pvisitor)
{
    pvisitor->VisitConcreteElementB(this);
}

class ObjectStructure { // 对象结构类（是一个元素的集合，它主要用于存放元素对象，并且提供遍历其内部元素的方法
public:
    void Attach(Element* pelement);
    void Detach(Element* pelement);
    void Accept(Visitor* pvisitor);

private:
    vector<Element*> elements;
};
void ObjectStructure::Attach(Element* pelement)
{
    elements.push_back(pelement);

}
void ObjectStructure::Detach(Element* pelement)
{
    vector<Element*>::iterator it = find(elements.begin(),elements.end(),pelement);
    if (it != elements.end())
    {
        elements.erase(it);
    }
}
void ObjectStructure::Accept(Visitor* pvisitor)
{
    // 为每个element设置visitor
    for (vector<Element*>::const_iterator it = elements.begin(); it != elements.end(); it++)
    {
        (*it)->Accept(pvisitor);
    }
}


int main()
{
    ObjectStructure* pobj = new ObjectStructure;

    ConcreteElementA* pelmtA = new ConcreteElementA;
    ConcreteElementB* pelmtB = new ConcreteElementB;

    pobj->Attach(pelmtA);
    pobj->Attach(pelmtB);
    cout << endl;

    ConreteVisitor1* pvist1 = new ConreteVisitor1;
    ConreteVisitor2* pvist2 = new ConreteVisitor2;

    pobj->Accept(pvist1);
    pobj->Accept(pvist2);

    if (pvist2) delete pvist2;
    if (pvist1) delete pvist1;

    if (pelmtB) delete pelmtB;
    if (pelmtA) delete pelmtA;

    if (pobj) delete pobj;

    return 0;
}

