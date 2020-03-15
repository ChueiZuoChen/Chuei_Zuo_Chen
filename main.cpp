#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

class Word {
private:
    string word;
    string type;
    string definition;
public:
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
    void showWordContent();
};

void Word::showWordContent() {
    cout << word << endl;
    cout << definition << endl;
    cout << type << endl;
}

void Word::setWord(string w) { word = w; }

void Word::setType(string t) { type = t; }

void Word::setDefinition(string d) { definition = d; }

string Word::getWord() { return word; }

string Word::getType() { return type; }

string Word::getDefinition() { return definition; }

class Dictionary {
public:
    vector<Word> words;
    void loadDictionary();
    void showDictionary();
};

void Dictionary::showDictionary() {
    vector<Word>::iterator iterator;
    for (iterator=words.begin();iterator!=words.end();++iterator) {
        iterator->showWordContent();
    }
}

void Dictionary::loadDictionary() {
    fstream myFile;
    myFile.open("../dictionary2020.txt", ios::in);
    if (!myFile) {
        cout << "dictionary2020.txt cannot be open!" << endl;
    } else {
        string line;
        int countLine = 1;
        string tempLine[4];
        while (getline(myFile, line) && !myFile.eof()) {
            tempLine[countLine % 4] = line;
            if (countLine % 4 == 0) {
                words.push_back(Word(tempLine[1], tempLine[2], tempLine[3]));
            }
            countLine++;
        }
    }
}

int main() {
    Dictionary dictionary = *new Dictionary();
    dictionary.loadDictionary();
    dictionary.showDictionary();
    return 0;
}