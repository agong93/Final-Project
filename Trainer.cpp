//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
//#include "Class3.h"
//#include "Class4.h"
//#include "Class5.h"

//#include "CreatureType.h"

using namespace std;

Trainer::Trainer()
{
    int creature1Health = 0;
    int creature2Health = 0;
    int creature3Health = 0;
    int creature4Health = 0;
    int enemyHealth = 0;
    enemyCreatureType = "unknown";
    creature1Type = "unkown";
    creature2Type = "unknown";
    creature3Type = "unknown";
    creature4Type = "unknown";
    string airDealsDoubleDamageToType = "unknown";
    string airReceivesDoubleDamageFromType = "unknown";
    string airDealsHalfDamageToType = "unknown";
    string airReceivesHalfDamageFromType = "unknown";
    string bombastDealsDoubleDamageToType = "unknown";
    string bombastReceivesDoubleDamageFromType = "unknown";
    string bombastDealsHalfDamageToType = "unknown";
    string bombastReceivesHalfDamageFromType = "unknown";
    string coolReceivesDoubleDamageFromType = "unknown";
    string coolDealsDoubleDamageToType = "unknown";
    string coolReceivesHalfDamageFromType = "unknown";
    string coolDealsHalfDamageToType = "unknown";
    string darkReceivesDoubleDamageFromType = "unknown";
    string darkDealsDoubleDamageToType = "unknown";
    string darkReceivesHalfDamageFromType = "unknown";
    string darkDealsHalfDamageToType = "unknown";
    string earthReceivesDoubleDamageFromType = "unknown";
    string earthDealsDoubleDamageToType = "unknown";
    string earthReceivesHalfDamageFromType = "unknown";
    string earthDealsHalfDamageToType = "unknown";
    string funkReceivesDoubleDamageFromType = "unknown";
    string funkDealsDoubleDamageToType = "unknown";
    string funkReceivesHalfDamageFromType = "unknown";
    string funkDealsHalfDamageToType = "unknown";
    string gammaReceivesDoubleDamageFromType = "unknown";
    string gammaDealsDoubleDamageToType = "unknown";
    string gammaReceivesHalfDamageFromType = "unknown";
    string gammaDealsHalfDamageToType = "unknown";
    string hammerReceivesDoubleDamageFromType = "unknown";
    string hammerDealsDoubleDamageToType = "unknown";
    string hammerReceivesHalfDamageFromType = "unknown";
    string hammerDealsHalfDamageToType = "unknown";
    int battlesWon = 0;
    int lastBattleWon = 0;
}

string Trainer::makeMove(stringstream& situation)
{
    ourCreature creature1;
    ourCreature creature2;
    ourCreature creature3;
    ourCreature creature4;
    
    string situationString = situation.str();
    vector<string> lines = splitString(situationString, "\n");
    int pipeLine = -1;
    for (int i=0; i<lines.size(); i++)
    {
        // Store each line in the string line
        string line = lines[i];
        // Store the first char of line in the char c
        char c = line[0];
        // If c is a pipe ('|'), then this is the line that tells us about our
        //    party and the health of each Creature we own.
        if (c == '|')
        {
            // Store which line number this is
            pipeLine = i;
        }
    }
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    for (int i=1; i<creatureHealthBits.size()-1; i++)
    {
        // cout just for testing
        //cout << creatureHealthBits[i] << "\n";
        
        // We are putting the string into a stringStream so we can use >>
        stringstream ss;
        ss << creatureHealthBits[i];
        
        // For example, we have a stringstream ss containing " *Jackal   10/10 "
        // pull the name as a string
        string name;
        ss >> name; // name = "*Jackal"
        
        // pull the health
        int health;
        ss >> health; // health = 10
        
        // Get rid of the slash char
        char slash;
        ss >> slash; // slash = '/'
        
        // get max health
        int maxHealth;
        ss >> maxHealth; // maxHealth = 10
        
        // cout this info for testing purposes
        //cout << "Name: " << name << " health: " << health << "\n";
    }
    
}

