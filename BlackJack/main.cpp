#include <iostream>
#include <array>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <cassert>


namespace MyRandom
{
// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die{ min, max }; // we can create a distribution in any function that needs it
    return die(MyRandom::mersenne); // and then generate a random number from our global generator
}



class Card
{
public:
    enum CardSuit
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,
        MAX_SUITS
    };

    enum CardRank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS
    };
private:
    CardRank m_rank;
    CardSuit m_suit;

public:
    Card(CardRank rank = CardRank::RANK_2, CardSuit suit = CardSuit::SUIT_CLUB)
        : m_rank(rank), m_suit(suit)
    {
    }

    void printCard() const
    {
        switch (m_rank)
        {
        case RANK_2:
            std::cout << '2';
            break;
        case RANK_3:
            std::cout << '3';
            break;
        case RANK_4:
            std::cout << '4';
            break;
        case RANK_5:
            std::cout << '5';
            break;
        case RANK_6:
            std::cout << '6';
            break;
        case RANK_7:
            std::cout << '7';
            break;
        case RANK_8:
            std::cout << '8';
            break;
        case RANK_9:
            std::cout << '9';
            break;
        case RANK_10:
            std::cout << 'T';
            break;
        case RANK_JACK:
            std::cout << 'J';
            break;
        case RANK_QUEEN:
            std::cout << 'Q';
            break;
        case RANK_KING:
            std::cout << 'K';
            break;
        case RANK_ACE:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case SUIT_CLUB:
            std::cout << 'C';
            break;
        case SUIT_DIAMOND:
            std::cout << 'D';
            break;
        case SUIT_HEART:
            std::cout << 'H';
            break;
        case SUIT_SPADE:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
        }
    }

    int getCardValue() const
    {
        switch (m_rank)
        {
        case RANK_2:
            return 2;
        case RANK_3:
            return 3;
        case RANK_4:
            return 4;
        case RANK_5:
            return 5;
        case RANK_6:
            return 6;
        case RANK_7:
            return 7;
        case RANK_8:
            return 8;
        case RANK_9:
            return 9;
        case RANK_10:
            return 10;
        case RANK_JACK:
            return 10;
        case RANK_QUEEN:
            return 10;
        case RANK_KING:
            return 10;
        case RANK_ACE:
            return 11;
        default:
            return 0;
        }

        return 0;
    }
};

class Deck
{
using index_t = std::array<Card, 52>::size_type;

private:
    std::array<Card, 52> m_deck;
    index_t m_cardIndex = 0;

    void swapCard(Card &card1, Card &card2)
    {
        Card temp = card1;
        card1 = card2;
        card2 = temp;
    }

    int getRandomNumber(int min, int max)
    {
        std::uniform_int_distribution<> die{ min, max }; // we can create a distribution in any function that needs it
        return die(MyRandom::mersenne); // and then generate a random number from our global generator
    }


public:
    Deck()
    {
        using index_t = std::array<Card, 52>::size_type;
        index_t card = 0;

        for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
            for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
            {
                m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
                ++card;
            }

    }



    void printDeck()
    {
        for (const auto &card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }

        std::cout << '\n';
    }


    void shuffleDeck()
    {
        // Step through each card in the deck

        for (index_t index = 0; index < 52; ++index)
        {
            // Pick a random card, any card
            index_t swapIndex =  static_cast<index_t>(getRandomNumber(0, 51));
            // Swap it with the current card
            swapCard(m_deck[index], m_deck[swapIndex]);
        }
        m_cardIndex = 0;
    }

    const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}

};


char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(Deck &deck)
{

	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the dealer one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// Player goes first
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();

		// See if the player busted
		if (playerTotal > 21)
			return false;
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}



int main()
{


    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Deck deck;
	deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";
    return 0;
}
