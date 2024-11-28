#include "TreeMap.h"
#include <fstream>
#include <string>
#include <vector>


int main()
{

    TreeMap<char, vector<string>> dictionary;

    //50 words file, 2 words repeated - mold, egg
    ifstream file("text.txt");

    if (!file.is_open()) {
        cerr << "Error opening the file!";
    }
    string word;
    while (getline(file, word))
    {
        if (dictionary.containsKey(word[0]))
        {
            dictionary.get(word[0]).push_back(word);
        }
        else
        {
            vector<string> v = {word};
            dictionary.put(word[0], v);
        }
    }

    file.close();

    BinaryTree<char> set = dictionary.keySet();
    set.printInOrder();


	return 0;
}