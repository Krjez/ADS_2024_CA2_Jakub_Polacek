#include "TreeMap.h"
#include <fstream>
#include <string>
#include <vector>

void app1();
void app2();

int main()
{
    cout << "Hello, I am Jakub Polacek and this is my project for ADS CA2." << endl;

    bool run = true;
    string input;
    int in;

    while (run)
    {
        cout << "\nWhat application would you like to run?" << endl;
        cout << "0: Close the program." << endl;
        cout << "1: Reading text file, sorting by first letters. " << endl;
        cout << "2: CSV file with data rows." << endl;
        cout << "Please type in a number:" << endl;

        getline(cin, input); 
        try
        {
            in = stoi(input);

            switch (in)
            {
            case 0:
                run = false;
                break;
            case 1:
                app1();
                break;
            case 2:
                app2();
                break;
            default:
                cout << "Not a valid number." << endl;
                break;
            }
        }
        catch (logic_error e)
        {
            cout << "Not a number, try again." << endl;
            //cout << e.what();
        }
    }

	return 0;
}

void app1()
{
    TreeMap<char, vector<string>> dictionary;

    //50 words file, 2 words repeated - mold, egg
    ifstream file("text.txt");

    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
    }
    else
    {
        string word;
        while (getline(file, word))
        {
            if (dictionary.containsKey(word[0]))
            {
                for (string &w : dictionary.get(word[0]))
                {
                    if (!(w == word))
                    {
                        dictionary.get(word[0]).push_back(word);
                    }
                }
            }
            else
            {
                vector<string> v = { word };
                dictionary.put(word[0], v);
            }
        }

        file.close();

        cout << "Words in the file started with these letters:" << endl;
        BinaryTree<char> set = dictionary.keySet();
        set.printInOrder();
        
        try
        {
            cout << "\nChoose a letter to display all its words for:" << endl;
            string letter;
            getline(cin, letter);
            for (string s : dictionary.get(letter[0]))
            {
                cout << s << endl;
            }
        }
        catch(logic_error e)
        {
            cout << e.what() << endl;
        }
    }
    
}

void app2()
{
    cout << "?" << endl;
}