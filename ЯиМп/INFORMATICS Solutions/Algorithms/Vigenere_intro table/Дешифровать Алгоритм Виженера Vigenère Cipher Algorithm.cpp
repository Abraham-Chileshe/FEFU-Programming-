#include<bits/stdc++.h>

using namespace std;

string generateKey(string str, string key){
    int x = str.size();

    for (int i = 0; ; i++){
        if (x == i)
            i = 0;
        if (key.size() == str.size()) //check if the size of key and text is equal.
            break;
        key.push_back(key[i]); //Pushback one letter from the Key
    }
    return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
    string cipher_text;
    for (int i = 0; i < str.size(); i++){
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;

        // convert into alphabets(ASCII)
        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;

        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

// Driver program to test the above function
int main()
{
    string str = "ILOVEYOU";
    string keyword = "CHILESHE";

    string key = generateKey(str, keyword); //first we generate the key
    string cipher_text = cipherText(str, key);

    cout << "\n----------------------------\nCiphertext : " << cipher_text << "\n----------------------------\n";
    cout << "Decrypted Text : " << originalText(cipher_text, key) << "\n----------------------------\n";

    return 0;
}