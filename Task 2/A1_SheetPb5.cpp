#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Domino
{
    // init instance attributes
    private:
        int left_dots;
        int right_dots;


    public:
        Domino(int domino_left_dots, int domino_right_dots)           // constructor
        {   
            left_dots = domino_left_dots;
            right_dots = domino_right_dots;
        }


        // operator overloading  <<
        friend ostream &operator<<(ostream &ost, const Domino &d)
        {
            ost << d.left_dots << "|" << d.right_dots;
            return ost;
        }


        // instance methods         
        // setters
        void set_left_dots(int new_left_dots)
        {
            left_dots = new_left_dots;
        }

        void set_right_dots(int new_right_dots)
        {
            right_dots = new_right_dots;
        }

        // getters >>> encapsulation
        int get_left_dots()
        {
            return left_dots;
        }

        int get_right_dots()
        {
            return right_dots;
        }

};

// functions declartions
void print_domio_from_chain(vector<Domino> &user_domino);
bool form_domino_chain(vector<Domino> &dominos);


int main()
{
    int n_of_d;
    cout << "n_of_d: ";
    cin >> n_of_d;

    vector<Domino> user_domino;
    for (int i = 0; i < n_of_d; ++i)
    {
        int std_left_dots, std_right_dots;
        
        cout << "left_dots and right_dots: ";
        cin >> std_left_dots >> std_right_dots;
        
        Domino d(std_left_dots, std_right_dots);
        user_domino.push_back(d);
    }

    if(form_domino_chain(user_domino))
    {
        cout << "yes you can form chain" << endl;
    }
    else
    {
        cout << "NO YOU CAN't !!" << endl;
    }
    print_domio_from_chain(user_domino);


    return 0;
}

// functions definations
void print_domio_from_chain(vector<Domino> &user_domino)
{
    // get all dominos
    for (int i = 0; i < user_domino.size(); ++i)
    {
        Domino d = user_domino[i];
        cout << d;

        if (i == user_domino.size() - 1)
        {
           break; 
        }
        cout << " - ";
    }
}

// class methods
bool form_domino_chain(vector<Domino> &dominos)
{

    // assuming dominos can't form a chain
    bool can_form_chain = true, is_there_next = false;
    int counter = 0;

    // iterate over each domino
    for (int i = 0; i < dominos.size(); ++i)
    {
        Domino org = dominos[i];

        // iteratve over all next dominos 
        for (int j = i + 1; j < dominos.size(); ++j)
        {
            // if there is any domino_left_dots == org_right: swap those two dominos
            if (org.get_right_dots() == dominos[j].get_left_dots())
            {
                swap(dominos[i + 1], dominos[j]);
                is_there_next = true;
                break;
            }  
        }

        // if it wan't able to find next for the prevouis org then quit
        if (!is_there_next)
        {
            can_form_chain = false;
            break;
        }

        // restore is there next for checking of next org
        is_there_next = false;

    }
    cout << counter << endl;

    return can_form_chain;     // return value of function
}