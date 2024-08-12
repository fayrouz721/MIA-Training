#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      int i,n,element,index,notfound=-1;
    //take the index from the user
   cin>>n;
    //take the elements from the user
   int arr[n];
        for (i=0;i<n;i++){
    cin>>arr[i];} 
//take the number from the user
cin>>element;
for (int j=0;j<n;j++){
    if (element == arr[j]){
        index = j;
        notfound = 0;
    cout<<index <<endl;
}}
//if the number isn't found in the array
   if (notfound == -1 ){
     cout<<notfound<<endl ;}
    return 0;
}
