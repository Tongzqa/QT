
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 迭代抽象类
class Iterator {
public:
    Iterator() {}
    virtual ~Iterator(){}

    virtual string First() = 0;
    virtual string Next() = 0;
    virtual string CurrentItem() = 0;
    virtual bool IsDone() = 0;
};


// 聚集抽象类
class Aggregate {
public:
    virtual int Count() = 0;
    virtual void Push(const string& strvalue) = 0;
    virtual string Pop(const int nindex) = 0;
    virtual Iterator* CreateIterator() = 0;
};

// 具体迭代器类，继承Iterator实现
class ConcreteIterator :public Iterator {
public:
    ConcreteIterator(Aggregate* paggreate) :mncurrent(0), Iterator() {
        maggreate = paggreate;
    }

    string First() {
        return maggreate->Pop(0);
    }

    string Next() {
        string strRet;
        mncurrent++;
        if (mncurrent < maggreate->Count())
        {
            strRet = maggreate->Pop(mncurrent);
        }

        return strRet;
    }

    string CurrentItem()
    {
        return maggreate->Pop(mncurrent);
    }

    bool IsDone() {
        return ((mncurrent >= maggreate->Count()) ? true : false);
    }

private:
    int mncurrent;
    Aggregate* maggreate;
};

// 具体聚集类 继承
class ConcreteAggregate :public Aggregate {
public:
    ConcreteAggregate() :mpiterator(NULL) {
        mvecitems.clear();
    }


    ~ConcreteAggregate() {
        if (mpiterator != NULL) {
            delete mpiterator;
            mpiterator = NULL;
        }        
    }

    Iterator* CreateIterator() {
        if (mpiterator == NULL) {
            mpiterator = new ConcreteIterator(this);
       }
        return mpiterator;        
    }

    int Count()
    {
        return mvecitems.size();
    }

    void Push(const string& strValue)
    {
        mvecitems.push_back(strValue);
    }

    string Pop(const int nIndex)
    {
        string strRet;
        if (nIndex < Count())
        {
            strRet = mvecitems[nIndex];
        }

        return strRet;
    }


private:
    vector<string> mvecitems;
    Iterator* mpiterator;
};



int main()
{
    ConcreteAggregate* pstr = NULL;
    pstr = new ConcreteAggregate();

    cout << "\n\n";
    if (pstr != NULL)
    {
        pstr->Push("How are you：");
        pstr->Push("How do you do：");
        pstr->Push("What is you name：");
    }
    
    Iterator* it = NULL;
    it = pstr->CreateIterator();

    if (it != NULL)
    {
        string stritem = it->First();
        while (!it->IsDone())
        {
            cout << it->CurrentItem() << " is OK." << endl;
            it->Next();
        }
    }

    cout << "\n\n";

    return 0;
}

