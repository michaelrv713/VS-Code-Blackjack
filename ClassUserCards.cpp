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


