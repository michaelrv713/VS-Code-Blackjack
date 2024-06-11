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
    char cue;    // Stores a required user input needed to continue
    int i;
    int j = 3;
    bool bust = false;
    bool win = false;
    
    cout << "Welcome to Blackjack! Press any key to continue: ";
    cin >> cue;
    cout << endl;

    UserCards userPile; // Creates pile
    userPile.DrawCard(Generator()); // Automatically Draws two cards
    userPile.DrawCard(Generator());
    userPile.SetTotal();

    UserCards dealerPile;
    dealerPile.DrawCard(Generator());
    dealerPile.DrawCard(Generator());
    dealerPile.DrawCard(Generator());
    dealerPile.SetTotal();

    
    while ( (win == false) && (bust == false) && (j > 0))
    {
        --j;    // Increments loop such that the game is ended after 3 turns.
       cout << "Total: " << userPile.GetTotal() << endl;
       cout << "Type \'h\' to hit, or any other key to check" << endl;

       cin >> cue;

       if (cue == 'h') 
       {

        userPile.DrawCard(Generator());
        userPile.SetTotal();

       }

       if (userPile.GetTotal() > 21)
       {
        bust = true;

       }
       else if (userPile.GetTotal() == 21)
       {

        win = true;

       }

        // THE GAME WILL RUN IN THIS SPACE.
        
        
    }
    
    cout << "Total: " << userPile.GetTotal() << endl;

    // START OF OUTCOMES FOR WHEN THE GAME IS OVER

    if ( (bust == false) && (win == false) )    // Outcome: Compare with Dealer
    {
        if ( ( (dealerPile.GetTotal() < 21) && (userPile.GetTotal() > dealerPile.GetTotal()) ) || (dealerPile.GetTotal()) > 21 )
        {
            win = true;
        }

    }
    
    if (bust == true)   // Outcome: User busts
    {
        if (dealerPile.GetTotal() > 21)
        {

            cout << "Dealer busts! Tie!";

        }
        else 
        {

            cout << "Bust! Game Over!" << endl;
        }
        
    }
    else if (win == true)   // Outcome: Win
    {
        
        cout << "You Win!" << endl;
        
    }
    else    // Outcome: Dealer Wins
    {
        
        cout << "Dealer Won!" << endl;
        
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
