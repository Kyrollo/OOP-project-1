#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//To save the last position
int past=0;

static void binaryPrint(int n){
    //Print the last digit and finish the function
    if (n <= 1){
        cout << n;
        return;
    }
    //Call the funtion
    binaryPrint(n / 2) ;
    //Print the digit of the number
    cout << n % 2;
}

void numbers(string prif,int k) {
    //To least the k by one
    int i=k-1;
    //To know the last position
    int l=0;
    if (i!=0) {
        numbers(prif+"0",i);
    }
    //Print the prefix and the number of combination
    for(int j=past; j<pow(2,i+1); j++) {
        cout<<prif;binaryPrint(j);cout<<endl;
        l=j;
    }
    //Save the last position
    past=l+1;
    return;
}
int main()
{
    int n = 3;
    string prefix = "k";
    binaryPrint(n);
    numbers(prefix, n);
}
