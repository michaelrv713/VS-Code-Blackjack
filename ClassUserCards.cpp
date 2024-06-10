//
//  ClassUserCards.cpp
//  Blackjack
//
//  Created by Michael Velarde on 6/5/24.
//

#include "ClassUserCards.hpp"
using namespace std;

void UserCard::SetValue(int genValue)
{
    value = genValue;
    // TODO: Create alternate situation for an ace (11) where it is one if
    // total is over 21.
}

int UserCard::GetValue()
{
    return value;
}

void UserCards::DrawCard(int randNum)
{

UserCard newCard;
newCard.SetValue(randNum);
cardPile.push_back(newCard);


}

void UserCards::SetTotal()
{

UserCard currCard;

for (int i = 0; i < cardPile.size(); ++i)
{

currCard = (cardPile.at(i)) ;  // TODO: UPDATE THIS LINE SO IT SPECIFICALLY ACCESSES THE VALUE SET AT cardPile!!!!!
total = total + currCard.GetValue();

}

}

int UserCards::GetTotal()
{

return total;

}


