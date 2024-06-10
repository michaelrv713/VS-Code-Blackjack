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
    
        int value;
        
};

class UserCards
{
    public:
    
        void DrawCard(int randNum);
        void SetTotal();
        int GetTotal();
    
    
    private:
    
        std::vector<UserCard> cardPile;
        int total = 0;
    
};




#endif
