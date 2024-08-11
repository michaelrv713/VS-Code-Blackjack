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


int Generator ()    // Generates the numerical value of a drawn card, or a random number 
{
    srand (static_cast<unsigned int>(time(0)));
    int result = -5;    // Initially assigns the integer with a negative value such that an error in the generator function can be identified
    
    result = (rand() % 10) + 2;
    
    return result;
}

void DealerGame (UserCards& inputdeck)  // Manages the dealer's deck    
{                                       // Pass by Reference in order to directly alter vectors and integers in the class

    inputdeck.DrawCard(Generator());    // Draws first two cards for the Dealer
    inputdeck.DrawCard(Generator());
    inputdeck.SetTotal();

    while (inputdeck.GetTotal() < 13)   // Dealer will continue to hit until total is 13 or higher
    {
        inputdeck.DrawCard(Generator());
        inputdeck.SetTotal();

    }

    for (int i = 0; i < 2; ++i) {
    
        switch (inputdeck.GetTotal())   // Once total is 13 or higher, the total will determine if dealer draws again. 
        {                               // Run 3 times, but if total is 20 or 21, no more cards will be drawn.
            case 13: 
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();
                }
                break;
            case 14:
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();

                }
                break;
            case 15:
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();

                } 
                break;
            case 16:
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();
                }
                break;
            case 17:
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();
                }
                break;
            case 18:
                if ((Generator()) < 11 )
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();
                }
                break;
            case 19:
                if ((Generator()) < 11)
                {
                    inputdeck.DrawCard(Generator());
                    inputdeck.SetTotal();
                }
                break;
            default:
                break;


        }
    
    }



}


int main()
{
    char cue;    // Stores a required user input needed to continue
    int i;
    int j = 3;  // Integer manages the number of turns (3)
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
    DealerGame(dealerPile); // Runs the DealerGame Function to simulate three turns for the dealer

    
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
        if (  (dealerPile.GetTotal() > 21) || ( (userPile.GetTotal() > dealerPile.GetTotal()) ) )
        {
            win = true;
        }

    }
    
    if (bust == true)   // Outcome: User busts
    {
        if (dealerPile.GetTotal() > 21)
        {

            cout << "Dealer busts! Tie!" << endl;

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
        if ( (dealerPile.GetTotal()) <= 21 && (userPile.GetTotal()) < dealerPile.GetTotal() ) {

            cout << "Dealer Won!" << endl;
        }
        if (dealerPile.GetTotal() <= 21 && (userPile.GetTotal()) == dealerPile.GetTotal() ) {

            cout << "Tie! Try Again!" << endl;
        }
        
    }
    
    cout << "Dealer Total: " << dealerPile.GetTotal();
    

    /*
     
     
     Future Goal: Make a 'Multiplayer' Turn-Based Mode where there are two
     users controlled, and the screen goes blank upon every turn.
     
     
     */
   
    return 0;
}
