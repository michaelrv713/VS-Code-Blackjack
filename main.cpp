//
//  main.cpp
//  Blackjack
//
//  Created by Michael Velarde on 6/5/24.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "ClassUserCards.hpp"
#include "ClassUserCards.cpp"


int Generator ()
{
    srand (static_cast<unsigned int>(time(0)));
    int result = -5;
    
    result = (rand() % 11) + 1;
    
    return result;
}


int main()
{
    int cue;    // Stores a required user input needed to continue
    int i;
    bool bust = false;
    bool win = false;
    
    cout << "Welcome to Blackjack! Press any key to continue: ";
    cin >> cue;
    cout << endl;
    
    while ( (win == false) && (bust == false) )
    {
        
        UserCards userPile; // Creates pile
        userPile.DrawCard(Generator()); // Automatically Draws two cards
        userPile.DrawCard(Generator());   // REPLACE 5 WITH GENERATOR FUNCTION

        /*
        Test this by outputting the value in UserCard for both elements in the vector.
        */

       userPile.SetTotal();
       cout << userPile.GetTotal();


        bust = true;
        win = true;
        
        
        
        // THE GAME WILL RUN IN THIS SPACE.
        
        
    }
    
    cout << endl;
    
    if (bust == true)
    {
        
        cout << "Bust! Game Over!" << endl;
        
        
    }
    else if (win == true)
    {
        
        cout << "You Win!" << endl;
        
    }
    else
    {
        
        cout << "Error" << endl;
        
    }
    
    

    /*
     Plan: Create Class for userCard with value. Create vector class that uses
     UserCard. Create a function in this document that randomly generates a value.
     Use the vector so that the user can keep adding cards.
     
     Create the game within a while loop that keeps repeating until either boolean is true.
     
     
     Future Goal: Make a 'Multiplayer' Turn-Based Mode where there are two
     users controlled, and the screen goes blank upon every turn.
     
     
     */
   
    return 0;
}
