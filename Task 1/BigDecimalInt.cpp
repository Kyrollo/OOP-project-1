#include "BigDecimalInt.h"

//default constructor
BigDecimalInt::BigDecimalInt()
{
    str = "";
}

//parameters constructor (string)
BigDecimalInt::BigDecimalInt(string decStr)
{
    //use regex to define the number as string
    regex filter("[+-]?[1-9][0-9]*");
    //check if the input is valid or not
    if (regex_match(decStr, filter))
    {
        //if the sign is + save it in the char sign and remove it from the string
        if (decStr[0] == '+')
        {
            sign = '+';
            decStr.erase(0, 1);
        }
        //if the sign is - save it in the char sign and remove it from the string
        else if (decStr[0] == '-')
        {
            sign = '-';
            decStr.erase(0, 1);
        }
        //if there is not + or - it is by default +ve number
        else if (decStr[0] != '-' || decStr[0] != '+')
        {
            sign = '+';
        }
        //save the input in the string
        str = decStr;
    }
    //if the input is invalid print error
    else
    {
        cout << "Wrong input\n";
    }
}

//parameters constructor (integer)
BigDecimalInt::BigDecimalInt(int decInt)
{
    //turn the integer to string to save it in the string
    str = to_string(decInt);
}

//setters
void BigDecimalInt::setStr(string decStr)
{
    str = decStr;
}

void BigDecimalInt::setSign(char sgn)
{
    sign = sgn;
}

//getters
string BigDecimalInt::getStr()
{
    return str;
}

char BigDecimalInt::getSign()
{

    return sign;
}

//plus function
string BigDecimalInt::pluss(string num1, string num2)
{

    string res = "";
    int sum, carry = 0;
    //make the two numbers have the same size
    if (num1.size() > num2.size()) {
        while (num1.size() > num2.size())
        {
            num2 = '0' + num2;
        }
    }

    else if (num1.size() < num2.size()) {
        while (num1.size() < num2.size())
        {
            num1 = '0' + num1;
        }
    }
    //for each number in the string add it to the corresponding number
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        sum = 0;
        sum = (num1[i] - 48) + (num2[i] - 48) + carry;
        //if the sum of the two numbers is greater than 10 subtract 10 and carry 1
        if (sum >= 10)
        {
            sum -= 10;
            res += to_string(sum);
            carry = 1;
        }
        //else make carry=0
        else
        {
            carry = 0;
            res += to_string(sum);
        }
    }
    //if carry = 0 add 1 to the result
    if (carry == 1)
    {
        res += to_string(carry);
    }
    //reverse the result
    for (int i = 1; i < res.size(); i++)
    {
        char ch = res[i];
        res[i] = res[res.size() - 1 - i];
        res[res.size() - 1 - i] = ch;

    }
    //return result
    return res;
}

//operator overloading +
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    BigDecimalInt num;
    //if the two numbers have the same sign add them
    if (this->getSign() == anotherDec.getSign())
    {
        num.setSign(this->getSign());
        num.setStr(pluss(this->getStr(), anotherDec.getStr()));
        return num;
    }
    //if the two numbers have not the same sign subtract them
    else if (this->getSign() != anotherDec.getSign())
    {
        return minuss(this->getStr(),anotherDec.getStr());
    }
}