char decideMove (char move)
{
    int lastBattleWon = 0;
    int turn = 1;
    int numAttacksCreature1 = 0;
    int numAttacksCreature2 = 0;
    int numAttacksCreature3 = 0;
    int numAttacksCreature4 = 0;
    int creatureInBattle = 0;
    
    while (lastBattleWon != -1) //until all creatures faint
    {
        while (turn == 1)
        {
            if (creature1Health > 12)
            {
                numAttacksCreature1 ++;
                creatureInBattle = 1;
                return 'a';
            }
            else if (creature2Health > 12)
            {
                creatureInBattle = 2;
                return s2;
            }
            else if (creature3Health > 12)
            {
                creatureInBattle = 3;
                return s3;
            }
            else if (creature4Health > 12)
            {
                creatureInBattle = 4;
                return s4;
            }
            else
            {
                creatureInBattle = 1;
                numAttacksCreature1++;
                return 'a';
            }
            turn ++;
        }
        //READ IN DAMAGE RECEIVED, Current health of creature in game, LEARN--check for same name btw our creatures and enemy creature
        
        while (turn == 2)
        {
            if (numAttacksCreature1 == 1)
            {
                
            }
            else if (numAttacksCreature1 == 0)
            {
                if (currentHealth - damageReceived > 0)
                {
                    return a;
                }
                else if (creatureInBattle == 2 && (damageReceived == 2 || damageReceived == 4 || damageReceived == 8))
                {
                    return s1;
                }
                else if (creatureInBattle == 3 && (damageReceived == 2 || damageReceived == 4 || damageReceived == 8))
                {
                    return s1;
                }
                else if (creatureInBattle == 4 && (damageReceived == 2 || damageReceived == 4 || damageReceived == 8))
                {
                    return s1;
                }
            }
        }
    }
    
    
    
    
    
    
    //need to start another loop here if enemy creature is our creature's strength and rest
    //if enemy creature is a new type and we still have a creature type unknown, rest until that creature is full health and switch in to see if we have valuable info to store
    if (creatures[1].getHealthCurr() == 0 && creatures[2].getHealthCurr() == 0 && creatures[3].getHealthCurr() == 0 && creatures[4].getHealthCurr() == 0)
    {
        lastBattlesWon = -1;
        return;
    }
    
    
    void Trainer::finalSituation(stringstream& situation)
    {
        cout << situation.str();
    }
    
    
    // This is something else you can do ONLY for testing.
    // In a previous post, I recommended #including CreatureType.h so that you
    //    can make a Trainer::decide() function that will make the right
    //    decision if you have perfect data about creature types.
    // While developing, you can use the static vector<CreatureType> TYPES to
    //    get that perfect information, though you will eventually need to write
    //    your own function to learn that information from the data that is sent
    //    in via stringstream& situation.
    
    /*
     // This makes ct a copy of the CreatureType for Creature 0 (the Axolotyl).
     // All CreatureType and Element names start with a different letter of the
     //    alphabet (CreatureType is A-Z, Element is A-H).
     CreatureType ct = CreatureType::TYPES[0];
     // You can then get the type of ct, which is 0 because it's the Axolotyl
     int type = ct.getType();
     // You can also directly get info from CreatureTypes::TYPES elements.
     int elementalWeakness3 = CreatureType::TYPES[3].getElementalWeakness();
     */
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situationString;
    
    
    /*
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */
    string response;
    cin >> response;
    
    
    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}

//
//  Class2.h
//  trainer.cpp
//
//  Created by Katie Ried on 12/3/14.
//  Copyright (c) 2014 Katie Ried. All rights reserved.
//

#ifndef __trainer_cpp__Class2__
#define __trainer_cpp__Class2__

#include <string>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

// vvvvvv Your implementations go between this line…

class ourCreature {
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    ourCreature ();
    
    /**
     * Requires: Nothing.
     * Modifies: center, radius, color.
     * Effects:  Overloaded contructor. Sets creature name to "unknown".
     */
    ourCreature (string ourCreatureName, int ourCreatureCurrentHealth, int ourCreatureMaxHealth, string ourCreatureElement);
    
    
    /**
     * Requires: Nothing.
     * Modifies: center.
     * Effects:  Sets creature name.
     */
    void setCreatureName (string ourCreatureName);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns creature name.
     */
    string getCreatureName () const;
    
    /**
     * Requires: Nothing.
     * Modifies: center.
     * Effects:  Sets creature current health.
     */
    void setCreatureHealthCurr (int ourCreatureHealthCurr);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns creature current health.
     */
    int getCreatureHealthCurr () const;
    
    /**
     * Requires: Nothing.
     * Modifies: center.
     * Effects:  Sets creature current health.
     */
    void setCreatureHealthMax (int ourCreatureHealthMax);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns creature current health.
     */
    int getCreatureHealthMax () const;
    
    void setCreatureElement(string ourCreatureElement);
    
    string getCreatureElement() const;
    
    /**
     * Requires: ins is in good state.
     * Modifies: ins, creatureName, creatureMaxHealth, creatureCurrentHealth
     * Effects:  Reads in all three of the above variables from string stream
     */
    void read(stringstream& situation);
    
    
private:
    string creatureName;
    string creatureElement;
    int creatureMaxHealth;
    int creatureCurrentHealth;
    //int creatureAttack;
    //int creatureHealthGainedRest;
};



// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */

