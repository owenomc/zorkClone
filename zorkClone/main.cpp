#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

class Player {
private:
    int hp;          // Player health
    int hpMax;       // Player max health
    int strength;    // Player strength
    int gold;        // Player gold
    int potions;     // Player's count of health potions
    int playerNum = 0; // Player's assigned number base on class
    int book;        // Player's count of books
    int intel;       // Player intelligence
    int WeaponDamage;
    bool canHeal = true;
    string armor[4] = {"knight armor", "archer cloak", "mage robe", "captive pants"};

public:
    // Constructor
    Player() : hp(0), hpMax(0), strength(0), intel(0), gold(0), RubyKey(0), potions(0), book(0), currentRoom(1) {}

    // Public Variables
    int RubyKey;
    int defeatedEnemies = 0;
    int difficulty = 1;
    int exploreOne = 2;
    int exploreTwo = 2;
    int exploreThree = 2;
    int exploreFour = 2;
    int currentRoom ; // Current room is public
    string weapon[4] = {"short sword", "bow", "wand", "fork"};

    // Getter and setter for strength
    int getStrength() const {
        return strength;
    }
    void setStrength(int qstrength) {
        strength = qstrength;
    }

    // Getter and setter for weapon damage
    int getWeaponDamage() const {
        return WeaponDamage;
    }
    void setWeaponDamage(int qweapond) {
        WeaponDamage = qweapond;
    }

    // Getter and setter for weapon name
    string getWeapon() const {
        return weapon[playerNum];
    }

    // Getter and setter for currentRoom
    int getCurrentRoom() const {
        return currentRoom;
    }
    void setCurrentRoom(int room) {
        currentRoom = room;
    }

    // Getter and setter for ruby key
    int getRubyKey() const {
        return RubyKey;
    }
    void setRubyKey(int qRubyKey) {
        RubyKey = qRubyKey;
    }

    // Getter and setter for potions
    void setPotions(int currentPotion) {
        currentPotion = potions;
    }
    int getPotions() const {
        return potions;
    }

    // Getter and setter for intel
    int getIntel() const {
        return intel;
    }
    void setIntel(int newIntel) {
        intel = newIntel;
    }

    // Getter and setter for book
    int getBook() const {
        return book;
    }
    void setBook(int newBook) {
        book = newBook;
    }

    // Getter and setter for gold
    int getGold() const {
        return gold;
    }
    void setGold(int newGold) {
        gold = newGold;
    }

    //  Getter and setter for health and Max Health
    void setHp(int newHp) {
        // Optionally, you might want to add a check to ensure newHp doesn't exceed maxHealth
        hp = newHp;
    }
    int getHp() const {
        return hp;
    }
    int getMaxHp() const {
        return hpMax;
    }

    // Getter and setter for can heal
    void setCanHeal(bool x)
    {
        canHeal = x;
    }
    bool getCanHeal()
    {
        return canHeal;
    }

    // Additional methods to modify player properties
    void addStrength(int amount) { strength += amount; }
    void addHp(int amount) { hp += amount; }
    void addRubyKey(int amount) { RubyKey += amount; }
    void minusRubyKey(int amount) { RubyKey -= amount; }
    void addPotions(int amount) { potions += amount; }
    void addBook(int amount) { book += amount; }
    void addGold(int amount) { gold += amount; }
    void minusGold(int amount) { gold -= amount; }

    // Display player information
    void displayInfo() const {
        cout << "Player health: " << hp << endl;
        cout << "Player max health: " << hpMax << endl;
        cout << "Strength: +" << strength << " damage" << endl;
        cout << "Intelligence: " << intel << endl;
        cout << "Gold: " << gold << endl;
        cout << "Ruby keys: " << RubyKey << endl;
        cout << "Health potions: " << potions << endl;
        cout << "Books: " << book << endl;
    }

