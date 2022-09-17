#include <iostream>
#include "string.h"

using namespace std;

int main() {

    kp::String str4("Ola");
    kp::String str5("Karol");
    kp::String str6("Papito");

    //konkatenacja
    kp::String str1("Merry");
    kp::String str2("Christmas");
    kp::String str3 = str1 + " " + str2;
    cout << str3 << endl;

    //dodawanie znaku
    str3.add_char('!', 14);
    cout << str3 << endl;

    // dodawanie i lower case
    str4.to_lower();
    str4.add_char('T', 0);
    cout << str4 << endl;

    // usuwanie
    str4.delete_element(0);
    cout << str4 << endl;

    // upper case
    str3.to_upper();
    cout << str3 << endl;

    // reverse
    str5.reverse();
    cout << str5 << endl;

    // usuwanie spe�niaj�ce kryterium
    kp::It<char> it1 = str6.begin();
    kp::It<char> it2 = str6.end();

    while (it1 != str6.end()) {
        cout << *it1 << endl;
        ++it1;
    }
    it1 = str6.begin();
    --it2;
    str6.erase(it1, it2);
    cout << str6 << endl;

    for (auto el : str6)
        cout << el;
  
    return 0;
}
