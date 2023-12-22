// File name:A3_SheetPb3_20220103.cpp
// Purpose:in the comments
// Author(s):Habiba Ayman Hamed
// ID(s):20220103
// Section:S7,8
// Date:9/12/2023
#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string , int> mp;
string content;
int main() {
    ifstream f1("C:\\Users\\hhaym\\Documents\\clionprojects\\task 4\\tst4.txt");
    if(!f1.is_open()){
        cout<<"couldn't open file\n";
        return 1;
    }
    else{
        //read the content of the file into a string
        getline(f1,content);
    }
    //close the string
    f1.close();
    //creates a stringstream to tokenize the content of the file and it works on strings
    stringstream ss(content);
    string word;
    while (ss >> word) {
        //break the string into words
        string result;
        for (char c: word) {
            //check if there is punctuations except '-' or non-alphabetic numbers
            if (c == '-' || isalpha(c)) {
                result+=c;
            }
        }
        //increment count of each word
        if(!result.empty())
            mp[result]++;
    }
    cout << "Word Frequency Map:" << std::endl;
    for (const auto& pair :mp) {
        cout  << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
