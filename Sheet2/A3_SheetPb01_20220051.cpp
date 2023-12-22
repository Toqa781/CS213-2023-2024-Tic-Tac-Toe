 //File:A3_SheetPb01_20220051.cpp
//author: Adham Salah Ezzat
//ID: 20220051
//section:S7
//Date:9/12/2023

#include <iostream>
#include <fstream>

using namespace std;

class LabelGenerator {
public:
    // Constructor: Initializes the label generator with a prefix and an initial index.
    LabelGenerator(const string& prefix, int initialIndex);

    // Generates the next label in the sequence and returns it.
    string nextLabel();

protected:
    string prefix;
    int currentIndex;
};


LabelGenerator::LabelGenerator(const string& prefix, int initialIndex)
        : prefix(prefix), currentIndex(initialIndex) {}

// Generates the next label in the sequence and returns it.
std::string LabelGenerator::nextLabel() {
    return prefix + to_string(currentIndex++);
}

class FileLabelGenerator : public LabelGenerator {
public:
    // Constructor: Initializes the file label generator with a prefix, an initial index, and a FirstProblem file.
    FileLabelGenerator(const string& prefix, int initialIndex, const string& FirstProblem);

    // Overrides the base class method to generate the next label from the file.
    string nextLabel() ;

private:
    // Attribute
    ifstream fileStream;
};

// Constructor
FileLabelGenerator::FileLabelGenerator(const string& prefix, int initialIndex, const string& FirstProblem)
        : LabelGenerator(prefix, initialIndex), fileStream(FirstProblem) {
    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file " << FirstProblem<< endl;
    }
}

// Overrides the base class method to generate the next label from the file.
string FileLabelGenerator::nextLabel() {
    string additionalLabel;

    // Read the next line from the file and append it to the generated label.
    getline(fileStream, additionalLabel);

    // If end of file is reached, close and reopen the file for subsequent reads.
    if (fileStream.eof()) {   // End-of-file flag, indicating whether the end of the file has been reached
        fileStream.clear();  // Clear the end-of-file flag.
        fileStream.seekg(0); // Rewind to the beginning of the file.
        // Function used to set the position of the get pointer in the input stream.
    }

    return LabelGenerator::nextLabel() + " " + additionalLabel;
}

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);

    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }

    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }

    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }

    cout << endl;

    // Using FileLabelGenerator
    FileLabelGenerator figureLabels("Figure ", 1, "FirstProblem.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }

    return 0;
}
