#include <iostream>
#include <algorithm>
using namespace std;


int main() {
int i,j,n;
    //taking input (no of rows) from the user
   cin>>n;
   //the outer loop indicates the rows
   for ( i=1 ;i<=n ; i++ ){
       //the inner loop indicates the elements in each row
    for (j=1;j<=i;j++){
         cout<< "*" ;
    } cout<<"\n";
   }    return 0;
}