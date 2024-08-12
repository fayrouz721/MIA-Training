#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    string name ; 
    //read the name including spaces 
    getline(cin, name);
    //greet the user
        cout << "Hello, " << name <<"!"; 
   
    return 0;
}