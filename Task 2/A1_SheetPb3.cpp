#include <iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

//create file to save players' name and score after close the program
fstream file;
//create a pair array to save players' name and score
pair <int,string> players[10];
//function to take players' name and score from the user
void inputPlayers()
{
    //open the file
    file.open("players.txt",ios::out);
    //take the name and score
    for(int i=0;i<10;i++)
    {
        cout<<"Enter the name : ";
        cin>>players[i].second;
        cout<<"Enter the score : ";
        cin>>players[i].first;
    }
    //sort the array from lowest to highest
    sort(players,players+10);
    //save in the file from highest to lowest
    for(int i=9;i>=0;i--)
    {
        file<<players[i].second<<"   "<<players[i].first<<endl;
    }
    //close the file
    file.close();
}

//function to add player to the list
void addPlayer()
{
    string name;
    int score;
    //take the name and score of the new player from user
    cout<<"Please enter the name of player : ";
    cin>>name;
    cout<<"Please enter the score of player : ";
    cin>>score;
    //check if the player is from top 10 or not
    for(int i=0;i<10;i++)
    {
        //if he is from top 10 add him to the list and remove the player of lowest score
        if(score >= players[i].first)
        {
            players[0].second =name;
            players[0].first =score;
        }
    }
    //sort the array
    sort(players,players+10);
    //open the file
    file.open("players.txt",ios::out);
    file<<"";
    file.close();
    //save in the file from highest to lowest
    for(int i=9;i>=0;i--)
    {
        file.open("players.txt",ios::app);
        file<<players[i].second<<"   "<<players[i].first<<endl;
        file.close();
    }
}

//function to print players
void printPlayers()
{
    char character;
    //read from the file character by character
    file.open("players.txt",ios::in);
    //while the file not ended
    while(!file.eof())
    {
        //print from the file
        file.get(character);
        cout<<character;
    }
    file.close();
}

//function to search about player
void serchPlayer()
{
    string name;
    int score = 0;
    //take the name of the player fro the user
    cout<<"please enter the player name : ";
    cin>>name;
    //search about his name in the array
    for(int i=0;i<10;i++)
    {
        //if he is found make the score = his score
        if(name == players[i].second)
        {
            score = players[i].first;
            if(score <= players[i].first)
            {
                score = players[i].first;
            }
        }
    }
    //if score = 0 it is mean he is not found
    if(score == 0)
    {
        cout<<"The player not founded in the list.\n";
    }
    //if score !=0 it is mean he is found so print his score
    else
    {
        cout<<"score = "<<score<<endl;
    }
}

//function the menu
void menu()
{
    int order;
    //ask user what he want to do
    cout<<"1-Search player in list.\n2-Add player to the list.\n3-Print the list.\n";
    cin>>order;
    //if it is invalid input take it again
    if(order !=1 && order !=2 && order !=3)
    {
        cout<<"Error. Please enter it again.\n";
        menu();
    }
    //if he choose search player call it is function
    else if(order == 1)
    {
        serchPlayer();
        menu();
    }
    //if he choose add player call it is function
    else if(order == 2)
    {
        addPlayer();
        menu();
    }
    //if he choose print the players' list call it is function
    else
    {
        printPlayers();
        menu();
    }
}

int main()
{
    inputPlayers();
    menu();
}
