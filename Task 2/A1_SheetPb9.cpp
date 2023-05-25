#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

//create two files
fstream file1;
fstream file2;
char filename1[100],filename2[100];

//open the files
void openFiles()
{
    file1.open(filename1,ios::in);
    file2.open(filename2,ios::in);
    if(file1.fail())
    {
        ofstream file1(filename1);
    }
    if(file2.fail())
    {
        ofstream file2(filename2);
    }
    file1.close();
    file2.close();
}

//comparison by character
void comparisonBychar()
{
    //open the two files
    file1.open(filename1,ios::in);
    file2.open(filename2,ios::in);
    char character1,character2;
    //while the files not end
    while(!file1.eof() || !file2.eof())
    {
        file1.get(character1);
        file2.get(character2);
        //if the char from file1 not = the char from file2 then the files are not same and get out from the function
        if(character1 != character2 )
        {
            cout<<"files are not the same\n";
            file1.close();
            file2.close();
            return;
        }
    }
    //if you are in the function then the files are the same
    cout<<"files are same\n";
    file1.close();
    file2.close();
}

//comparison by word
void comparisonByword()
{
    //open the two files
    file1.open(filename1,ios::in);
    file2.open(filename2,ios::in);
    string word1,word2;
    //while the files not end
    while(!file1.eof() || !file2.eof())
    {
        file1>>word1;
        file2>>word2;
        //if the word from file1 not = the word from file2 then the files are not same and get out from the function
        if(word1 != word2 )
        {
            cout<<"files are not the same\n";
            file1.close();
            file2.close();
            return;
        }
    }
    //if you are in the function then the files are the same
    cout<<"files are same\n";
    file1.close();
    file2.close();
}

//function menu
void choose()
{
    int order;
    //ask the user what he want to do
    cout<<"Please choose what you want.\n1-Comparison by char.\n2-Comparison by word.\n3-End.\n";
    cin>>order;
    //if the input is invalid take it again
    if(order !=1 && order !=2 && order !=3)
    {
        cout<<"Error please choose again.\n";
        choose();
    }
    //if he choose comparison by character call its function
    else if(order == 1)
    {
        comparisonBychar();
        choose();
    }
    //if he choose comparison by word call its function
    else if (order == 2)
    {
        comparisonByword();
        choose();
    }
    //if he choose end close the program
    else if(order == 3)
    {
        cout<<"End.\n";
        return;
    }
}

int main()
{
    cout<<"Please enter the name of first file : ";
    cin>>filename1;
    strcat(filename1,".txt");
    cout<<"Please enter the name of the second file : ";
    cin>>filename2;
    strcat(filename2,".txt");
    openFiles();
    choose();
}
