#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;


class BigDecimalInt
{
private:
    string str;
    char sign;
public:
    BigDecimalInt();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    void setStr(string decStr);
    void setSign(char sgn);
    string getStr();
    char getSign();
    string pluss(string num1, string num2);
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    string minuss(string num1,string num2);
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    bool smaller(string num1,string num2);
    bool  operator< (BigDecimalInt anotherDec);
    bool  operator> (BigDecimalInt anotherDec);
    bool greaterr(string num1, string num2);
    bool operator== (BigDecimalInt anotherDec);
    bool equalequal(string num1, string num2);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    string equall(string num1, string num2);
    friend ostream& operator << (ostream& out, BigDecimalInt num);
    int int_size(string num1);
};

#endif // BIGDECIMALINT_H