    void pickClass() {
        int pickClass = 0;
        cout << "Which armor do you choose (1-4)? " << endl;
        cin >> pickClass;

        switch (pickClass) {
            case 1: {
                playerNum = 0;
                setHp(20);
                hpMax = hp;
                setGold(3);
                setStrength(4);
                setIntel(4);
                setBook(0);
                setWeaponDamage(3);
                break;
            }
            case 2: {
                playerNum = 1;
                setHp(15);
                hpMax = hp;
                setGold(4);
                setStrength(3);
                setIntel(6);
                setBook(1);
                setWeaponDamage(2);
                break;
            }
            case 3: {
                playerNum = 2;
                setHp(10);
                hpMax = hp;
                setGold(4);
                setStrength(2);
                setIntel(10);
                setBook(1);
                setRubyKey(1);
                setWeaponDamage(2);
                break;
            }
            default: {
                playerNum = 3;
                setHp(5);
                hpMax = hp;
                setGold(5);
                setStrength(1);
                setIntel(2);
                setBook(0);
                setWeaponDamage(1);
                break;
            }
        }
        cout << "You picked the " << armor[playerNum] << ", the " << weapon[playerNum] << ", and have " << hp << " health points" << endl;
        cout << '\n';
        cout << "Input commands to guide your player" << endl;
        cout << "Enter: 'stats' for player details or 'explain' for more help" << endl;
        cout << '\n';
        cout << "The journey begins.." << endl;
        currentRoom = 1;
    }

    void handleDifficulty(int diff) {
        if (diff == 1) {
            cout << "EASY DIFFICULTY \n";
            difficulty = 1;
            hpMax -= 1;
        } if (diff == 2) {
            cout << "MEDIUM DIFFICULTY \n";
            hpMax -= 2;
            difficulty = 2;
        } if (diff == 3) {
            cout << "HARD DIFFICULTY\n";
            hpMax -= 3;
            difficulty = 3;
        } if (diff == 4) {
            cout << "INSANE DIFFICULTY \n";
            hpMax -= 4;
            difficulty = 4;
        } if (diff == 5) {
            cout << "EXTREME DIFFICULTY\n";
            hpMax -= 5;
            difficulty = 5;
        }
        cout << " \n";
    }

    void changeDifficulty() {
        cout << "Enter new difficulty (1 is easy, 5 is extreme): \n";

        // Enter input to game menu
        int difEnter;
        cin >> difEnter;
        handleDifficulty(difEnter);
    }
};

class Game {
private:
    // Private Variable
    bool BoughtWeapon = false;

    void weaponUpgrade(Player& player) {
        // Public Variables
        string explorerTrades[4] = {"colossal greatsword", "heart-piercer bow", "dragon-made wand","stainless-steel fork"};

        // Ensure that the arrays are of the same size
        for (int i = 0; i < sizeof(player.weapon) / sizeof(player.weapon[0]); ++i) {
            // Replace each value in player.weapon with the corresponding value from explorerTrades
            player.weapon[i] = explorerTrades[i];
        }
        player.addStrength(4);
        BoughtWeapon = true;
    }

    static void displayValidEntries() {
        // Inputs available
        cout << "VALID ENTRIES and SHORTCUTS:" << endl;
        cout << "explain or e" << endl;
        cout << "stats or s" << endl;
        cout << "explore" << endl;
        cout << "map or m" << endl;
        cout << "read" << endl;
        cout << "rest or r" << endl;
        cout << "inventory or i" << endl;
        cout << "left, right, up, down" << endl;
        cout << "wallet or w" << endl;
        cout << "hint or h" << endl;
        cout << "difficulty or d" << endl;
        cout << "potion or p" << endl;
        cout << "END (will end the game)" << endl;
    }

