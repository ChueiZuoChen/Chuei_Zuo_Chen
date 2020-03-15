#include<iostream>
#include<fstream>

const int WORD_SIZE = 106186;
using namespace std;

class Word {
private:
    string word;
    string type;
    string definition;
public:
    Word() { cout << "constructor has been created!" << endl; }

    ~Word() { cout << "destructor has been created!" << endl; }

    Word(string word, string definition, string type) {
        setWord(word);
        setType(type);
        setDefinition(definition);
    }

    void setWord(string words);

    void setType(string types);

    void setDefinition(string definitions);

    string getWord();

    string getType();

    string getDefinition();
};

void Word::setWord(string w) { word = w; }

void Word::setType(string t) { type = t; }

void Word::setDefinition(string d) { definition = d; }

string Word::getWord() { return word; }

string Word::getType() { return type; }

string Word::getDefinition() { return definition; }

class Dictionary {
public:
    Word *words[WORD_SIZE];
    int countWordTotal = 0;
    int *const countWord = &countWordTotal;

    void loadDictionary();

    void showDictionary();
};

void Dictionary::showDictionary() {
    for (int i = 0; i < WORD_SIZE; i++) {
        cout << "[" << i << "]" << endl;
        cout << words[i]->getWord() << endl;
        cout << words[i]->getDefinition() << endl;
        cout << words[i]->getType() << endl;
    }

}

void Dictionary::loadDictionary() {

    fstream myFile;
    myFile.open("../dictionary2020.txt", ios::in);
    if (!myFile) {
        cout << "dictionary2020.txt cannot be open!" << endl;
    }
    string line;
    int countLine = 1;
    string tempLine[4];
    Word *word;
    while (getline(myFile, line) && !myFile.eof()) {
        tempLine[countLine % 4] = line;
        if (countLine % 4 == 0) {
            word = new Word(tempLine[1], tempLine[2], tempLine[3]);
            words[*countWord] = word;
            *countWord += 1;
//            cout << *countWord << endl;
        }
        countLine++;
    }
}


int main() {
    Dictionary dictionary = *new Dictionary();
    dictionary.loadDictionary();
    dictionary.showDictionary();
    return 0;
}