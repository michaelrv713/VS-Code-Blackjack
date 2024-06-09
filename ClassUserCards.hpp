//
//  Class UserCards.hpp
//  Blackjack
//
//  Created by Michael Velarde on 6/5/24.
//

#ifndef Class_UserCards_hpp
#define Class_UserCards_hpp

#include <stdio.h>
#include <vector>

class UserCard
{
    public:
    
        void SetValue(int genValue);
        int GetValue();
    
    private:
    
        int value = -1;
        
};

class UserCards
{
    public:
    
        void DrawCard();
        void SetTotal(UserCard inputCard);
        int GetTotal();
    
    
    private:
    
        std::vector<UserCard> cardPile;
        int total = 0;
    
};




#endif
