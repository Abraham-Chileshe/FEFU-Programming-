#include <bits/stdc++.h>
using namespace std;

// Function to find the string obtained
// after performing given shift operations
string stringShift(string s,
                 vector<vector<int> >& shift)
{

    int val = 0;

    for (int i = 0; i < shift.size(); ++i)

        // If shift[i][0] = 0, then left shift
        // Otherwise, right shift
        val += shift[i][0] == 0
               ? -shift[i][1]
               : shift[i][1];

    // Stores length of the string
    int len = s.length();

    // Effective shift calculation
    val = val % len;

    // Stores modified string
    string result = "";

    // Right rotation
    if (val > 0)
        result = s.substr(len - val, val)
                 + s.substr(0, len - val);

        // Left rotation
    else
        result
                = s.substr(-val, len + val)
                  + s.substr(0, -val);

    return result;
}

int test(string str1, string str2, int count){
    int cnt = count;

    vector<vector<int> > shift = {
            { 0, 1 },
            { 1, 2 }
    };

    if(str1 == str2)
        return count;

    else if(stringShift(str1, shift)==str1)
        return -1;

    cnt++;

    return test(stringShift(str1, shift),str2, cnt);
}

// Driver Code
int main()
{
    string s1;
    string s2;

    std::cin>>s1;
    std::cin>>s2;

    std::cout<<test(s1,s2,0);


    return 0;
}