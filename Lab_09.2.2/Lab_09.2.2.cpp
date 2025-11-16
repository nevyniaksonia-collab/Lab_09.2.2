#include <iostream>
#include <fstream>
#include <cctype>
#include <cassert>
#include <string>
#include <map>

using namespace std;

void processFile(const string& filename, int min, int max)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: File not found." << endl;
        return;
    }

    map<string, int> counts = {
        {"Alphabetic", 0}, {"Numeric", 0}, {"Control", 0},
        {"Punctuation", 0}, {"Whitespace", 0}, {"Other", 0}
    };

    char ch;
    while (file.get(ch)) {
        int c = static_cast<unsigned char>(ch);

        if (isalpha(c)) {
            counts["Alphabetic"]++;
        }
        else if (isdigit(c)) {
            counts["Numeric"]++;
            assert(ch - '0' >= min && ch - '0' <= max); 
        }
        else if (iscntrl(c)) {
            counts["Control"]++;
        }
        else if (ispunct(c)) {
            counts["Punctuation"]++;
        }
        else if (isspace(c)) {
            counts["Whitespace"]++;
        }
        else {
            counts["Other"]++;
        }
    }

    file.close();

    cout << "\n--- Character Count Summary ---" << endl;
    for (const auto& pair : counts) {
        cout << pair.second << " \t-> " << pair.first << endl;
    }
}

int main(void)
{
    int min_val, max_val;
    cout << "Enter min range (0-9): ";
    cin >> min_val;
    cout << "Enter max range (0-9): ";
    cin >> max_val;

    if (min_val < 0 || max_val > 9 || min_val > max_val) {
        cerr << "Invalid range. Defaulting to [0, 9]." << endl;
        min_val = 0;
        max_val = 9;
    }

    processFile("input_text.txt", min_val, max_val);

    return 0;
}