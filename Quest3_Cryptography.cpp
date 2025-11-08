#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class CaesarCipher{
    private:
        int shiftValue;
    
    protected:
        string encode(const string& message){       // enodes the given message by whatever shiftValue is set to then returns it.
            string encoded_string;
            for(char c : message){
                encoded_string += (c + shiftValue);
            }
            return encoded_string;
        }
        
    public:
        string encryptMessage(const string& message){   // method used to access protected method encode.
            return encode(message);
        }
        void setShiftValue(int value){  // setter method used to access private attribute shiftValue.
            shiftValue = value;
        }
};

int main(){
    
    CaesarCipher cipher;    //instantiate cipher object.
    string message, choiceInput;
    string choice;
    int shiftValue;
    
    cout << "----Welcome To The Cipher Program!----" << endl;
    while(true){
        cout << "Would you like to encrypt a new message? (y/n) " << endl;

        getline(cin,choice);
        
        if (tolower(choice[0]) == 'y'){ // checks if choice is y and proceeds with program.
            cout << "Input your message: ";
            getline(cin, message);
            cout << "And now how much you'd like to shift it by (1-13): ";
            cin >> shiftValue;
            cin.ignore(); // discard leftover newline from cin >> so getline will work next time
            
            cipher.setShiftValue(shiftValue); // sets the shiftValue in class CaesarCipher using setter method to inputted value.
            cout << cipher.encryptMessage(message) << endl; // outputs encoded message to console.
        }
        else if(tolower(choice[0]) == 'n'){ // checks if choice is n and exits program.
            cout << "Exiting the program.";
            break;
        }
        else { // if neither y or n is inputted, error message will be displayed.
            cout << "Invalid input! Please either y or n." << endl;
        }
    }
    return 1;
}
