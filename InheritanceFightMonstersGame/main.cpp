#include <array>
#include <iostream>
#include <string>
#include <string_view> // std::string_view requires C++17
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
  static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}


class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

public:
    Creature(const std::string& name, char symbol, int health, int damage, int gold)
        : m_name{ name },
          m_symbol{ symbol },
          m_health{ health },
          m_damage{ damage },
          m_gold{ gold }
    {
    }

    const std::string& getName() const
    {
        return m_name;
    }
    char getSymbol() const
    {
        return m_symbol;
    }
    int getHealth() const
    {
        return m_health;
    }
    int getDamage() const
    {
        return m_damage;
    }
    int getGold() const
    {
        return m_gold;
    }

    void reduceHealth(int health)
    {
        m_health -= health;
    }
    bool isDead() const
    {
        return m_health <= 0;
    }
    void addGold(int gold)
    {
        m_gold += gold;
    }
};

class Player : public Creature
{
    int m_level{ 1 };

public:
    Player(std::string name)
        : Creature{ name, '@', 10, 1, 0 }
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() const
    {
        return m_level;
    }

    bool hasWon()
    {
     return m_level >= 20;
    }
};

class Monster : public Creature
{
public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

private:
    struct MonsterData
    {
        std::string_view name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    // Note: If you're using std::string, you can't make monsterData constexpr,
    // Note: remove constexpr and define the array outside of the class.
    static constexpr std::array<MonsterData, Monster::MAX_TYPES> monsterData
    {
        {   { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 }
        }
    };

public:
    Monster(Type type)
        : Creature
    {
        monsterData[type].name.data(),
        monsterData[type].symbol,
        monsterData[type].health,
        monsterData[type].damage,
        monsterData[type].gold
    }
    {
    }

    static Monster getRandomMonster()
    {
        int num{ getRandomNumber(0, MAX_TYPES - 1) };
        return Monster{ static_cast<Type>(num) };
    }
};

// This function handles the player attacking the monster
void attackMonster(Player& p, Monster& m)
{
  // If the player is dead, we can't attack the monster
  if (p.isDead())
    return;

  std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

  // Reduce the monster's health by the player's damage
  m.reduceHealth(p.getDamage());

  // If the monster is now dead, level the player up
  if (m.isDead())
  {
    std::cout << "You killed the " << m.getName() << ".\n";
    p.levelUp();
    std::cout << "You are now level " << p.getLevel() << ".\n";
    std::cout << "You found " << m.getGold() << " gold.\n";
    p.addGold(m.getGold());
  }
}

// This function handles the monster attacking the player
void attackPlayer(const Monster& m, Player& p)
{
  // If the monster is dead, it can't attack the player
  if (m.isDead())
    return;

  // Reduce the player's health by the monster's damage
  p.reduceHealth(m.getDamage());
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player& p)
{
  // First randomly generate a monster
  Monster m{ Monster::getRandomMonster() };
  std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

  // While the monster isn't dead and the player isn't dead, the fight continues
  while (!m.isDead() && !p.isDead())
  {
    std::cout << "(R)un or (F)ight: ";
    char input;
    std::cin >> input;
    if (input == 'R' || input == 'r')
    {
      // 50% chance of fleeing successfully
      if (getRandomNumber(1, 2) == 1)
      {
        std::cout << "You successfully fled.\n";
        return; // success ends the encounter
      }
      else
      {
        // Failure to flee gives the monster a free attack on the player
        std::cout << "You failed to flee.\n";
        attackPlayer(m, p);
        continue;
      }
    }

    if (input == 'F' || input == 'f')
    {
      // Player attacks first, monster attacks second
      attackMonster(p, m);
      attackPlayer(m, p);
    }
  }
}

int main()
{
  std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
  std::rand(); // get rid of first result

  std::cout << "Enter your name: ";
  std::string playerName;
  std::cin >> playerName;

  Player p{ playerName };
  std::cout << "Welcome, " << p.getName() << '\n';

  // If the player isn't dead and hasn't won yet, the game continues
  while (!p.isDead() && !p.hasWon())
    fightMonster(p);

  // At this point, the player is either dead or has won
  if (p.isDead())
  {
    std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  else
  {
    std::cout << "You won the game with " << p.getGold() << " gold!\n";
  }

  return 0;
}
