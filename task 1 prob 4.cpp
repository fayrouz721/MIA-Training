#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      // Declare the array rows and cols 
    int r,c;
    cin>>r>>c;
    int JL[r][c];
    int vill[r][c];
    //input justice league grids
     for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin>>JL[i][j];
        } }
          //input villians grids
        for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin>>vill[i][j];
        } }
        //compare the corresponding cells of the arrays
    // variables to compare the results
       int jlpts = 0; 
       int villpts = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
        if (JL[i][j] > vill [i][j]){
        jlpts++; }
        else if (JL[i][j] < vill [i][j]){
               villpts++;}
            else{
             jlpts++;  villpts++;
            }}}
        //announcing the winner
    if(jlpts > villpts){
        cout<<"Justice League"<<endl;}
   else  if(jlpts < villpts){
        cout<<"Villains"<<endl;}
    else{
        cout<<"Tie"<<endl;}
    return 0;
}