    void attackCycle(int enemyNum, Player& player) {

        // Upgrades weapon on attack, for buying upgrade
        if (BoughtWeapon) {
            weaponUpgrade(player);
        }

        // Player can not heal
        player.setCanHeal(false);

        // Define Enemies // NPCs included as enemies
        string enemyName[6] = {"Undead", "Skeleton Warden", "Glorious Spider", "Blood-Hunter Demon", "Merchant", "Explorer"};
        string enemyAttack[6] = {"bite", "mace", "web spray",  "hell-storm claw", "large stick", "gold spear"};
        int enemyHealth[6] = {5,15,25,50, 20, 30};
        int enemyDamage[6] = {1, 2, 3, 4, 3, 3};
        // Enemy definitions
        string currentEnemyName = enemyName[enemyNum];
        int currentEnemyHealth = enemyHealth[enemyNum];
        int currentEnemyDamage = enemyDamage[enemyNum];

        // Combat with Enemy
        while (currentEnemyHealth > 0 && player.getHp() > 0) {
            int missChance = rand() % 10 + 1; // Generate random damage between 1 and 9

            cout << '\n';
            cout << "You attack the " << currentEnemyName << " with your " << player.getWeapon() << ". " << endl;
            int playerDamage = player.getWeaponDamage() + player.getStrength(); // Damage from player
            int criticalChance = rand() % 10 + 1; // Generate critical hit chance

            // Chance for miss and critical hit
            if (missChance == 1) {
                playerDamage = 0;
                cout << "You missed the attack" << endl;
            }
            if (criticalChance == 1) {
                playerDamage = playerDamage * 2;
                currentEnemyHealth -= playerDamage;
                cout << "You hit with a critical attack" << endl;
            }
            else
                currentEnemyHealth -= playerDamage;

            if(currentEnemyHealth > 0) {
                cout << "You deal " << playerDamage << " damage." << endl;
                cout << currentEnemyName << " has " << currentEnemyHealth << " health left." << endl;
                cout << '\n';
            }
            else {
                cout << "You deal " << playerDamage << " damage." << endl;
                cout << endl;
            }
            if (currentEnemyHealth <= 0) {
                cout << "You defeated the " << currentEnemyName << endl;
                int genGold = rand() % 2 + 1;
                cout << "You collected " << genGold << " gold. " << endl;
                // Update player's gold
                player.addGold(genGold);
                player.defeatedEnemies++;
                player.setCanHeal(true);
                if (enemyHealth[3] < 0 ) {
                    killedFinal = 1;
                }

                return; // Exit the function after winning the fight
            }

            int computerDamage = rand() % 2 + 1; // Generate random damage between 1 and 2
            // Scales damage, half of player damage is added to enemy damages
            computerDamage = computerDamage + currentEnemyDamage + round(0.5 * playerDamage);
            // Reduce player's health
            player.addHp(-computerDamage);

            cout << "The " << currentEnemyName << " attacks you by " << enemyAttack[enemyNum] << " and deals "
                 << computerDamage << " damage." << endl;

            if(player.getHp() > 0) {
                cout << "You have " << player.getHp() << " health left." << endl;
            }
            // Update player's health
            if (player.getHp() <= 0) {
                break;
            }

            // Mage class heals after each turn
            if (player.getIntel() >= 10) {
                int healAmount = player.getIntel() - 10;
                cout << "Intel heals for " << healAmount << " hp" << endl;
                // Update player's health
                player.addHp(healAmount);
            }

            cout << '\n';
            cout << "Continue fighting or escape? (y/n): " << endl;
            // Ask if the user wants to continue the fight
            string answer;
            cin >> answer;

            if (answer == "potion" || answer == "p") {
                if (player.getPotions() >= 1) {
                    player.addPotions(-1);
                    player.addHp(5);
                    cout << "You gained 5 hp" << endl;
                }
                else
                    cout << "You have no potions" << endl;
            }

            if (answer == "n") {
                int tryEscape = rand() % 10 + 1;
                if (tryEscape > 5) {
                    cout << "You got out" << endl;
                    player.setCanHeal(true);
                    return;
                }
                else
                    cout << "You can't escape " << endl;
            }
        }
    }

