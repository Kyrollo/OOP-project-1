#include "BigDecimalInt.h"


int main()
{
    BigDecimalInt num1("10");
    BigDecimalInt num2("40");
    BigDecimalInt num3("-5");
    BigDecimalInt num4("-30");
    //poerator +
    // +ve + +ve
    cout<<num1<<" + "<<num2<<" = "<<num1 + num2<<endl;
    // -ve + -ve
    cout<<num3<<" + "<<num4<<" = "<<num3 + num4<<endl;
    // +ve + -ve
    cout<<num1<<" + "<<num4<<" = "<<num1 + num4<<endl;
    // -ve + +ve
    cout<<num4<<" + "<<num2<<" = "<<num4 + num2<<endl;

    //operator -
    // +ve - +ve
    cout<<num1<<" - "<<num2<<" = "<<num1 - num2<<endl;
    // -ve - -ve
    cout<<num3<<" - "<<num4<<" = "<<num3 - num4<<endl;
    // +ve - -ve
    cout<<num1<<" - "<<num4<<" = "<<num1 - num4<<endl;
    //-ve - +ve
    cout<<num3<<" - "<<num1<<" = "<<num3 - num1<<endl;

    //operator >
    cout<< (num1>num3)<<endl;
    //operator >
    cout<< (num1<num3)<<endl;

    //operator ==
    cout<<(num2 == num3)<<endl;

    BigDecimalInt num5;
    num5 = num1;

    cout<<num5<<endl;
}