string BigDecimalInt::minuss(string num1,string num2){
    //To store the result
    string res="";
    int sum,case_num;

    char num1_sign, num2_sign;
    //Know the sign of the two numbers
    num1_sign = BigDecimalInt::getSign();
    num2_sign = BigDecimalInt::getSign();
    //Equate the length of the two numbers
     if (num1.size() > num2.size()){
        while(num1.size() > num2.size())
    {
        num2 ='0'+num2;
    }
    }

    else if (num1.size() < num2.size()){
        while(num1.size() < num2.size())
    {
        num1 ='0'+num1;
    }
    }
    //If the first number is positive & the second number is positive
    if(num1_sign != '-' && num2_sign != '-'){

        //Determine the biggest number
        for (int i = 0; i <= num1.size() - 1; i++){
            //If the first number is greater than the second number
            if(num1[i] > num2[i]){
                case_num = 1;
                break;
            }
            //If the first number is smaller than the second number
            else if(num1[i] < num2[i]){
                case_num = 2;
                num1.swap(num2);
                break;
            }
            //If the first number is equal to the second number
            else if(num1[i] == num2[i]){
                case_num = 3;
            }
        }
    }

    //If the first number is negative & the second number is negative
     else if (num1_sign == '-' && num2_sign == '-'){
        //Determine the biggest number
        for (int i = 0; i <= num1.size() - 1; i++){
            //If the first number is smaller than the second number
            if(num1[i] < num2[i]){
                case_num = 1;
                num1.swap(num2);
                break;
            }
            //If the first number is greater than the second number
            else if(num1[i] > num2[i]){
                case_num = 2;
                break;
            }
            //If the first number is equal to the second number
            else if(num1[i] == num2[i]){
                case_num = 3;
            }
        }
    }

    //If the first number is greater than the second number
    if (case_num == 1){
    for (int i = num1.size() - 1; i >= 0; i--){
        sum = 0;
        sum = num1[i] - num2[i];
        if (sum < 0){
            for (int j = i - 1; j >= 0; j--){
                if ( num1[j] >= 1){
                    num1[j] -= 1;
                    sum += 10;
                    break;
                }
                else {
                    num1[j] = 9;
                }
            }

        }
        res += to_string(sum);
    }
    }

    //If the first number is smaller than the second number
    if (case_num == 2){

        for (int i=num1.size()-1; i>=0; i--){
        sum =0;
        sum = num1[i] - num2[i];
        if (sum < 0){
            for (int j = i - 1; j >= 0; j--){
                if ( num1[j] >= 1){
                    num1[j] -= 1;
                    sum += 10;
                    break;
                }
                else {
                    num1[j] = 9;
                }
            }

        }
        res += to_string(sum);
    }
    res += '-';
    }
    //If the first number is equal to the second number
    if (case_num == 3){
        res = '0';
    }
    //Reverse the string
    reverse(res.begin(), res.end());
    //Return the result
    return res;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){
    BigDecimalInt num;
    //If the two numbers has the same sign
    if(this->getSign() == anotherDec.getSign())
    {
        num.setSign(this->getSign());
        num.setStr(minuss(this->getStr(),anotherDec.getStr()));
        return minuss(this->getStr(),anotherDec.getStr());
    }
    //If the first number is positive & the second number is negative
    else if(this->getSign() != '-' && anotherDec.getSign() == '-')
    {
        num.setSign(this->getSign());
        num.setStr(pluss(this->getStr(),anotherDec.getStr()));
        return this->getSign(),pluss(this->getStr(),anotherDec.getStr());
    }
    //If the first number is negative & the second number is positive
    else if(this->getSign() == '-' && anotherDec.getSign() != '-')
    {
        num.setSign(this->getSign());
        num.setStr(pluss(this->getStr(),anotherDec.getStr()));
        return num.getSign(),pluss(this->getStr(),anotherDec.getStr());
    }
}

