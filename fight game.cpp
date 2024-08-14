#include <bits/stdc++.h> 
using namespace std;

class Character {
protected:
    string name , weapon, shield;
    int health, energy , damage , shield_Protection;

public:
    Character(string n, int h, int e) {
    name = n;
    health = h;
    energy = e;

}
string getName() {
        return name;
    }
int getHealth() {
        return health;
    }
int getEnergy() {
        return energy;
    }
virtual void set_w_sh() {}
void displayStats() {
     cout << "Name: " << name << endl;
     cout << "Health:" << health <<endl ;
     cout << "Energy: " << energy << endl;
    }
virtual void attack(Character& opponent) {
    set_w_sh(); //set weapon and shield
    // dealing with damage
    int finalDamage = damage * (100 - opponent.shield_Protection) / 100;
    opponent.health -= finalDamage;
    if (opponent.health < 0) {
        opponent.health = 0; // Ensure health doesn't go below 0
    }
//print attacking details
cout << name << " attacks with " << weapon << " using " << shield << "." << endl;
cout << opponent.getName() << "'s remaining health: " << opponent.getHealth() << endl;
//check health 
    if (opponent.getHealth() <= 0) {
        cout << opponent.getName() << " has deied" << endl;
    }
}
};

class Batman : 
public Character {
public:
Batman() : Character("Batman", 100, 500) {}
   void set_w_sh() {
     cout << "choose Batman's weapon (Batarang, Grapple Gun, Explosive Gel, Batclaw): ";
     cin >> weapon;
     cout << "choose Batman's shield (Cape Glide, Smoke Pellet): ";
     cin >> shield;

if (weapon == "Batarang") {
 damage = 11;
 energy -= 50;
} 
else if (weapon == "Grapple Gun") {
   damage = 18;
  energy -= 88;
} 
else if (weapon == "Explosive Gel") {
damage = 10;
energy -= 92;
 } 
else if (weapon == "Batclaw") {
  damage = 20;
  energy -= 120;
 } 
else {
 cout << "Invalid weapon" << endl;  
}

if (shield == "Cape Glide") {
    shield_Protection = 40;
     energy -= 20;
        } 
else if (shield == "Smoke Pellet") {
     shield_Protection = 90;
    energy -= 50;
        }
else {
cout << "Invalid shield "<<endl ;
    }
  }
};

class Joker :
public Character {
public:
Joker() : Character("Joker", 100, 500) {}
    void set_w_sh() {
    cout << "choose Joker's weapon (Joy Buzzer, Laughing Gas, Acid Flower): ";
    cin >> weapon;
    cout << "choose Joker's shield (Trick Shield, Rubber Chicken): ";
    cin >> shield;

if (weapon == "Joy Buzzer") {
    damage = 8;
    energy -= 40;
}
else if (weapon == "Laughing Gas") {
 damage = 13;
energy -= 56;
} 
else if (weapon == "Acid Flower") {
damage = 22;
energy -= 100;
}
else {
cout << "Invalid weapon" << endl;
}
if (shield == "Trick Shield") {
    shield_Protection = 32;
    energy -= 15;
} 
else if (shield == "Rubber Chicken") {
shield_Protection = 80;
energy -= 40;
} 
else {
cout << "Invalid shield" << endl;
   }
 }
};
int main() {
    Batman batman;
    Joker joker;
    batman.set_w_sh();
    joker.set_w_sh();

while (batman.getHealth() > 0 && joker.getHealth() > 0) {
 batman.attack(joker);
    if (joker.getHealth() <= 0) {
        cout << "Joker died ,Game over" << endl;
        break;
    }
joker.attack(batman);
    if (batman.getHealth() <= 0) {
        cout << "Batman died ,Game over" << endl;
        break;
    }
}
    if (batman.getHealth() > 0) {
        cout << "Batman wins the game" << endl;
    } else {
        cout << "Joker wins the game" << endl;
    }

    return 0;
}