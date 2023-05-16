/**
 FCAI - Programming 1 - 2022 - Assignment 2
 Program Name: All Ciphers.cpp
 Program Description: Encrypt and decrypt messages using any of the ten ciphers
 Last Modification Date: 23/3/2022
 Author Name: Khaled Salah
 Purpose: Practicing c++
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
string option;

void AffineCipher(int a, int b) {
    string s, ns;
    cout << "Enter your massage :\n";
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if (static_cast<char>(towlower(s[i])) > 122 || static_cast<char>(towlower(s[i])) < 97) {
            ns[i] = static_cast<char>(towlower(s[i]));
        } else {
            ns[i] = char((((a * (towlower(s[i]) - 97) + b) % 26 + 26) % 26) + 97);
        }
    }
    cout << "Your massage after encryption is: " << ns << endl;


}

void AffineDecipher(int b, int c) {
    string s, ns;
    cout << "Enter your massage : \n";
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if (static_cast<char>(towlower(s[i])) > 122 || (towlower(s[i]) < 97)) { ns[i] = (char) towlower(s[i]); }
        else {
            ns[i] = char(((c * (tolower(s[i]) - 97) - b) % 26 + 26) % 26 + 97);
        }
    }
    cout << "Your massage after decryption is: " << ns << endl;
}

void Affine() {
    int a = 5, b = 8, c = 21;
    int n;

    while (true) {

        cout
                << "Welcome to Affine cipher. \n What do you like to do today? \n 1- Cipher a message \n 2- Decipher a message \n 3- Change the cipher and decipher constants a,b and c \n type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { AffineCipher(a, b); }
        else if (n == 2) { AffineDecipher(b, c); }
        else if (n == 3) {
            cout
                    << "Enter a,b and c constants space-separated, cipher formula is (a x+ b)%26 and decipher formula is c*(y - b)%26 : "
                    << endl;
            while (true) {
                cin >> a >> b >> c;
                if ((a * c) % 26 == 1) break;
                cout
                        << "Non valid numbers please enter a,b and c constants again satisfying the condition (a * c) mod 26 = 1 :\n";
            }
        } else { return; }
    }
}

int shift(int x, int a) {
    if (x < 123 && (x + a) > 122) return x + a - 26;
    else return (x + a);
}

int ShiftBack(int x, int a) {
    if (x > 96 && (x - a) < 97) return x - a + 26;
    else return x - a;
}

void CaesarCipher(int a) {
    string s, ns;
    cout << "Enter your massage :\n";
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if (towlower(s[i]) > 122 || towlower(s[i]) < 97) { ns[i] = s[i]; }
        else {
            ns[i] = char(shift(towlower(s[i]) - 0, a));
        }
    }
    cout << "Your massage after encryption is: " << ns << endl;

}


void CaesarDecipher(int a) {
    string s, ns;
    cout << "Enter your massage : \n";
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if (towlower(s[i]) - 0 > 122 || towlower(s[i]) - 0 < 97) { ns[i] = s[i]; }
        else {
            ns[i] = char(ShiftBack(towlower(s[i]) - 0, a));
        }
    }
    cout << "Your massage after decryption is: " << ns << endl;
}

void Caesar() {
    int a;
    int n;
    while (true) {
        cout << "Welcome to Caesar cipher.\n"
                "Enter a constant 'a' that indicates how many times every letter will be shifted: " << endl;
        cin >> option;
        a = option[0] - 48;

        if (a < 27) {
            break;
        }

        cout << "Invalid number. Please enter a constant again satisfying the condition (a < 27):" << endl;
    }

    while (true) {
        cout << "What would you like to do today?\n"
                "1 - Cipher a message\n"
                "2 - Decipher a message\n"
                "Type anything else to go to the main menu of ciphers:" << endl;
        cin >> option;
        n = option[0] - 48;

        if (n == 1) {
            CaesarCipher(a);
        } else if (n == 2) {
            CaesarDecipher(a);
        } else {
            return;
        }
    }

}

void AtbashCipher(int x) {
    string s, ns;
    cout << "Enter your message: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);

    ns = s;

    for (int i = 0; i < s.size(); i++) {
        if ((towlower(s[i]) - 0) > 122 || (towlower(s[i]) - 0) < 97) {
            ns[i] = char((s[i]));
        } else {
            ns[i] = char(towlower(s[i]) + 219 - 2 * towlower(s[i]));
        }
    }

    if (x) {
        cout << "Your message after encryption is: " << ns << endl;
    } else {
        cout << "Your message after decryption is: " << ns << endl;
    }
}

void Atbash() {
    int n;
    while (true) {
        cout << "Welcome to Atbash Cipher. What do you want to do?\n"
                "1 - Perform encryption\n"
                "2 - Perform decryption\n"
                "* Type anything else to go to the main menu of ciphers." << endl;

        cin >> option;
        n = option[0] - 48;

        if (n == 1) {
            AtbashCipher(1);
        } else if (n == 2) {
            AtbashCipher(0);
        } else {
            return;
        }
    }
}

void VignereDecipher(string s2) {

    string s, ns;
    cout << "Enter the massage to be Decrypted :" << endl;

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() < 81) break;
        cout << "Too many characters , try again with maximum 80 characters : " << endl;

    }


    ns = s;
    for (char &i: s2) {
        i = (char) toupper(i);
    }
    for (int i = 0; i < s.size(); i++) {
        if ((towlower(s[i]) - 0) > 122 || (towlower(s[i]) - 0) < 97) { ns[i] = char(s[i]); }
        else {
            int a = 0;
            if ((toupper(s[i]) - 0) < (toupper(s2[i - (s2.size() * ((int) (i / s2.size())))]) - 0)) { a = 26; }

            ns[i] = char(((toupper(s[i]) + a) - toupper(s2[i - (s2.size() * ((int) (i / s2.size())))])) + 65);
        }
    }
    cout << "Your massage after Decryption is: " << ns << endl;
}

void VignereCipher(string s2) {

    string s, ns;
    cout << "Enter the massage to be encrypted :" << endl;

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() < 81) break;
        cout << "Too many characters , try again with maximum 80 characters : " << endl;
    }
    ns = s;
    for (char &i: s2) { i = (char) toupper(i); }
    for (int i = 0; i < s.size(); i++) {
        if ((towlower(s[i]) - 0) > 122 || (towlower(s[i]) - 0) < 97) { ns[i] = char(s[i]); }
        else {
            ns[i] = char(((toupper(s[i]) + toupper(s2[i - (s2.size() * ((int) (i / s2.size())))])) % 26) + 65);

        }
    }
    cout << "Your massage after encryption is: " << ns << endl;
}

void Vignere() {
    int n;
    string s;
    cout << "Welcome in VignereCipher, enter the keyword of encryption :" << endl;
    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() < 9) break;
        cout << "Too many characters , try again with maximum 8 characters : " << endl;
    }
    while (true) {
        cout
                << "What do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { VignereCipher(s); }
        else if (n == 2) { VignereDecipher(s); }
        else { return; }
    }
}

void SimpleSubstitutionDecipher(const char key[26]) {

    string s, ns;
    cout << "Enter the massage to be Decrypted :" << endl;

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() < 81) break;
        cout << "Too many characters , try again with maximum 80 characters : " << endl;

    }

    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if ((towlower(s[i]) - 0) > 122 || (towlower(s[i]) - 0) < 97) { ns[i] = char(s[i]); }
        else {
            ns[i] = char(key[tolower(s[i]) - 97] + 97);

        }
    }
    cout << "Your massage after Decryption is: " << ns << endl;
}

void SimpleSubstitutionCipher(const char key[26]) {

    string s, ns;
    cout << "Enter the massage to be encrypted :" << endl;

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() < 81) break;
        cout << "Too many characters , try again with maximum 80 characters : " << endl;
    }
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if ((towlower(s[i]) - 0) > 122 || (towlower(s[i]) - 0) < 97) { ns[i] = char(s[i]); }
        else {
            ns[i] = key[towlower(s[i]) - 97];

        }
    }
    cout << "Your massage after encryption is: " << ns << endl;
}

void SimpleSubstitution() {
    pair<char, bool> arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i].first = char(97 + i);
        arr[i].second = false;
    }
    char key[26];
    char key2[26];
    int n;
    cout << "Welcome SimpleSubstitutionCipher, enter the keyword of encryption consisting of 5 characters :" << endl;
    string s;
    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, s);
        if (s.size() == 5) break;
        cout << "Non-valid number of characters , try again with exactly 5 characters : " << endl;
    }
    for (int i = 0; i < 5; i++) {
        key[i] = (char) towlower(s[i]);
        arr[(tolower(s[i]) - 97)].second = true;
        key2[towlower(s[i]) - 97] = (char) i;
    }
    int a = 5;
    for (int i = 0; i < 26; i++) {
        if (arr[i].second) {
            a--;
            continue;
        }
        key[i + a] = arr[i].first;
        key2[arr[i].first - 97] = (char) (i + a);
    }

    while (true) {
        cout
                << "What do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { SimpleSubstitutionCipher(key); }
        else if (n == 2) { SimpleSubstitutionDecipher(key2); }
        else { return; }
    }
}

void BaconianDecipher() {

    string s, ns;
    cout << "Enter the massage to be Decrypted, note it should be only a combination of a and b :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = "";
    for (int a = 0; a < s.size(); a += 6) {
        if (!(s[a] == 'b' || s[a] == 'a')) {
            ns += s[a];
            a -= 5;
        } else {

            int x = 0;
            for (int i = 0; i < 5; i++) { if (s[i + a] == 'b') x += (int) pow(2, 4 - i); }
            ns += char(x + 97);
        }
    }


    cout << "Your massage after Decryption is: " << ns << endl;
}

void BaconianCipher() {

    string s, ns, x;
    cout << "enter the massage to be encrypted :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    for (char i: s) {

        if ((towlower(i) - 0) > 122 || (towlower(i) - 0) < 97) { ns += i; }
        else {
            x = "12345";
            for (int d = 4; d >= 0; d--) {
                int a = ((towlower(i) - 97) >> d);
                if (a & 1) { x[4 - d] = 'b'; }
                else { x[4 - d] = 'a'; }
            }
            ns += x + ' ';

        }
    }
    cout << "Your massage after encryption is: " << ns << endl;
}

void Baconian() {
    int n;
    while (true) {
        cout
                << "Welcome to BaconianCipher, what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { BaconianCipher(); }
        else if (n == 2) { BaconianDecipher(); }
        else { return; }
    }
}

// This function deciphers a message using the Polybius Square Cipher
void PolybiusSquareDecipher(char arr[10][10]) {
    string s, ns; // s is the original message, ns is the deciphered message
    cout << "Enter the massage to be Decrypted :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    // Iterate through each character of the original message
    for (int i = 0; i < s.size(); i += 2) {
        // If the character is not a number, add it to the deciphered message
        if ((s[i] - 0) > 58 || (s[i] - 0) < 49) {
            ns += s[i];
            i--;
        }
            // Otherwise, use the Polybius Square Cipher to decipher the character
        else {
            ns += arr[s[i] - 48][s[i + 1] - 48];
        }
    }
    cout << " your massage after Decryption is: " << ns << endl;
}

// This function encrypts a message using the Polybius Square Cipher
void PolybiusSquareCipher(int arr[26]) {
    string s, ns; // s is the original message, ns is the encrypted message
    cout << "Enter the massage to be encrypted :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s); // Get the message from the user
    for (char i: s) { // Iterate through each character in the message
        if ((towlower(i) - 0) > 122 || (towlower(i) - 0) < 97) {
            // If the character is not a letter, add it to the encrypted message
            ns += i;
        } else {
            // Otherwise, add the corresponding number from the array to the encrypted message
            ns += to_string(arr[toupper(i) - 65]);
        }
    }
    cout << " your massage after encryption is: " << ns << endl;
}

void PolybiusSquare() {
    // Declare a 10x10 array to store the Polybius Square
    char arr[10][10];
    // Declare an array to store the reference of the Polybius Square
    int ref[26];
    // Declare a variable to store user input
    int n;
    // Ask the user to enter a keyword of 5 characters
    cout << "Welcome to SimpleSubstitutionCipher, enter the keyword of encryption consisting of 5 characters :" << endl;
    string s;
    while (true) {
        cin >> s;
        if (s.size() == 5) break;
        cout << "Non-valid number of characters, try again with exactly 5 characters : " << endl;
    }
    // Create the Polybius Square and the reference array
    for (int a = 0; a < 5; a++) {
        for (int i = 0; i < 5; i++) {
            arr[s[a] - 48][s[i] - 48] = char(65 + 5 * a + i);
            ref[5 * a + i] = (10 * (s[a] - 48)) + (s[i] - 48);
        }
    }
    // Ask the user what they want to do
    while (true) {
        cout << "What do you want to do? \n"
                " 1- do encryption  \n"
                " 2- do Decryption  \n"
                " *type any other thing to go to ciphers main menu " << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { PolybiusSquareCipher(ref); }
        else if (n == 2) { PolybiusSquareDecipher(arr); }
        else { return; }
    }
}

void MorseCodeDecipher(map<string, char> key) {

    string s, ns;
    cout << "Enter the massage to be Decrypted :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    string x;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ns += key[x];
            if (s[i + 1] == ' ') {
                ns += ' ';
                i += 2;
            }
            x = "";
            continue;
        }
        x += s[i];
    }
    ns += key[x];
    cout << "Your massage after Decryption is: " << ns << endl;
}

void MorseCodeCipher(map<char, string> key) {
    // Declare variables
    string s, ns;
    // Prompt user for message to be encrypted
    cout << "Enter the message to be encrypted: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    // Loop through characters in message
    for (char i: s) {
        // Check if character is a letter or not
        if ((towlower(i) - 0) > 122 || (towlower(i) - 0) < 97) {
            // If not a letter, add corresponding morse code to new string
            ns += key[i] + ' ';
        } else {
            // If letter, convert to uppercase and add corresponding morse code to new string
            ns += key[(char) toupper(i)] + ' ';
        }
    }
    // Print encrypted message
    cout << "Your message after encryption is: " << ns << endl;
}

void MorseCode() {
    int n;
    // Create map of characters and their corresponding morse code
    map<char, string> key1 = {
            {' ', "  "},
            {',', "--..--"},
            {'.', ".-.-.-"},
            {'?', "..--.."},
            {'0', "-----"},
            {'1', ".----"},
            {'2', "..---"},
            {'3', "...--"},
            {'4', "....-"},
            {'5', "....."},
            {'6', "-...."},
            {'7', "--..."},
            {'8', "---.."},
            {'9', "----."},
            {'A', ".-"},
            {'B', "-..."},
            {'C', "-.-."},
            {'D', "-.."},
            {'E', "."},
            {'F', "..-."},
            {'G', "--."},
            {'H', "...."},
            {'I', ".."},
            {'J', ".---"},
            {'K', "-.-"},
            {'L', ".-.."},
            {'M', "--"},
            {'N', "-."},
            {'O', "---"},
            {'P', ".--."},
            {'Q', "--.-"},
            {'R', ".-."},
            {'S', "..."},
            {'T', "-"},
            {'U', "..-"},
            {'V', "...-"},
            {'W', ".--"},
            {'X', "-..-"},
            {'Y', "-.--"},
            {'Z', "--.."},
    };
    // Create map of morse code and their corresponding characters
    map<string, char> key2;
    key2["--..--"] = ',';
    key2["  "] = ' ';
    key2[".-.-.-"] = '.';
    key2["..--.."] = '?';
    for (int i = 0; i < (10); i++) {
        key2[key1[char(i + 48)]] = char(i + 48);
    }
    for (int i = 0; i < (26); i++) {
        key2[key1[char(i + 65)]] = char(i + 65);
    }
    // Prompt user for action
    while (true) {
        cout
                << "Welcome to MorseCode, what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        // Call cipher or decipher function based on user input
        if (n == 1) { MorseCodeCipher(key1); }
        else if (n == 2) { MorseCodeDecipher(key2); }
        else { return; }
    }
}

void XORDecipher(int k) {
    string s, ns;
    cout << "enter the massage to be Decrypted ( in hexadecimal ) :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    for (int i = 0; i < s.size() - 1; i += 2) {
        string y;
        y += s[i];
        y += s[i + 1];
        int x = stoi(y, nullptr, 16);
        x ^= k;
        ns += char(x);
    }
    cout << " your massage after Decryption is: " << ns << endl;
}

void XORCipher(int k) {

    string s, ns;
    cout << "enter the massage to be encrypted :" << endl;
    cin.clear();
    cin.sync();
    getline(cin, s);
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        int x = toupper(s[i]) - 0;
        x ^= k;
        ns[i] = char(x + 65);
    }
    cout << " your massage after encryption is: " << ns << "  (Hex: ";
    for (char n: ns) {
        if ((n - 65) < 16) cout << 0;
        cout << hex << (n - 65);
    }
    cout << ')' << endl;
}

void XOR() {
    int n;
    string s;
    cout << "welcome to XORCipher, enter the secret letter to start\n";
    while (true) {
        cin >> s;
        if (s.size() == 1) break;
        cout << "non-valid letter, please enter one valid letter\n" << endl;
    }
    while (true) {
        cout
                << "what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "
                << endl;
        cin >> option;
        n = option[0] - 48;
        if (n == 1) { XORCipher(toupper(s[0]) - 0); }
        else if (n == 2) { XORDecipher(toupper(s[0]) - 0); }
        else { return; }
    }
}

void rail_fence_enc(const string &s) {

    char arr[3][(s.length())];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < s.length(); j++)
            arr[i][j] = ' ';

    bool down = false;
    int row = 0, column = 0;

    for (char i: s) {

        if (row == 0 || row == 2)
            down = !down;


        arr[row][column++] = i;

        if (down) row++;
        else row--;
    }


    string result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < s.length(); j++)
            if (arr[i][j] != ' ')
                result.push_back(arr[i][j]);

    cout << result << endl << endl;
}

void rail_fence_dec(string cipher) {

    char arr[3][cipher.length()];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cipher.length(); j++)
            arr[i][j] = ' ';

    bool down;

    int row = 0, column = 0;

    for (int i = 0; i < cipher.length(); i++) {

        if (row == 0)
            down = true;
        if (row == 2)
            down = false;


        arr[row][column++] = '-';


        if (down) row++;
        else row--;
    }


    int n = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (arr[i][j] == '-' && n < cipher.length())
                arr[i][j] = cipher[n++];


    string result;

    row = 0, column = 0;
    for (int i = 0; i < cipher.length(); i++) {

        if (row == 0)
            down = true;
        if (row == 2)
            down = false;

        if (arr[row][column] != '-')
            result.push_back(arr[row][column++]);


        if (down) row++;
        else row--;
    }
    cout << result << endl << endl;
}

void Rail_fence() {
    string message;
    int choice;
    while (true) {
        cout
                << "ahlan ya habibi in Rail fence , what do you like to do \n 1) Cipher \n 2) Decipher \n *press any other key to go back to Ciphers list\n"
                << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter a message to cipher: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, message);
            message.erase(remove(message.begin(), message.end(), ' '), message.end());
            rail_fence_enc(message);
        } else if (choice == 2) {
            cout << "Enter a message to decipher: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, message);
            rail_fence_dec(message);
        } else break;
    }
}

int main() {
    int q;
    while (true) {
        cout << "Hello, choose your cipher method:\n"
                " 0-Affine\n 1-Caesar\n 2-Atbash\n 3-Vignere\n 4-Baconian\n"
                " 5-Simple Substitution\n 6-Polybius Square\n 7-Morse Code\n"
                " 8-XOR\n 9-Rail Fence\n\n*Type anything else to exit the program:"
             << endl;
        cin >> option;
        q = option[0] - 48;
        switch (q) {
            case 0:
                Affine();
                break;
            case 1:
                Caesar();
                break;
            case 2:
                Atbash();
                break;
            case 3:
                Vignere();
                break;
            case 4:
                Baconian();
                break;
            case 5:
                SimpleSubstitution();
                break;
            case 6:
                PolybiusSquare();
                break;
            case 7:
                MorseCode();
                break;
            case 8:
                XOR();
                break;
            case 9:
                Rail_fence();
                break;
            default:
                return 0;
        }
    }
}
