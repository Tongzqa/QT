
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 抽象表达式类
class Expression {
public:
    virtual ~Expression(){}
    virtual double interpreter(unordered_map<string, double>var) = 0;
};

// 变量解析器类
class VarExpression :public Expression {
public:
    VarExpression(string key) :mkey(key){}

    double interpreter(unordered_map<string, double>var) override {
        return var[mkey];
    }

private:
    string mkey;
};

// 抽象运算符号解析器
class SymbolExpression :public Expression {
public:
    SymbolExpression(Expression* left, Expression* right):mleft(left),mright(right){}

protected:
    Expression* mleft;
    Expression* mright;
};

// 设计加法解释器
class AddExpression :public SymbolExpression {
public:
    AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}

    double interpreter(unordered_map<string, double> var)override {
        return mleft->interpreter(var) + mright->interpreter(var);
    }
};

// 设计减法解释器
class SubExpression :public SymbolExpression {
public:
    SubExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}

    double interpreter(unordered_map<string, double> var)override {
        return mleft->interpreter(var) - mright->interpreter(var);
    }
};


// 设计解析器封装类
class Calculator {
public:
    Calculator(vector<string> expstr) {
        stack<Expression*> stack;
        Expression* left;
        Expression* right;

        for (int i = 0; i < expstr.size(); i++) {
            if (expstr[i] == "+") { // 加法操作
                left = stack.top(), stack.pop();
                right = new VarExpression(expstr[++i]);
                stack.push(new AddExpression(left, right));
            }
            else if (expstr[i] == "-") { // 减法操作
                left = stack.top(), stack.pop();
                right = new VarExpression(expstr[++i]);
                stack.push(new SubExpression(left, right));
            }
            else // 变量
            {
                stack.push(new VarExpression(expstr[i]));
            }
        }

        this->mpression = stack.top();
    }

    double run(unordered_map<string, double>var) {
        return this->mpression->interpreter(var);
    }

private:
    Expression* mpression;
};

// 客户端
// 获取表达式
void getexpstr(vector<string>& expstr) {
    cout << "\n请输入算术表达式:" << endl;
    string str;
    int currentindex = 0;
    getline(cin, str);
    string temp;
    int len = 0;

    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
        case '+':
            len = i - currentindex;
            temp = str.substr(currentindex, len);

            // 多余的空格处理
            temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
            expstr.push_back(temp);
            expstr.push_back("+");
            currentindex = i + 1;
            break;

        case '-':
            len = i - currentindex;
            temp = str.substr(currentindex, len);

            // 多余的空格处理
            temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
            expstr.push_back(temp);
            expstr.push_back("-");
            currentindex = i + 1;
            break;
        }
    }

    temp = str.substr(currentindex);
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    expstr.push_back(temp);
}

void getvalue(unordered_map<string, double>& var, vector<string>& expstr) {
    for (const auto& key : expstr) {
        if (key != "+" && key != "-") {
            if (var.find(key) == var.end()) {
                cout << "请输入" << key << " 的值:" << endl;
                cin >> var[key];
            }
        }
    }
}

string vector_to_string(vector<string>& expStr) {
    string str;
    for (const auto& expstr : expStr) {
        str.append(expstr);
        str.append(" ");
    }
    str.pop_back();

    return str;
}


int main()
{
    vector<string> expstr;
    unordered_map<string, double> var;
    getexpstr(expstr);
    getvalue(var, expstr);

    Calculator* calc = new Calculator(expstr);

    cout << "\n表达式计算结果为:" << vector_to_string(expstr) << " = " << calc->run(var) << endl;

    return 0;
}


