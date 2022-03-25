/*
 * Author1 : Mohamed Essam  
 * Program Name: Polybius Square Cipher .cpp
 * Program Description: Subistute each letter with row and column order  
 * Last Modification Date: 21/03/2022
*/

#include <iostream>
#include <algorithm>
using namespace std;

char table[6][6] = {{'0','1','2','3','4','5'},
                    {'1','A','B','C','D','E'},
                    {'2','F','G','H','I','K'},
                    {'3','L','M','N','O','P'},
                    {'4','Q','R','S','T','U'},
                    {'5','V','W','X','Y','Z'}};

/*
 * Adjusting keys to table
 * By fix the row and change column of keys 
 * Then fix column and change row  of keys
*/
void keys_table(){
    string keys;
    int a = 1, b = 1;
    cout << "Enter keys for both rows and column: ";
    getline(cin,keys);

    for (int i = 0; i < keys.length(); i++){
        table[0][b] = keys[i];
        table[a][0] = keys[i];
        b += 1;
        a += 1;
    }
};

/*
 * Encryption Text
 * Change all input to upper case as table
 * Seacrh for character in table
 * Then print the key of row and column adjacent to the letter
 * Not the actual row and column of the letter.
*/
void encryption(string text){
    char row, col;
    for (int i = 0; i < text.length(); i++){
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = text[i] - 32;
    }
    cout << "Cipher text: "<<endl;
    for (int i = 0; i < text.length(); i++){
        for (int r = 1; r < 6; r++){
            for (int c = 1; c < 6; c++){
                if (text[i] == 'J'){
                    text[i] = 'I';
                }                
                if (text[i] == table[r][c]){
                    row = table[r][0];
                    col = table[0][c];
                    cout << row << col;
                }
            }
        }
    }  
};

//Decryption Text
void decryption (string text){
    int row, col;
    cout << "Decipher text: "<<endl;
    for (int i = 0; i < (text.length()-1); i+=2){
        for (int r = 0; r < 6; r++){
            for (int c = 0; c < 6; c++){
                if (table[r][c] == (char)text[i])
                    row = r;   
                if (table[r][c] == (char)text[i+1])
                    col = r;
            } 
        }
        cout << table[row][col];
    }  
};

int main()
{   string Enctext, Dectext;
    int option;
    bool flag = true;
    cout << "Note: J and I are in the same slot." << endl;
    while (flag){
        cout << "\n---------------------------------" <<
                "\nAhlan yaa habibi \n" <<
                "What do you like to do today?\n" <<
                "1- Cipher a message.\n" <<
                "2- Decipher a message.\n" <<
                "3- Exit." << endl;
        cout << "Choose an option: ";
        cin >> option; 
        switch(option){     
            case 1:
                cin.ignore();
                keys_table();
                cout << "\nPlain text: ";
                getline (cin, Enctext);
                Enctext.erase(remove(Enctext.begin(),Enctext.end(),' '),Enctext.end());
                encryption(Enctext);
                break;
        
            case 2:
                cin.ignore();
                keys_table();
                cout << "\nCipher text: ";
                getline(cin,Dectext);
                Dectext.erase(remove(Dectext.begin(),Dectext.end(),' '),Dectext.end());
                decryption(Dectext); break;
            case 3:
                flag = false; break;
        };
   }
    return 0;
}