#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

using std::cout;                using std::cin;
using std::vector;              using std::list;
using std::endl;                using std::string;
using std::copy;                using std::back_insert_iterator;
using std::ostream_iterator;    using std::istream_iterator;


int main()
{
    list<string> name;
    list<string> backup {"names_followed"};
    back_insert_iterator<list<string>> ins_it(name); 

    /*while (cin >> *itr) {
        continue;
    }*/
    *ins_it = "one";
    *ins_it = "tweo";

    //copy(name.begin(), name.end(), backup.begin()); 
    //in the above case "list<string> backup {"names_followed", "two", "thre", ..."
    copy(name.begin(), name.end(), back_inserter(backup));

    // Write backup to cout
    copy(backup.begin(), backup.end(), ostream_iterator<string>(cout, " "));

    // Read from istream and populate backup
    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(name));

    //Write name to cout
    copy(name.begin(), name.end(), ostream_iterator<string>(cout, " "));

    return 0;
}
