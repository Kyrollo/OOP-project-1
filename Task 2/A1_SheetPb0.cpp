#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>
using namespace std;

//function that make the first letter capital

void upper_first_letter(string& str) {
    if (str.length() == 0) {
        return;
    }
    str[0] = toupper(str[0]);
  
}
 //function that loops on every character in the string and make it small if it is capital
void lower_sentence(string& str) {
    for (int i = 1; i <= (str.length() - 1); i++) {
        str[i] = tolower(str[i]);
    }
}

//function that loops on ths string if found that two elements sequence in the string are space delete on on them
void delete_spaces(string& str) {
    for (int i = 0; i <= (str.length() - 1); i++) {
        if (str[i] == ' ' & str[i+1] == ' ') {
            str.erase(str.begin() + i);
            i--;

        }
    }
}
//in the main we call the three function and take the string from the user that we make on it the three functions
int main()
{
    string str;
    cout << "please enter a sentence " << endl;
    getline(cin,str) ;
    upper_first_letter(str);
    lower_sentence(str);
    delete_spaces(str);
    cout << str << endl;
}