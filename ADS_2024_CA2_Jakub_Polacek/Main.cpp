#include "TreeMap.h"
#include "MTGSet.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

void app1();
void app2();
void lineFront(string& s, list<string>& list);
void lineFront(int& i, list<string>& list);
void lineFront(float& f, list<string>& list);
void lineFront(bool& b, list<string>& list);

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
    TreeMap<string, vector<MTGSet>> index;
    string field;
    int id;

    bool run = true;
    string input;
    
#pragma region User Selection
    while (run)
    {
        cout << "\nWhat field do you want to create an index on?" << endl;
        cout << "0: Return to the main menu." << endl;
        cout << "1: baseSetSize" << endl;
        cout << "2: block" << endl;
        cout << "3: cardsphereSetId" << endl;
        cout << "4: code" << endl;
        cout << "5: isFoilOnly" << endl;
        cout << "6: isForeignOnly" << endl;
        cout << "7: isNonFoilOnly" << endl;
        cout << "8: isOnlineOnly" << endl;
        cout << "9: isPartialPreview" << endl;
        cout << "10: keyruneCode" << endl;
        cout << "11: languages" << endl;
        cout << "12: mcmId" << endl;
        cout << "13: mcmIdExtras" << endl;
        cout << "14: mcmName" << endl;
        cout << "15: mtgoCode" << endl;
        cout << "16: name" << endl;
        cout << "17: parentCode" << endl;
        cout << "18: releaseDate" << endl;
        cout << "19: tcgplayerGroupId" << endl;
        cout << "20: tokenSetCode" << endl;
        cout << "21: totalSetSize" << endl;
        cout << "22: type" << endl;
        cout << "Please type in a number:" << endl;

        getline(cin, input);
        try
        {
            id = stoi(input);

            run = false;

            switch (id)
            {
            case 0:
                break;
            case 1:
                field = "baseSetSize";
                break;
            case 2:
                field = "block";
                break;
            case 3:
                field = "cardsphereSetId";
                break;
            case 4:
                field = "code";
                break;
            case 5:
                field = "isFoilOnly";
                break;
            case 6:
                field = "isForeignOnly";
                break;
            case 7:
                field = "isNonFoilOnly";
                break;
            case 8:
                field = "isOnlineOnly";
                break;
            case 9:
                field = "isPartialPreview";
                break;
            case 10:
                field = "keyruneCode";
                break;
            case 11:
                field = "languages";
                break;
            case 12:
                field = "mcmId";
                break;
            case 13:
                field = "mcmIdExtras";
                break;
            case 14:
                field = "mcmName";
                break;
            case 15:
                field = "mtgoCode";
                break;
            case 16:
                field = "name";
                break;
            case 17:
                field = "parentCode";
                break;
            case 18:
                field = "releaseDate";
                break;
            case 19:
                field = "tcgplayerGroupId";
                break;
            case 20:
                field = "tokenSetCode";
                break;
            case 21:
                field = "totalSetSize";
                break;
            case 22:
                field = "type";
                break;
            default:
                cout << "Not a valid choice." << endl;
                run = true;
                break;
            }
        }
        catch (logic_error e)
        {
            cout << "Not a number, try again." << endl;
            cout << e.what();
        }
    }
#pragma endregion User Selection