    void exploreRoom(Player& player) {
        int currentRoom = player.getCurrentRoom();

            if (currentRoom == 1) {
                if (player.exploreOne > 0) {
                    int genItem = rand() % 10 + 1;
                    if (genItem == 1) {
                        player.addRubyKey(1);
                        cout << "You found a ruby key!" << endl;
                    } else if (genItem == 2 || genItem == 3) {
                        player.addGold(5);
                        cout << "You found 5 gold!" << endl;
                    } else if (genItem == 4 || genItem == 5 ) {
                        cout << "You found an enemy!" << endl;
                        attackCycle(0, player);
                    } else if (genItem == 6) {
                        cout << "You found a book!" << endl;
                        player.addBook(1);
                    } else if (genItem >= 7) {
                        player.addPotions(1);
                        cout << "You found a potion!" << endl;
                    }
                    if (player.getIntel() > 5) {
                        cout << "There is an open path to the right" << endl;
                    } else cout << "All you see is darkness" << endl;
                    player.exploreOne--;
                } else cout << "Nothing here to explore" << endl;
            }
            if (currentRoom == 2) {
                if (player.exploreTwo > 0) {
                    int genItem = rand() % 10 + 1;
                    if (genItem == 1 || genItem == 2) {
                        player.addRubyKey(1);
                        cout << "You found a ruby key!" << endl;
                    } else if (genItem == 3 || genItem == 4) {
                        player.addGold(6);
                        cout << "You found 6 gold!" << endl;
                    } else if (genItem == 5) {
                        cout << "You found an enemy!" << endl;
                        attackCycle(0,player);
                    } else if (genItem >= 6) {
                        player.addPotions(1);
                        cout << "You found a potion!" << endl;
                    }
                    player.exploreTwo--;
                } else cout << "Nothing here to explore" << endl;
                if (player.getIntel() > 5) {
                    cout << "There is a shadow to the left" << endl;
                } else cout << "You have no idea where to go" << endl;

            }
            if (currentRoom == 3) {
                if (player.exploreThree > 0) {
                    int genItem = rand() % 10 + 1;
                    if (genItem == 1 || genItem == 2) {
                        player.addGold(7);
                        cout << "You found 7 gold!" << endl;
                    } else if (genItem >= 3) {
                        player.addRubyKey(1);
                        cout << "You found a ruby key!" << endl;
                    }
                    player.exploreThree--;
                    if (player.getIntel() > 8) {
                        cout << "You see spiders crawling on the left wall" << endl;
                    } else cout << "You sense a dark presence near" << endl;

                } else cout << "Nothing here to explore" << endl;

            }
            if (currentRoom == 4) {
                if (player.getIntel() > 8) {
                    cout << "There is a large hallway to the right" << endl;
                } else cout << "Nothing here to explore" << endl;
                cout << "You are overcome with fear" << endl;
                player.exploreFour = player.exploreFour - 2;
            }
            if (currentRoom == 5) {
                cout << "There is nothing here to explore" << endl;
            }
    }

