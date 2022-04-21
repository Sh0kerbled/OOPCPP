#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

/*
class Card {
public:
    enum cardvalue
    {
        one = 1,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9,
        ten = 10,
        jack = 11,
        queen = 12,
        king = 13
    };
    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
};

template<typename type>
/*class Hand
{
public:
    Hand()
    {
        m_Cards.reserve(7);
    }

    virtual ~Hand()
    {
        Clear();
    }

    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }

    void Clear()
    {
        std::vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete* iter;
            *iter = nullptr;
        }

        m_Cards.clear();
    }

    int GetValue() const
    {
        if (m_Cards.empty() || m_Cards[0]->GetValue() == 0)
            return 0;

        int total = 0;
        std::vector<Card*>::const_iterator iter;

        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            total += (*iter)->GetValue();

        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            if ((*iter)->GetValue() == Card::ACE)
                containsAce = true;

        if (containsAce && total <= 11) total += 10;

        return total;
    }*

protected:
    std::vector<Card*> m_Cards;
};
*/
class GenericPlayer : public Hand
{
private:
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
    string theName;
public:
    GenericPlayer(const string& name = " ") : theName(name) { }

    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBoosted() const
    {
        return (GetValue() > 21);
    }

    void Bust() const
    {
        cout << theName << " It's too much." << endl;
    }
};
//task 3
class Player : public GenericPlayer
{
public:
    Player(const string& name = "") : GenericPlayer(name) { }

    virtual ~Player() { }

    virtual bool IsHitting() const
    {
        cout << theName << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void Win() const
    {
        cout << theName << " wins.\n";
    }

    void Lose() const
    {
        cout << theName << " lost.\n";
    }

    void Push() const
    {
        cout << theName << " pushes.\n";
    }
};
//task 4
class House : public GenericPlayer
{
public:
    House(const string& name = "House") : GenericPlayer(name) { }

    virtual ~House() { }

    virtual bool IsHitting() const
    {
        return (GetValue() <= 16);
    }

    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
            m_Cards[0]->Flip();
        else
            cout << "No Cards!\n";
    }
};
//task 5
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.IsFaceUp)
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    else
        os << "XX";

    return os;
}
//task 2
#define endll endl<<endl

int main()
{
    //task 1
    int num;
    while (!(cin >> num))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "it's incorrect! ";
    }
    //task 2
    cout << "Unreal" << endll << "Engine";
    return 0;
}