#pragma region File Read & Index Creation
        ifstream file("sets.csv");

        if (!file.is_open()) {
            cerr << "Error opening the file!" << endl;
        }
        else
        {
            string line, value;

            while (getline(file, line))
            {
                stringstream lineStream(line);
                list<string> lineList;
                string quotes;
                bool quotesOpen = false;

                while (getline(lineStream, value, ','))
                {   
                    if (quotesOpen)
                    {
                        quotes.append(value);
                        if (value.back() == '"')
                        {
                            quotesOpen = false;
                            lineList.push_back(quotes);
                            quotes.clear();
                        }
                    }
                    else if (value[0] == '"')
                    {
                        quotes.append(value);
                        quotesOpen = true;
                    }
                    else
                    {
                        lineList.push_back(value);
                    }
                }

                int baseSetSize;
                string block;
                float cardsphereSetId;
                string code;
                bool isFoilOnly;
                bool isForeignOnly;
                bool isNonFoilOnly;
                bool isOnlineOnly;
                bool isPartialPreview;
                string keyruneCode;
                string languages;
                float mcmId;
                float mcmIdExtras;
                string mcmName;
                string mtgoCode;
                string name;
                string parentCode;
                string releaseDate;
                float tcgplayerGroupId;
                string tokenSetCode;
                int totalSetSize;
                string type;

                lineFront(baseSetSize, lineList);
                lineFront(block, lineList);
                lineFront(cardsphereSetId, lineList);
                lineFront(code, lineList);
                lineFront(isFoilOnly, lineList);    
                lineFront(isForeignOnly, lineList);
                lineFront(isNonFoilOnly, lineList);
                lineFront(isOnlineOnly, lineList);
                lineFront(isPartialPreview, lineList);
                lineFront(keyruneCode, lineList);
                lineFront(languages, lineList);
                lineFront(mcmId, lineList);
                lineFront(mcmIdExtras, lineList);
                lineFront(mcmName, lineList);
                lineFront(mtgoCode, lineList);
                lineFront(name, lineList);
                lineFront(parentCode, lineList);
                lineFront(releaseDate, lineList);
                lineFront(tcgplayerGroupId, lineList);
                lineFront(tokenSetCode, lineList);
                lineFront(totalSetSize, lineList);
                lineFront(type, lineList);

                if (id == 1)
                    value = baseSetSize;
                if (id == 2)
                    value = block;
                if (id == 3)
                    value = cardsphereSetId;
                if (id == 4)
                    value = code;
                if (id == 5)
                    value = isFoilOnly;
                if (id == 6)
                    value = isForeignOnly;
                if (id == 7)
                    value = isNonFoilOnly;
                if (id == 8)
                    value = isOnlineOnly;
                if (id == 9)
                    value = isPartialPreview;
                if (id == 10)
                    value = keyruneCode;
                if (id == 11)
                    value = languages;
                if (id == 12)
                    value = mcmId;
                if (id == 13)
                    value = mcmIdExtras;
                if (id == 14)
                    value = mcmName;
                if (id == 15)
                    value = mtgoCode;
                if (id == 16)
                    value = name;
                if (id == 17)
                    value = parentCode;
                if (id == 18)
                    value = releaseDate;
                if (id == 19)
                    value = tcgplayerGroupId;
                if (id == 20)
                    value = tokenSetCode;
                if (id == 21)
                    value = totalSetSize;
                if (id == 22)
                    value = type;

                MTGSet set = { baseSetSize, block, cardsphereSetId, code, isFoilOnly, isForeignOnly, isNonFoilOnly, isOnlineOnly, isPartialPreview, keyruneCode, languages, mcmId, mcmIdExtras, mcmName, mtgoCode, name, parentCode, releaseDate, tcgplayerGroupId, tokenSetCode, totalSetSize, type };


                if (index.containsKey(value))
                {
                    index.get(value).push_back(set);
                }
                else
                {
                    vector<MTGSet> vec = { set };
                    index.put(value, vec);
                }
            }
            file.close();

        }
#pragma endregion File Read & Index Creation

    
    BinaryTree<string> bt = index.keySet();
    bt.printInOrder();
}

#pragma region Helper Methods for Indexing
void lineFront(int& i, list<string>& list)
{
    if (list.front() == "")
    {
        i = 0;
    }
    else
    {
        i = stoi(list.front());
    }
    list.pop_front();
}

void lineFront(float& f, list<string>& list)
{
    if (list.front() == "")
    {
        f = 0;
    }
    else
    {
        f = stof(list.front());
    }
    list.pop_front();
}

void lineFront(bool& b, list<string>& list)
{
    if (list.front() == "True")
    {
        b = true;
    }
    else
    {
        b = false;
    }
    list.pop_front();
}

void lineFront(string& s, list<string>& list)
{
    s = list.front();
    list.pop_front();
}
#pragma endregion