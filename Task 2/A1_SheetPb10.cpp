#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//To store the words found
vector<string> words;
//Num of occurrence of the found words
int num_occurrence[30];
//The value of the found words
int value_point[30];

fstream file;
char name[100];
//Open the file and if there is file it will create one
void open_create_file()
{
    file.open(name, ios::in);
	if (file.fail())
    {
        ofstream file(name);
        cout<<"This is a new file. I created it for you \n";
    }
    else
    {
        cout << "File opened successful.\n";
        cout<<"This File Already exists. \n";
        file.close();
    }


}

// list of phishing words
string Words_list[30] = {
      "amazon", "official", "bank", "security", "urgent", "alert","important", "information", "ebay", "password",
       "credit", "verify","confirm", "account", "bill", "immediately", "address", "telephone", "safety", "charity",
       "check", "secure", "personal", "network", "ATM", "warning", "Cyber", "email", "FBI", "Paypal" };

//parallel array of point values
int phishingPoints[30] = { 1, 1, 3, 3, 2, 3, 1, 3, 1, 3,
       2, 3, 2, 1, 1, 1, 2, 2, 3, 1,
       3, 3, 2, 1, 3, 2, 1, 2, 2, 1 };
//Organize the line that will print
int one_line(string str, int phishingPoints){
    for (int i = 0; i < words.size(); i++){
                 if (str == words[i]){
                        num_occurrence[i] += 1;
                        value_point[i] = phishingPoints;

                        return 0;
                 }
    }
    words.push_back(str);

    for (int i = 0; i < words.size(); i++){
                 if (str == words[i]){
                        num_occurrence[i] += 1;
                        value_point[i] = phishingPoints;
                        return 0;
                 }
    }
}

//Print the words found and their num of occurrence and their value
void print_one_line(int total_score){
    //Print the word
    cout << setw(14) << "   The word   " << setw(10) <<  "Number of occurence" << setw(10) << "Value" <<"\n";
    //Print the words found and their num of occurrence and their value
    for (int i = 0; i < words.size(); i++){
        cout << setw(14) << words[i] << setw(10) <<  num_occurrence[i] <<"       "<< setw(10) << value_point[i] <<"\n";
    }
    //Print the score
    cout<< "\n" << "Total score: " << total_score << "\n";

}


int main()
{
    //Give the vector a size
    words.resize(30);
    string str ;
    char character_of_file;
    //The score that depends on the words found
    int total_score = 0;

    cout << "Pls input an existing file name: ";
	cin.getline(name, 100);
	strcat(name,".txt");

	//Open the file
	file.open(name, ios::in);
    //Read all contents of the file
	while(!file.eof())
	{
        //Read file char by char
		file.get(character_of_file);
		//If the character of files is space or tab or new line
        if(character_of_file == '\n' || character_of_file == ' ' || character_of_file == '.'){

            for (int i = 0; i < 30; i++){
                 if (str == Words_list[i]){
                    total_score += phishingPoints[i];
                    one_line(Words_list[i], phishingPoints[i]);
                 }
            }
            //The word end so clear the string
            str.clear();
        }
        else{
            //Store the word read by char in string
            str.push_back(character_of_file);


        }

	}

	//Close the file
	file.close();

	//Print the words found and their num of occurrence and their value
    print_one_line(total_score);
}