bool BigDecimalInt::smaller(string num1,string num2){
    int case_num;
    char num1_sign, num2_sign;
    //Know the sign of the two numbers
    num1_sign = BigDecimalInt::getSign();
    num2_sign = BigDecimalInt::getSign();
    //Equate the length of the two numbers
    if (num1.size() > num2.size()){
        while(num1.size() > num2.size())
    {
        num2 ='0'+num2;
    }
    }

    else if (num1.size() < num2.size()){
        while(num1.size() < num2.size())
    {
        num1 ='0'+num1;
    }
    }

    //If the first number is positive & the second number is positive
    if(num1_sign != '-' && num2_sign != '-'){

        //Determine the biggest number
        for (int i = 0; i <= num1.size() - 1; i++){
            //If the first number is greater than the second number
            if(num1[i] > num2[i]){
                case_num = 2;
                break;
            }
            //If the first number is smaller than the second number
            else if(num1[i] < num2[i]){
                case_num = 1;
                break;
            }
            //If the first number is equal to the second number
            else if(num1[i] == num2[i]){
                case_num = 2;
            }
        }
    }

    //If the first number is negative & the second number is negative
     if (num1_sign == '-' && num2_sign == '-'){

        for (int i = 0; i <= num1.size() - 1; i++){
            //If the first number is smaller than the second number
            if(num1[i] < num2[i]){
                case_num = 2;
                break;
            }
            //If the first number is greater than the second number
            else if(num1[i] > num2[i]){
                case_num = 1;
                break;
            }
            //If the first number is equal to the second number
            else if(num1[i] == num2[i]){
                case_num = 2;
            }
        }
    }
    if (case_num == 1){
        return 1;
    }
    if (case_num == 2){
        return 0;
    }
}

 bool BigDecimalInt::operator<(BigDecimalInt anotherDec){
    BigDecimalInt num;

    //If the first number is negative & the second number is negative
    if(this->getSign() == '-' && anotherDec.getSign() == '-')
    {
        num.setSign(this->getSign());
        return smaller(this->getStr(),anotherDec.getStr());
    }

    //If the first number is positive & the second number is positive
    else if(this->getSign() != '-' && anotherDec.getSign() != '-')
    {
        if(this->getSign() == anotherDec.getSign()){
            num.setSign(this->getSign());
            return smaller(this->getStr(),anotherDec.getStr());
        }
    }

    //If the first number is positive & the second number is negative
    else if(this->getSign() != '-' && anotherDec.getSign() == '-')
    {
        return 0;
    }

    //If the first number is negative & the second number is positive
    else if(this->getSign() == '-' && anotherDec.getSign() != '-')
    {
        return 1;
    }
}
//-------------------------------------------------------- greater
//here we see if num1 greater than num2 or not
bool BigDecimalInt::greaterr(string num1, string num2) {
    int case_num; //case num to check with it the case so the compiler can tell us if num1 is grater than num2 or not
    char num1_sign, num2_sign;

    num1_sign = BigDecimalInt::getSign();
    num2_sign = BigDecimalInt::getSign();

    //here we make the size of the two numbers equal so we can deal with it easily
    if (num1.size() > num2.size()) {
        while (num1.size() > num2.size())
        {
            num2 = '0' + num2;
        }
    }

    else if (num1.size() < num2.size()) {
        while (num1.size() < num2.size())
        {
            num1 = '0' + num1;
        }
    }
    if (num1_sign != '-' && num2_sign != '-') {

        //Determine the biggest number by iterate with the for loop
        for (int i = 0; i <= num1.size() - 1; i++) {
            //if we found that the number of num1[i] > num2[i] so the case num will equal 1 which means that num1 greater than num2
            if (num1[i] > num2[i]) {
                case_num = 1;
                break;
            }
            //if we found that the number of num1[i] < num2[i] so the case num will equal 2 which means that num1 less than num 2 not greater
            else if (num1[i] < num2[i]) {
                case_num = 2;
                break;
            }
            //if we found that the number of num1[i] == num2[i] so the case num will equal 2 which means that num1 equal num 2 not greater
            else if (num1[i] == num2[i]) {
                case_num = 2;
            }
        }
    }


    //-ve , -ve
    if (num1_sign == '-' && num2_sign == '-') {

        for (int i = 0; i <= num1.size() - 1; i++) {
            if (num1[i] < num2[i]) {
                case_num = 1;
                break;
            }
            else if (num1[i] > num2[i]) {
                case_num = 2;
                break;
            }
            else if (num1[i] == num2[i]) {
                case_num = 2;
            }
        }
    }
    //if the case num == 1 return 1 which means true that num1 is greater than num2
    if (case_num == 1) {
        return 1;
    }
    //if the case num == 2 return 0 which means false that num1 is greater than num2
    if (case_num == 2) {
        return 0;
    }
}

