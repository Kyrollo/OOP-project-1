#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//check if the number is power of 2 or not
bool powOF2(int num)
{
    //for integer i=1 to i less than the number check if the number power of 2
    for(int i=1;i<num;i++)
    {
        //if the number power of 2 return true
        if(pow(2,i)==num)
        {
            return true;
        }
    }
    //after the for loop it did not return true then return false
    return false;
}

static void pattern( int n, int i )
{
    //if row =0 return and get out from the function
    if ( i == 0 )
    {
        return;
    }
    //draw the first half of the pattern
    pattern( n, i / 2 );
    for ( int j = 0; j < n  ; j++ )
        cout << "  ";
    for ( int j = 0; j < i; j++ )
        cout << "* ";
    cout << endl;
    //to draw the second half of the pattern call the function again
    pattern( n + i / 2, i / 2 );
}



int main()
{
    //number of rows
   int n;
   cout << "Enter n (a power of 2): ";
   //input the number of rows
   cin >> n;
   //while the input is invalid enter it again
   while(!powOF2(n))
   {
        cout << "Error. Enter n (a power of 2): ";
        cin >> n;
   }
   //call the function to draw the pattern
   pattern(0,n);
}
