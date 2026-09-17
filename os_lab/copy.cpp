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
    
    ifstream srcF(src);
    if (!srcF) {
        cout << "Error opening source file. Aborting." << endl;
        return 1;
    }

    // Check if destination file already exists
    if (filesystem::exists(dst)) {
        cout << "Destination file already exists." << endl;
        char opt;
        cout << "do you want to overwrite/append/abort? [o/a/A]: " << endl;
        cin >> opt;
        if(opt=='o'){
          cout<<"overwriting.\n";
        }else if (opt=='a'){
          ofstream destF(dst,ios::app);
          char ch;
          while (srcF.get(ch)) {
              destF.put(ch);
          }

          cout << "File appended into successfully." << endl;

          srcF.close();
          destF.close();
          return 1;
        }else if (opt=='A'){
          cout<<"aborting.\n";
          return 1;
        }else {
          cout<<"invalid option. aborting.\n";
          return 1;
        }
    }
    ofstream destF(dst);
    char ch;
    while (srcF.get(ch)) {
        destF.put(ch);
    }
    cout << "File copied successfully." << endl;
    srcF.close();
    destF.close();

    // Open source file for reading

    // Open destination file for writing
    // ofstream destF(dst);

    // if (!destF) {
    //     cout << "Error creating destination file. Aborting." << endl;
    //     return 1;
    // }

    // Copy contents
    
    return 0;
}