    void displayMap(Player& player) {
        int currentRoom = player.getCurrentRoom();
            if (currentRoom == 1) {
                cout << "you can go down or right" << endl;
                // First For Loop (1-15)
                for(int a=1;a<=15;a++)
                {
                    cout<<"*"; // Print an asterisk (*) 15 times horizontally
                }
                cout<<endl; // Move to the next line after printing 15 asterisks

                // Second For Loop (1-3)
                for(int b=1;b<=3;b++)
                {
                    // Inner For Loop (1 time)
                    for(int c=1;c<=1;c++)
                    {
                        cout<<"*"; // Print an asterisk (*) once
                    }

                    // Inner For Loop (13 times)
                    for(int d=1;d<=13;d++)
                    {
                        cout<<" "; // Print a space ( ) 13 times, creating a gap
                    }

                    cout<<"*"<<endl; // Print an asterisk (*) and move to the next line
                }

                // Third For Loop (1-15)
                for(int e=1;e<=15;e++)
                {
                    cout<<"*"; // Print an asterisk (*) 15 times horizontally
                }

                cout << endl;

            }
            if (currentRoom == 2) {
                cout << "you can go up or left" << endl;

                int size = 8;

                // Top of diamond
                for (int i = 0; i < size; i++) {

                    // Prints spaces on left
                    for (int j = 0; j < size - i; j++) {
                        cout << " ";
                    }

                    // Prints in each row
                    for (int k = 0; k < 2 * i + 1; k++) {
                        if (k == 0 || k == 2 * i) {
                            cout << "*"; // Adds asterisks
                        } else {
                            cout << " "; // Adds spaces
                        }
                    }
                    cout << endl; // Moves to the next line
                }

                // Bottom of diamond
                for (int i = size - 2; i >= 0; i--) {

                    // Prints spaces on left
                    for (int j = 0; j < size - i; j++) {
                        cout << " ";
                    }

                    // Prints in each row
                    for (int k = 0; k < 2 * i + 1; k++) {
                        if (k == 0 || k == 2 * i) {
                            cout << "*"; // Adds asterisks
                        } else {
                            cout << " "; // Adds spaces
                        }
                    }
                    cout << endl;  // Moves to the next line
                }

            }
            if (currentRoom == 3) {
                cout << "you can go left, up and right" << endl;
                int height = 6; // Width of outer rectangle
                int width = 20; // Width of outer rectangle
                int innerHeight = 2; // Height of the inner rectangle
                int innerWidth = 8; // Width of the inner rectangle
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                            cout << "*"; // Print asterisk for outer rectangle
                        } else if (i >= (height - innerHeight) / 2 && i < (height + innerHeight) / 2 &&
                                   j >= (width - innerWidth) / 2 && j < (width + innerWidth) / 2) {
                            cout << "*"; // Print asterisk for inner rectangle
                        } else {
                            cout << " "; // Print a space for the inside of both rectangles
                        }
                    }
                    cout << endl; // Moves to the next line
                }
            }
            if (currentRoom == 4) {
                cout << "you can go up and right" << endl;
                // First For Loop (1-32)
                for(int a=1;a<=32;a++)
                {
                    cout<<"*"; // Print an asterisk (*) 32 times horizontally
                }
                cout<<endl; // Move to the next line after printing 32 asterisks
                // Second For Loop (1-8)
                for(int b=1;b<=8;b++)
                {
                    // Inner For Loop (1 time)
                    for(int c=1;c<=1;c++)
                    {
                        cout<<"*"; // Print an asterisk (*) once
                    }
                    // Inner For Loop (26 times)
                    for(int d=1;d<=30;d++)
                    {
                        cout<<" "; // Print a space ( ) 18 times, creating a gap
                    }
                    cout<<"*"<<endl; // Print an asterisk (*) and move to the next line
                }
                // Third For Loop (1-32)
                for(int e=1;e<=32;e++)
                {
                    cout<<"*"; // Print an asterisk (*) 32 times horizontally
                }
                cout << endl;
            }
            if (currentRoom == 5) {
                cout << "you can go down" << endl;
                // Defines radius for circle
                int radius = 10;
                // Starts a for loop
                for (int i = -radius; i <= radius; i++) {
                    // z is current column, goes over circle
                    for (int z = -radius; z <= radius; z++) {
                        // Checks if (i, z) is on the circle
                        // Uses pythagorean theorem
                        if (fabs(sqrt(i * i + z * z) - radius) < 0.7) {
                            cout << "* ";  // Adds asterisks
                        } else {
                            if (i == 0 && z == 0) {
                                cout << "+ "; // Adds a plus sign in middle of circle
                            } else if (z == 0 && i < 0) {
                                cout << "| "; // Adds lines from top to center of circle
                            } else {
                                cout << "  "; // Adds empty spaces in circle
                            }
                        }
                    }
                    cout << endl; // Goes to a new row
                }

            }
            cout << "You are in room " << currentRoom << endl;
    }

    void usePotion(Player& player) {
        if (player.getPotions() >= 1) {
            (player.setPotions(player.getPotions() - 1));
            player.setHp(player.getHp() + 5);
            cout << "You gained 5 hp" << endl;
        } else cout << "You have no potions" << endl;
    }

    void readBook(Player& player) {
            if (player.getBook() >= 1) {
                player.setBook(player.getBook() - 1);
                player.setIntel(player.getIntel() + 2);
                cout << "You gained intelligence" << endl;
            } else cout << "You have no books left" << endl;
    }

    static void provideHint(Player& player) {
            if (player.currentRoom == 1) {
                cout << "You should go right" << endl;
            }
            if (player.currentRoom == 2) {
                cout << "You should go left" << endl;
            }
            if (player.currentRoom == 3) {
                cout << "You should go left" << endl;
            }
            if (player.currentRoom == 4) {
                cout << "Defeat the boss" << endl;
            }
            if (player.currentRoom == 5) {
                cout << "Defeat the final boss" << endl;
            }
    }

    void displayWallet(Player& player) {
        cout << "You have " << player.getGold() << " gold" << endl;
    }

    void rest(Player& player) {
        if (player.getHp() == player.getMaxHp()) {
            cout << "No need for resting" << endl;
            return;
        } if (!player.getCanHeal()) {
            cout << "No resting in combat" << endl;
            return;
        } else {
            cout << "You are now rested" << endl;
            player.setHp( player.getMaxHp());
            cout << "You have " << player.getHp() << " hp with a max of " << player.getMaxHp() << endl;
            return;
        }
    }

    void displayInventory(Player& player) {
        cout << "Player weapon: " << player.getWeapon() << endl;
        cout << "Ruby key: " << player.getRubyKey() << endl;
        cout << "Books: " << player.getBook() << endl;
        cout << "Health potions: " << player.getPotions() << endl;
    }

    void movePlayerUp(Player& player) {
            if (player.currentRoom == 1) {
                cout << "Nowhere to go" << endl;
                attackCycle(0, player);
                return;
            }
            if (player.currentRoom == 2) {
                cout << "Walked back" << endl;
                player.currentRoom = 1;
                return;
            }
            if (player.currentRoom == 3) {
                cout << "Climbed over locked door using large rocks" << endl;
                player.currentRoom = 1;
                cout << "You found a ruby key!" << endl;
                player.RubyKey++;
                return;
            }
            if (player.currentRoom == 4) {
                cout << "You can not get past the spider webs" << endl;
                return;
            }
            if (player.currentRoom == 5) {
                cout << "Nowhere to go" << endl;
                return;
            }
    }

    void movePlayerDown(Player& player) {
            if (player.currentRoom == 1) {
                if (player.RubyKey >= 1) {
                    player.minusRubyKey(1);
                    player.currentRoom = 1;
                    cout << "You managed to open it with a ruby key" << endl;
                    return;
                } else { cout << "Locked door, rocks block it from the other side" << endl;
                    return;
                }
            }
            if (player.currentRoom == 2) {
                cout << "Nowhere to go" << endl;
                return;
            }
            if (player.currentRoom == 3) {
                cout << "Nowhere to go" << endl;
                return;
            }
            if (player.currentRoom == 4) {
                cout << "Nowhere to go" << endl;
                return;
            }
            if (player.currentRoom == 5) {
                cout << "Walked back" << endl;
                player.currentRoom = 4;
                return;
            }
    }

    void movePlayerRight(Player& player) {
            if (player.currentRoom == 1) {
                cout << "As you reach the end of the hallway, you walk into what looks to be an office or study with bookshelves lining the left and back walls."
                        "There is another hallway to the right similar to the one you just came from. In the center of the room is a desk set at a 45-degree angle"
                        " with a stack of papers and behind the is a figure that rises to meet you and it reaches out to attack you." << endl;
                cout << " \n" << endl;
                attackCycle(0,player);

                cout << " \n" << endl;
                cout << "Entered a room" << endl;
                player.currentRoom = 2;

                return;
            }
            if (player.currentRoom == 2) {
                cout << "Nowhere to go" << endl;

                cout << "After the fight, you find a happy looking merchant " << endl;
                merchantSpawn(player);

                return;
            }
            if (player.currentRoom == 3) {
                cout << "As you reach the end of the hallway, you walk into what looks to be an office or study with "
                        "bookshelves lining the right and back walls. There is another very pristine hallway to the left "
                        "similar to the one you saw in the room you started in. In the center of the room is a desk set at "
                        "a 45-degree angle with a stack of papers and behind the is a figure that rises to meet you and as "
                        "soon as you see the skeletal nature of it it reaches out to attack you." << endl;
                cout << " \n" << endl;
                attackCycle(0, player);

                player.currentRoom = 2;
                return;
            }
            if (player.currentRoom == 4) {

                cout << "While walking along a long hallway you fear a strong glare " << endl;

                // Explorer Spawn
                explorerSpawn(player);

                cout << " \n" << endl;
                cout << "You walk into a grand throne room with stairs leading up to a pedestal that extends out to the "
                        "middle of the room. On top of the pedestal is a figure standing and as soon as you see him he "
                        "addresses you. Blood-Hunter Demon: Welcome, I was wondering when or if you would even get here. "
                        "Nonetheless, I must applaud your attempt to escape. But this is where you meet your end" << endl;
                cout << " \n" << endl;

                // Final Boss
                attackCycle(3,player);
                killedFinal = 1;

                player.currentRoom = 5;
                return;
            }
            if (player.currentRoom == 5) {
                cout << "Nowhere to go" << endl;
                return;
            }
    }

    void movePlayerLeft(Player& player) {
            if (player.currentRoom == 1) {
                cout << "Nowhere to go" << endl;
                attackCycle(0, player);
                return;
            }
            if (player.currentRoom == 2) {
                cout << "Entered a room" << endl;
                player.currentRoom = 3;

                cout << "As you reach the end of the hallway, you walk into what looks to be an office or study "
                        "with bookshelves lining the right and back walls. There is another very pristine hallway to the left "
                        "similar to the one you saw in the room you started in. In the center of the room is a desk set at a 45-degree "
                        "angle with a stack of papers and behind the is a figure that rises to meet you and as soon as you see "
                        "the skeletal nature of it it reaches out to attack you." << endl;
                cout << " \n" << endl;

                // Warden Spawn
                attackCycle(1, player);

                cout << " \n" << endl;
                cout << " After your fight with what you presume was the warden, you walk into a very fancy dining room "
                        "with immaculate-looking food. You also notice a painting behind each chair. With a hallway that "
                        "veers left at the other end of the room and in the back right corner, there is another hallway "
                        "similar to the one you didn't go down where you woke up." << endl;
                cout << " \n" << endl;

                return;
            }
        if (player.currentRoom == 3) {
            if (player.getRubyKey() >= 1) {
                cout << "You managed to open it with a ruby key" << endl;
                cout << "Entered a room" << endl;
                player.currentRoom = 4;
                player.minusRubyKey(1);

                cout << " \n" << endl;
                cout << "After walking past the tempting feast you walk through a tunnel of spider webs, you stumble "
                        "into an opening and you realize that something has been watching you. It locks eyes with you "
                        "and continues to sit and watch you, until.. " << endl;
                cout << " \n" << endl;

                // Boss Spider
                attackCycle(2, player);

                return;
            } else { cout << "Locked door, with a red lock" << endl;
                return;
            }
        }
        if (player.currentRoom == 4) {
            cout << "Nowhere to go" << endl;
            return;
        }
        if (player.currentRoom == 5) {
            cout << "Nowhere to go" << endl;
            return;
        }
    }

