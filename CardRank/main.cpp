#include <iostream>
#include <array>
#include <random> // for std::mt19937
#include <ctime> // for std::time

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

struct Card
{
    CardSuit suit;
    CardRank rank;
};

std::string getRankInitails(CardRank rank)
{
    switch(rank)
    {
    case RANK_2:
        return "2";
    case RANK_3:
        return "3";
    case RANK_4:
        return "4";
    case RANK_5:
        return "5";
    case RANK_6:
        return "6";
    case RANK_7:
        return "7";
    case RANK_8:
        return "8";
    case RANK_9:
        return "9";
    case RANK_10:
        return "10";
    case RANK_JACK:
        return "J";
    case RANK_QUEEN:
        return "Q";
    case RANK_KING:
        return "K";
    case RANK_ACE:
        return "A";
    default:
        return "???";
    }
}


std::string getSuitInitails(CardSuit suit)
{
    switch(suit)
    {
    case SUIT_CLUB:
        return "C";
    case SUIT_DIAMOND:
        return "D";
    case SUIT_HEART:
        return "H";
    case SUIT_SPADE:
        return "S";
    default:
        return "???";
    }
}


void printCard(const Card &cardRef)
{
    std::cout << getRankInitails(cardRef.rank)<< getSuitInitails(cardRef.suit) << '\n';
}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

void swapCard(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	// Step through each card in the deck
	using index_t = std::array<Card, 52>::size_type;
	for (index_t index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		index_t swapIndex =  static_cast<index_t>(getRandomNumber(0, 51));
		// Swap it with the current card
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	default:            return 0;
	}

    return 0;
}


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

bool playBlackjack(const std::array<Card, 52> &deck)
{
	// Set up the initial game state
	const Card *cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the dealer one card
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	// Player goes first
	while (true) // infinite loop (until we break or return)
	{
		std::cout << "You have: " << playerTotal << '\n';

		// See if the player has busted
		if (playerTotal > 21)
			return false;

		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}



int main()
{
    std::array<Card, 52> deck;

    // We could initialize each card individually, but that would be a pain.  Let's use a loop.

    using index_t = std::array<Card, 52>::size_type;
    index_t card = 0;

    for (int suit = 0; suit < MAX_SUITS; ++suit)
        for (int rank = 0; rank < MAX_RANKS; ++rank)
        {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
   printDeck(deck);

	shuffleDeck(deck);

	printDeck(deck);

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

    return 0;
}
