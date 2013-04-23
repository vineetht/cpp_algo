#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

vector<string> split(const string s)
{
    vector<string> vec;
    typedef string::size_type st_sz;
    st_sz size = s.size();
    st_sz i = 0, j = 0;

    while (i != size) {
        // Increment i till we find a non space character, make sure not to 
        // exceed the string
        while (isspace(s[i]) && i != size)
            i++;

        // Use j to find the end of the word, startign from i
        j = i;
        while (!isspace(s[j]) && j != size) 
                j++;

        // A word is found if i not equal to j
        if (i != j) {
            vec.push_back(s.substr(i, j - i));
            // Point i to the end of the word to encounter next character as space.
            i = j;
        }
    }

    return vec;
}


int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string>words = split(line);
        for(vector<string>::const_iterator it = words.begin();
           it != words.end(); it++) {
            cout << *it << endl;
        }

        cin.clear();
    }

    return 0;
}
