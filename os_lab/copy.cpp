#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    string src, dst;

    cout << "Enter the name of source file: ";
    cin >> src;

    cout << "Enter the name of destination file: ";
    cin >> dst;

    // Check if source file exists
    if (!filesystem::exists(src)) {
        cout << "Source file does not exist. Aborting." << endl;
        return 1;
    }

    // Check if destination file already exists
    if (filesystem::exists(dst)) {
        cout << "Destination file already exists. Aborting." << endl;
        return 1;
    }

    // Open source file for reading
    ifstream srcF(src);

    if (!srcF) {
        cout << "Error opening source file. Aborting." << endl;
        return 1;
    }

    // Open destination file for writing
    ofstream destF(dst);

    if (!destF) {
        cout << "Error creating destination file. Aborting." << endl;
        return 1;
    }

    // Copy contents
    char ch;

    while (srcF.get(ch)) {
        destF.put(ch);
    }

    cout << "File copied successfully." << endl;

    srcF.close();
    destF.close();

    return 0;
}
