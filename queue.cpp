#include <bits/stdc++.h> 
using namespace std;

stack<string> stack1;  
stack<string> stack2; 

void trans() {
while (!stack1.empty()) {
stack2.push(stack1.top());
   stack1.pop();
    }
}
void push(const string &item) {
    stack1.push(item);
}
void pop() {
    if (stack2.empty()) {
        trans();
    }
    if (!stack2.empty()) {
        stack2.pop();
    } else {
        cout << "Queue is empty, cannot pop!" << endl;
    }
}
string front() {
    if (stack2.empty()) {
        trans();
    }
    if (!stack2.empty()) {
        return stack2.top();
    } else {
        return "Queue is empty";
    }
}
bool isEmpty() {
    return stack1.empty() && stack2.empty();
}
};
int main() {
    Queue myQueue;
    myQueue.push("Batarang");
    myQueue.push("Grapple Gun");
    myQueue.push("Explosive Gel");
    myQueue.push("Batclaw");
    myQueue.push("Cape Glide");
    myQueue.push("Smoke Pellet");
    cout << "Batman's Weapons and Shields: " << endl;
    while (!myQueue.isEmpty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    return 0;
}