public:

    void merchantSpawn(Player player) {
        cout << "Merchant: Welcome traveler, would you like to trade?" << endl;
        cout << "Trade for 5 gold or fight? (y/n): " << endl; // Ask if the user wants to continue the fight
        string merchantResponse;
        cin >> merchantResponse;
        if (merchantResponse == "y") {
            int tradeItem = rand() % 3 + 1; // Generate random damage between 1 and 3
            if (tradeItem == 1) {
                cout << "You got a potion" << endl;
                player.addPotions(1);
            }
            if (tradeItem == 2) {
                cout << "You got a book" << endl;
                player.addBook(1);
            }
            if (tradeItem == 3) {
                cout << "You got a ruby key" << endl;
                player.addRubyKey(1);
            }
            tradeItem = 0;
            cout << "Farewell traveler" << endl;

            player.minusGold(5);
            return;
        } else {
            cout << "Merchant: Good luck, you incompetent fool" << endl;
            attackCycle(4, player);
        }
    }

    void explorerSpawn(Player player) {
        cout << "Explorer: Ah yes a new victim, would you like to trade before your demise?" << endl;
        cout << "Trade for 15 gold or fight? (y/n): " << endl; // Ask if the user wants to continue the fight
        string explorerResponse;
        cin >> explorerResponse;
        if (explorerResponse == "y") {

            if (player.getGold() >= 15) {
                weaponUpgrade(player);
            } cout << "Not enough gold" << endl;

            // Attacks you either way
            attackCycle(5, player);

            player.minusGold(15);
            cout << "New weapon acquired" << endl;

            cout << " \n" << endl;
            cout << "Farewell traveler" << endl;
        } if (explorerResponse == "n") {
            cout << "Merchant: Wrong choice to fight someone like me" << endl;

            // User chooses to attack
            attackCycle(5, player);
            weaponUpgrade(player);
        }
    }

    void finalText(Player& player) {
        int dif = player.difficulty;

        cout << " \n";
        cout << "You find yourself crawling into the light " << endl;
        cout << "The dungeon has been conquered " << endl;
        cout << "You wander into the distance" << endl;
        cout << '\n';
        cout << "You defeated " << player.defeatedEnemies << " enemies " << endl;
        cout << "You completed on: ";
        if (dif == 1) {
            cout << "EASY DIFFICULTY \n";
        } if (dif == 2) {
            cout << "MEDIUM DIFFICULTY \n";
        } if (dif == 3) {
            cout << "HARD DIFFICULTY\n";
        } if (dif == 4) {
            cout << "INSANE DIFFICULTY \n";
        } if (dif == 5) {
            cout << "EXTREME DIFFICULTY\n";
        }
        cout << '\n';
        cout << "Thanks for playing!"  << endl;
    }

    void promptCalling(const string& input, Player& player) {
        // Main Inputs
        if (input == "explain" || input == "e") {
            displayValidEntries();
        } else if (input == "explore") {
            exploreRoom(player);
        } else if (input == "map" || input == "m") {
            displayMap(player);
        } else if (input == "potion" || input == "p") {
            usePotion(player);
        } else if (input == "read") {
            readBook(player);
        } else if (input == "stats" || input == "s") {
            player.displayInfo();
        } else if (input == "hint" || input == "h") {
            provideHint(player);
        } else if (input == "wallet" || input == "w") {
            displayWallet(player);
        } else if (input == "rest" || input == "r") {
            rest(player);
        } else if (input == "inventory" || input == "i") {
            displayInventory(player);
        } else if (input == "up") {
            movePlayerUp(player);
        } else if (input == "down") {
            movePlayerDown(player);
        } else if (input == "right") {
            movePlayerRight(player);
        } else if (input == "left") {
            movePlayerLeft(player);
        } else if (input == "difficulty" || input == "d") {
            player.changeDifficulty();
        }
    }

    // Public Variable
    int killedFinal = 0;
};

