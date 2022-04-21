#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;



//task 4
/*class Card {
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

template<typename type>*/
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
};*/

/*class GenericPlayer : public Hand
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
};*/


int main()
{
    int num;
    while (!(cin >> num))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Error ";
    }
}