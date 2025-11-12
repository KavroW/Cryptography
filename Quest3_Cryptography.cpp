#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class CaesarCipher {
private:
    int shiftValue;   // private attribute storing how much the message will be shifted by during encryption.

protected:
    string encode(const string& message) {      // encodes the given message by whatever shiftValue is set to then returns it.
        string encoded_string;
        for(char c : message) {
            encoded_string += (c + shiftValue);
        }
        return encoded_string;
    }

public:
    string encryptMessage(const string& message) {  // method used to access protected method encode.
        return encode(message);
    }

    string decode(const string& encoded_string, int shiftValueGuess){ // decodes encrypted string based on user guess
        string decoded_string;
        for(char c : encoded_string) {
            decoded_string += (c - shiftValueGuess);
        }
        return decoded_string;
    }

    void setShiftValue(int value) { // setter method used to access private attribute shiftValue.
        shiftValue = value;
    }
};

int main() {

    CaesarCipher cipher;    // instantiate cipher object.
    string message, encodeChoiceInput, decodeChoiceInput, encodedMessage, decodedMessageGuess;
    string choice;
    int encodeShiftValue, shiftValueGuess;

    cout << "----Welcome To The Cipher Program!----" << endl;
    while(true) {

        cout << "Would you like to encrypt a new message? (yes/no) " << endl;
        getline(cin, encodeChoiceInput);

        if (encodeChoiceInput.empty()) continue;  // prevents out of bounds crash on empty input

        if (tolower(encodeChoiceInput[0]) == 'y') { // checks if choice is y and proceeds with program.
            cout << "Input your message: ";
            getline(cin, message);

            cout << "And now how much you'd like to shift it by (1-13): ";
            cin >> encodeShiftValue;
            cin.ignore(); // discard leftover newline from cin >> so getline will work next time

            cipher.setShiftValue(encodeShiftValue); // sets the shiftValue in class CaesarCipher using setter method to inputted value.
            encodedMessage = cipher.encryptMessage(message);

            cout << encodedMessage << endl; // outputs encoded message to console.

            cout << "Do you want to decode the most recent inputted message? (yes/no) ";
            cin >> decodeChoiceInput;

            if (tolower(decodeChoiceInput[0])=='y'){  // checks if user wants to decode the encrypted message
                cout << "Enter your guess for the shift value: ";
                cin >> shiftValueGuess;

                decodedMessageGuess = cipher.decode(encodedMessage, shiftValueGuess); // attempts to decode based on user guess

                cout << "Original message: " << message << endl;        // prints original message
                cout << "Decoded message : " << decodedMessageGuess << endl;   // prints decoded guess message
            }

            cin.ignore(); // clears newline after decoding section
        }
        else if(tolower(encodeChoiceInput[0]) == 'n') { // checks if choice is n and exits program.
            cout << "Exiting the program.";
            return 0;
        }
        else { // if neither yes or no is inputted, error message will be displayed.
            cout << "Invalid input! Please either y or n." << endl;
        }
    }
    return 0;
}