void gameIntro(Player& player) {
    cout << '\n';
    cout << "Welcome to Kork's Adventure" << endl;
    cout << '\n';
    cout << "You awake from a deep slumber, unknowing of who you are or where you are. "  << endl;
    cout << "After a brief look around you gather you are locked in an underground dungeon. "  << endl;
    cout << "You see three sets of equipment and two long hallways. " << endl;
    cout << "Walking closer you find a knight, archer, mage, and captive armor sets " << endl;
    player.setCurrentRoom(1);
}

void gameLoop(Game& game, Player& player) {
    // Display game menu
    cout << "Game Start Menu \n";
    cout << "Select one of the following (1-3): \n";
    cout << "1 - Play \n";
    cout << "2 - Settings \n";
    cout << "3 - Quit \n";

    // Enter input to game menu
    int gamechoice;
    cin >> gamechoice;

    // Game menu
    switch (gamechoice) {
        case 1:
            cout << "STARTING THE GAME \n";
            break;
        case 2:
            cout << "CURRENT DIFFICULTY: \n";
            player.changeDifficulty();
            gameLoop(game, player);
            break;
        case 3:
            cout << "LEAVING THE GAME \n";
            exit(0);
        default:
            cout << "ERROR gamechoice \n";
            gameLoop(game, player);
            break;
    }

    gameIntro(player);
    player.pickClass();

    while (gamechoice <= 5) {
        string input;

        do {
            // Lose condition
            if (player.getHp() <= 0) {
                cout << '\n';
                cout << "You are dead..." << endl;
                cout << '\n';
                cout << "Would you like to restart? (y/n)" << endl;
                char restart;
                cin >> restart;
                if (restart == 'y') {
                    gameLoop(game,player);
                } else
                    exit(0);
            }

            // Win condition
            if (game.killedFinal == 1) {
                game.finalText(player);

                cout << '\n';
                cout << "Would you like to restart? (y/n)" << endl;
                char restart;
                cin >> restart;
                if (restart == 'y') {
                    gameLoop(game,player);
                } else
                    exit(0);
            }

            // Player enters prompts
            cin >> input;
            game.promptCalling(input, player);

        } while (input != "END");
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    Game game;
    Player player;
    gameLoop(game, player);

    return 0;
}