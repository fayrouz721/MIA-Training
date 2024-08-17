# Batman VS Joker Fight Game

## Overview

This is a console-based fight simulation game implemented in C++. The game features two characters, Batman and Joker, who can choose weapons or shields and attack each other until one character's health drops to zero or below. The game continues in turns until a winner is determined.

## Features

- **Characters**: Batman and Joker, each with unique weapons and shields.
- **Weapons**: Different weapons with varying damage and energy costs.
- **Shields**: Different shields that reduce the damage received from attacks.
- **Turn-Based System**: Characters take turns choosing actions and attacking each other.
- **Health and Energy Management**: Each character's health and energy are tracked and updated throughout the game.

## How It Works

1. **Character Initialization**:
    - Batman starts with 100 health and 500 energy.
    - Joker starts with 100 health and 500 energy.
2. **Action Choices**:
    - **Weapon Choice**: Characters can choose a weapon which will deal damage and consume energy.
    - **Shield Choice**: Characters can choose a shield which will provide protection and consume energy.
3. **Turn-Based Combat**:
    - Each turn, a character chooses an action (weapon or shield).
    - The opponent's health is updated based on the attack and shield protection.
    - The game continues until one character's health drops to zero or below.

## Code Explanation

### Character Class

- **Attributes**:
    - `name`: Name of the character.
    - `weapon`: Current weapon equipped.
    - `shield`: Current shield equipped.
    - `health`: Current health of the character.
    - `energy`: Current energy of the character.
    - `damage`: Damage dealt by the character.
    - `shield_Protection`: Protection provided by the shield.
- **Methods**:
    - `choose_action()`: Allows the character to choose a weapon or shield.
    - `attack(Character& opponent)`: Performs an attack on the opponent, considering shield protection.

### Batman Class

- **Initialization**: Set up with a fixed health of 100 and energy of 500.
- **Actions**:
    - **Weapons**:
        - Batarang: Damage 11, Energy cost 50
        - Grapple Gun: Damage 18, Energy cost 88
        - Explosive Gel: Damage 10, Energy cost 92
        - Batclaw: Damage 20, Energy cost 120
    - **Shields**:
        - Cape Glide: Protection 40, Energy cost 20
        - Smoke Pellet: Protection 90, Energy cost 50

### Joker Class

- **Initialization**: Set up with a fixed health of 100 and energy of 500.
- **Actions**:
    - **Weapons**:
        - Joy Buzzer: Damage 8, Energy cost 40
        - Laughing Gas: Damage 13, Energy cost 56
        - Acid Flower: Damage 22, Energy cost 100
    - **Shields**:
        - Trick Shield: Protection 32, Energy cost 15
        - Rubber Chicken: Protection 80, Energy cost 40

### Main Function

- Creates instances of `Batman` and `Joker`.
- Runs a loop where each character takes turns choosing actions and attacking.
- Ends when one character's health reaches zero or below.

## Example Output

```cpp
pythonCopy code
Choose an action for Batman:
1. Choose weapon
2. Choose shield
1
Choose Batman's weapon (Batarang, Grapple Gun, Explosive Gel, Batclaw): Batarang
Batman attacks with Batarang
Joker's remaining health: 89

Choose an action for Joker:
1. Choose weapon
2. Choose shield
1
Choose Joker's weapon (Joy Buzzer, Laughing Gas, Acid Flower): Laughing Gas
Joker attacks with Laughing Gas
Batman's remaining health: 87

...

```

## Notes

- Ensure that you enter valid choices for weapons and shields as prompted.
- Energy consumption and damage values are hard-coded and reflect the design of the game.