//here we overloads operator >
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    BigDecimalInt num;

    //-ve & -ve
    if (this->getSign() == '-' && anotherDec.getSign() == '-')
    {
        num.setSign(this->getSign());
        return greaterr(this->getStr(), anotherDec.getStr());
    }

    //+ve & +ve
    else if (this->getSign() != '-' && anotherDec.getSign() != '-')
    {
        if (this->getSign() == anotherDec.getSign()) {
            num.setSign(this->getSign());
            return greaterr(this->getStr(), anotherDec.getStr());
        }
    }

    //+ve & -ve
    else if (this->getSign() != '-' && anotherDec.getSign() == '-')
    {
        return 1;
    }

    //-ve & +ve
    else if (this->getSign() == '-' && anotherDec.getSign() != '-')
    {
        return 0;
    }
}
//----------------------------------------------------------------- equal equal
// this function see if the two number given are equal or not
bool BigDecimalInt::equalequal(string num1, string num2) {

    int case_num; //case num to check with it the case so the compiler can tell us if they are equal or not
    char num1_sign, num2_sign;

    num1_sign = BigDecimalInt::getSign();
    num2_sign = BigDecimalInt::getSign();
    //here we make the size of the two numbers equal so we can deal with it easily
    if (num1.size() > num2.size()) {
        while (num1.size() > num2.size())
        {
            num2 = '0' + num2;
        }
    }

    else if (num1.size() < num2.size()) {
        while (num1.size() < num2.size())
        {
            num1 = '0' + num1;
        }
    }
    if (num1_sign != '-' && num2_sign != '-') {

        //Determine the numbers by the for loop
        for (int i = 0; i <= num1.size() - 1; i++) {
            //if we found that the number of num1[i] > num2[i] so the case num will equal 2 and they are not equal

            if (num1[i] > num2[i]) {
                case_num = 2;
                break;
            }
            //if we found that the number of num1[i] < num2[i] so the case num will equal 2 and they are not equal
            else if (num1[i] < num2[i]) {
                case_num = 2;
                break;
            }
            ////if we found that the number of num1[i] == num2[i] so the case num will equal  and they are equal
            // when the cas num = 1 so it will return 1 which mean true the two numbers are equal
            else if (num1[i] == num2[i]) {
                case_num = 1;
            }
        }
    }

    //-ve , -ve
    if (num1_sign == '-' && num2_sign == '-') {

        for (int i = 0; i <= num1.size() - 1; i++) {
            if (num1[i] < num2[i]) {
                case_num = 2;
                break;
            }
            else if (num1[i] > num2[i]) {
                case_num = 2;
                break;
            }
            else if (num1[i] == num2[i]) {
                case_num = 1;
            }
        }
    }
    //if the case num == 1 return 1 which means true that num1 equal num2
    if (case_num == 1) {
        return 1;
    }
    //if the case num == 2 return 0 which means false that num1 equal num2
    if (case_num == 2) {
        return 0;
    }
}

//here we overloads the operator ==
bool BigDecimalInt::operator== (BigDecimalInt anotherDec) {
    BigDecimalInt num;

    //-ve & -ve
    if (this->getSign() == '-' && anotherDec.getSign() == '-')
    {
        num.setSign(this->getSign());
        return equalequal(this->getStr(), anotherDec.getStr());
    }

    //+ve & +ve
    else if (this->getSign() != '-' && anotherDec.getSign() != '-')
    {
        if (this->getSign() == anotherDec.getSign()) {
            num.setSign(this->getSign());
            return equalequal(this->getStr(), anotherDec.getStr());
        }
    }

    //+ve & -ve
    else if (this->getSign() != '-' && anotherDec.getSign() == '-')
    {
        return 1;
    }

    //-ve & +ve
    else if (this->getSign() == '-' && anotherDec.getSign() != '-')
    {
        return 0;
    }
}

//-------------------------------------------------------- equal
string BigDecimalInt::equall(string num1, string num2) {
    // since we deal with string and we want to make num1 = num2 so we can equal them easily
    // the value in num2 be in num1
    num1 = num2;
    return num1;
}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) { // overloading to the operator =
    // if the sign of num2 +
    if (anotherDec.getSign() != '-') {
        this->setSign(anotherDec.getSign());
        this->setStr(equall(this->getStr(), anotherDec.getStr()));
        return this->getSign(),this->getStr();
    }
    // if the sign of num2 is -
    else if (anotherDec.getSign() == '-') {
        this->setSign(anotherDec.getSign());
        this->setStr(equall(this->getStr(), anotherDec.getStr()));
        return this->getSign(),this->getStr(); // we take the sign of num2 first
    }
}

// to declare the size of the string (num)

int BigDecimalInt::int_size(string num1) {
    return num1.size();

}

ostream& operator << (ostream& out, BigDecimalInt num)
{
    cout << num.sign << num.str;
}
