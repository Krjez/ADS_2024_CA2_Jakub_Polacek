#include "TreeMap.h"
#include "MTGSet.h"
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
        cout << "2: CSV file of MTG sets with data rows." << endl;
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
                bool unique = true;
                for (string &w : dictionary.get(word[0]))
                {
                    if (w == word)
                    {
                        unique = false;
                    }
                }

                if (unique)
                {
                    dictionary.get(word[0]).push_back(word);
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
    bool run = true;
    string input;
    int in;

    while (run)
    {
        cout << "\nWhat field do you want to create an index on?" << endl;
        cout << "0: Return to the main menu." << endl;
        cout << "1: baseSetSize" << endl;
        cout << "2: block" << endl;
        cout << "3: cardsphereSetId" << endl;
        cout << "4: isFoilOnly" << endl;
        cout << "5: isForeignOnly" << endl;
        cout << "6: isNonFoilOnly" << endl;
        cout << "7: isOnlineOnly" << endl;
        cout << "8: isPartialPreview" << endl;
        cout << "9: keyruneCode" << endl;
        cout << "10: languages" << endl;
        cout << "11: mcmId" << endl;
        cout << "11: mcmIdExtras" << endl;
        cout << "12: mcmName" << endl;
        cout << "13: mtgoCode" << endl;
        cout << "14: name" << endl;
        cout << "15: parentCode" << endl;
        cout << "16: releaseDate" << endl;
        cout << "17: tcgplayerGroupId" << endl;
        cout << "18: tokenSetCode" << endl;
        cout << "19: totalSetSize" << endl;
        cout << "20: type" << endl;
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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
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
}