#include <bits/stdc++.h>
using namespace std;

set<int>prime;
int public_key;
int private_key;
int n; // n = p*q
int phi; //phi = (p - 1) * (q - 1)
int e; // 1 < e < phi(n) and gcd(e,phi) = 1
int d; // d = e-1 (mod phi(n))
int p, q;

//Function
void primefiller();
int pickrandomprime();
long long int encrypt(double);
long long int decrypt(int encrpyted_text);
vector<int> encoder(string message);
string decoder(vector<int> encoded);

void setkeys(){

    p = pickrandomprime(); // first prime number
    q = pickrandomprime(); // second prime number

    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 2;

    while (1) {
        if (__gcd(e, phi) == 1)
            break;
        e++;
    } //gcd(e,phi) = 1

    public_key = e;
    d = 2;

    while (1) {
        if ((d * e) % phi == 1)
            break;
        d++;
    }
    private_key = d;
}





int main(){
    primefiller();
    setkeys();
    string message;

    cout<<"Enter the message: ";
    getline(cin,message);

    // calling the encoding function
    vector<int> coded = encoder(message);
    cout << "\n\nEncrypted Message: \n--------------------------------\n";
    cout<<"p: "<< p<<", q: "<<q<<endl;
    cout<<"--------------------------------"<<std::endl;
    cout<<"encode: ";
    for (auto& p : coded)
        cout << p;

    cout << "\n\nThe decoded message(decrypted by private "
            "key)\n";
    cout << decoder(coded) << endl;
    return 0;
}

//primefilling
void primefiller(){
    vector<bool> seive(250, true);
    seive[0] = false;
    seive[1] = false;
    for (int i = 2; i < 250; i++) {
        for (int j = i * 2; j < 250; j += i) {
            seive[j] = false;
        }
    } // filling the prime numbers
    for (int i = 0; i < seive.size(); i++) {
        if (seive[i])
            prime.insert(i);
    }
}

//generating randomprime number
int pickrandomprime(){
    int k = rand() % prime.size();
    auto it = prime.begin();
    while (k--)
        it++;
    int ret = *it;
    prime.erase(it);
    return ret;
}

// to encrypt the given number
long long int encrypt(double message)
{
    int e = public_key;
    long long int encrpyted_text = 1;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= n;
    }
    return encrpyted_text;
}

// to decrypt the given number
long long int decrypt(int encrpyted_text){
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= n;
    }
    return decrypted;
}

// first converting each character to its ASCII value and
// then encoding it then decoding the number to get the
// ASCII and converting it to character
vector<int> encoder(string message){
    vector<int> form;
    // calling the encrypting function in encoding function
    for (auto& letter : message)
        form.push_back(encrypt((int)letter));
    return form;
}

string decoder(vector<int> encoded){
    string s;
    // calling the decrypting function decoding function
    for (auto& num : encoded)
        s += decrypt(num);
    return s;
}