#include <iostream>
#include <stdexcept>

using namespace std;

class GameEntry
{
private:
    string name;
// player’s name
    int score;
// player’s score

// a game score entry
public:
    GameEntry(const string& n="", int s=0); // constructor
    string getName() const;
// get player name
    int getScore() const;
// get score

};

GameEntry::GameEntry(const string& n, int s) // constructor
    : name(n), score(s) { }
// accessors
string GameEntry::getName() const
{
    return name;

}

int GameEntry::getScore() const
{
    return score;
}


class Scores
{
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
};

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores()
{
    delete[] entries;
}
void Scores::add(const GameEntry& e)   // add a game entry
{
    int newScore = e.getScore();
// score to add
    if (numEntries == maxEntries)
    {
// the array is full
        if (newScore <= entries[maxEntries - 1].getScore())
            return;
// not high enough - ignore
    }
    else
        numEntries++;
// if not full, one more entry
    int i = numEntries-2;
// start with the next to last
    while ( i >= 0 && newScore > entries[i].getScore() )
    {
        entries[i+1] = entries[i];
// shift right if smaller
        i--;
    }
    entries[i+1] = e;
// put e in the empty spot
}


GameEntry Scores::remove(int i)
{
    if ((i < 0) || (i >= numEntries))
// invalid index
        throw std::out_of_range("Invalid index");
    GameEntry e = entries[i];
// save the removed object
    for (int j = i+1; j < numEntries; j++)
        entries[j-1] = entries[j];
// shift entries left
    numEntries--;
// one fewer entry
    return e;
// return the r emoved object
}

void insertionSort(char* A, int n)
{
    for (int i = 1; i < n; i++)
    {
        char cur = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cur))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cur;
    }
}

        int main()
        {
            cout << "Hello world!" << endl;
            return 0;
        }
