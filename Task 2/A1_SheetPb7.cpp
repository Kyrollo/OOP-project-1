#include <string>
#include <iostream>
using namespace std;
//The rules of the play
bool give_bears(int num_bears){
     int test = (num_bears % 10) * ((num_bears / 10) % 10);
     //The num of bears is equal 42
     if(num_bears == 42) {
        cout << "Number of bears is " << num_bears << " give nothing\n";
        return true;
     }
     //The num of bears is less than 42
     else if (num_bears < 42){
        return false;
     }
     //The num of bears is divisble by 5
     else if((num_bears % 5 == 0) && give_bears (num_bears - 42))
     {
        cout << "Number of bears is " << num_bears << " give 42\n";
        return true;
     }
     //The num of bears is divisble by 3 or 4
     else if ((num_bears % 4 == 0 || num_bears % 3 == 0) && test && give_bears (num_bears - test))
     {
        cout << "Number of bears is " << num_bears << " give "<<  test  << "\n";
        return true;
     }
    //The num of bears is even
     else if ((num_bears % 2 == 0) && give_bears (num_bears / 2))
     {
         cout << "Number of bears is " << num_bears << " give " << (num_bears /2) << endl;
         return true;
     }
     else
        return false;
}

int main()
{
    int num_bears;
    cout << "Write the number of bears: ";
    cin >> num_bears;
    while(true){
        //If the user win
        if (give_bears(num_bears)){
            cout << "you win\n";
            break;
        }
        //If the user lost
        else if (num_bears < 42){
            cout << "You lose\n";
            break;
        }
        //The user keep playing
        else{
            cout << "keep trying\n";
        }
    system("pause");
    //The user keep playing so the user try again
    cout << "Write the number of bears: ";
    cin >> num_bears;
    }
    return 0;
}
