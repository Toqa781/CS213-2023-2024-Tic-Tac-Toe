// File name:A3_sheetPb02_20220093
// Purpose:Document Similarity
// Author(s):Toqa Abdalla Ahmed
// ID(s):20220093
// Section:s7
// Date:4/12/2023
// Version:1.0
#include<bits/stdc++.h>

using namespace std;

class StringSet {
private:
    vector<string> words;

public:
    //constructor that took a file name and insert it's string in the vector
    //strings are words in lower case
    StringSet(string filename) {
        ifstream file(filename);
        string word;
        while (file >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (find(words.begin(), words.end(), word) == words.end()) {
                words.push_back(word);
            }
        }
    }


    //add string to the set
    void addString(string str) {
        words.push_back(str);
    }

    //remove string from the set
    void removeString(string str) {
        words.erase(remove(words.begin(), words.end(), str), words.end());
    }

    //clear set
    void clearSet() {
        words.clear();
    }

    //return number os string
    int size() {
        return words.size();
    }

    //output the words in the set
    void outputStrings() {
        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;
    }

    //overload '+' operator
    StringSet operator+(StringSet &other) {
        StringSet result = *this;

        for (const auto &word: other.words) {
            if (find(result.words.begin(), result.words.end(), word) == result.words.end()) {
                result.words.push_back(word);
            }
        }

        return result;
    }


    //overload '*' operator
    StringSet operator*(StringSet &other) {
        StringSet result("");
        for (const auto &word: words) {
            if (find(other.words.begin(), other.words.end(), word) != other.words.end()) {
                result.addString(word);
            }
        }
        return result;
    }

    //similarity
    double computeSimilarity(StringSet &other) {
        StringSet intersectionSet = *this * other;
        int intersectionSize = intersectionSet.size();
        double den = sqrt(words.size()) * sqrt(other.words.size());
        double similarity = intersectionSize / den;
        return similarity;
    }


};

int main() {
    StringSet s1("q2.2");
    StringSet s2("q2");
    cout << "File 1 words: ";
    s1.outputStrings();
    cout << "File 2 words: ";
    s2.outputStrings();
    StringSet s3 = s1 + s2;
    cout << "union between 2 files: ";
    s3.outputStrings();
    StringSet s4 = s1 * s2;
    cout << "Intersection between 2 files: ";
    s4.outputStrings();
    double similarity = s1.computeSimilarity(s2);
    cout << "Similarity between 2 files: " << similarity;


    return 0;
}
