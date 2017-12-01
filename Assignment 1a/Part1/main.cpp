#include <iostream>
#include <fstream>

using namespace std;

/*
* Read ten lines of text from file or
* until end of file has been reached.
*/
void readFile(ifstream &file){
    // create a counter to read ten lines
    int i = 0;

    // variable to read input from file
    string line;

    while(!file.eof() && i < 10){
        i++;
        getline(file, line);
        cout << line << endl;
    }
}

/*
* Function to check if user wants to
* continue reading from file.
*
* Return true to continue reading,
* but false to stop reading.
*/
bool continueReading(){
    //Variable to check input status
    char input = 'x';

    // Loop until an answer is given in a correct format
    do{
        cout << "Do you want to continue: ";
        cout << "y/n" << endl;
        cin >> input;
    }while(input != 'y' && input != 'n');

    return input == 'y';
}

int main()
{
    // create an instance 'file' of the ifstream class to read from file
    ifstream file;

    file.open("test.txt");

    /*
    * If the file exists it is read until the end
    * or until user wants to quit reading. Else
    * a message is displayed showing the file could
    * not be opened, and the program terminates.
    */
    if(file.is_open()){
        while(!file.eof()){

            //Read ten lines of text or until end of file
            readFile(file);

            //If end of file has not been reached
            if (!file.eof()){
                //Check if user wants to continue reading from file
                if (!continueReading()){
                    break;
                }
            }

        }
        file.close();
    }
    else{
        cout << "could not open file" << endl;
    }
    return 0;
}
