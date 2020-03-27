#include <iostream>
#include <string>

enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

std::string printMonsterType(MonsterType type)
{
    switch(type)
    {
    case MonsterType::OGRE:
        return "Ogre";
    case MonsterType::DRAGON:
        return "Dragon";
    case MonsterType::ORC:
        return "Orc";
    case MonsterType::GIANT_SPIDER:
        return "GiantSpider";
    case MonsterType::SLIME:
        return "Slime";
    default:
        return "???";
    }

}

void printMonster(Monster monster)
{
    std::cout << "This " << printMonsterType(monster.type) << " is named " << monster.name << " and has " << monster.health << " health\n";
}

int main()
{
    MonsterType ogre = MonsterType::OGRE;
    MonsterType slime = MonsterType::SLIME;
    Monster myMonster1{ogre, "Torg", 145};
    Monster myMonster2{slime, "Blurp", 23};
    printMonster(myMonster1);
    printMonster(myMonster2);
    return 0;
}
