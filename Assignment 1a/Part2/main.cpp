#include <iostream>
#include <fstream>

using namespace std;

/*
* Write input to text file if the first character of the line is not '\'
* ofstream variable 'file' is the file being written to.
* Return false if the first character of a line is not '\'
* else return true.
*/
bool write(ofstream &file){
    // string variable 'input' is the input for the text file
    string input;

    // Retreive input from user, when enter is pressed
    getline(cin, input);

    if (input[0] == '\\'){
        return false;
    }
    else{
        // Add enter to input to create a new line in the file
        // being written to
        input = input + "\n";
        file << input;
    }
    return true;
}

int main()
{
    ofstream file;

    //Open text file to write to
    file.open("test.txt", ios_base::app);

    //While output from boolean function 'write' is true keep writing to the text file
    while(write(file));

    //Close the text file before closing the program
    file.close();
    return 0;
}
