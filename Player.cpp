#include "Player.h"

#include <utility>
#include "utilities.h"





Player::Player(string name): m_name(std::move(name)),
m_level(STARTING_LEVEL),
m_force(DEFAULT_FORCE),
m_maxHP(DEFAULT_MAX_HP),
m_HP(DEFAULT_MAX_HP),
m_coins(STARTING_COINS)
{

}


void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int amount)
{
    if(m_force + amount >= 0)
        m_force += amount;
    else
        m_force = 0 ;
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        if (m_HP + amount < m_maxHP)
        {
            m_HP += amount;
        }
        else
        {
            m_HP = m_maxHP;
        }
    }
}

void Player::damage(int amount)
{
    if (amount > 0)
    {
        if (m_HP - amount > 0)
        {
            m_HP -= amount;
        }
        else
        {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return m_HP == MIN_HP;
}

void Player::addCoins(int amount)
{
    if (amount > 0)
    {
        m_coins += amount;
    }
}

bool Player::pay(int amount)
{
    if (amount > 0)
    {
        if (m_coins >= amount)
        {
            m_coins -= amount;
            return true;
        }
        return false;
    }
    return true;
}

int Player::getAttackStrength() const
{
    return (m_level + m_force);
}

void Player::printInfo(std::ostream &os) const {
    printPlayerDetails(os, m_name,getJob(), m_level, m_force, m_HP, m_coins);
}
std::ostream& operator<<(std::ostream &os, const Player &player){
    player.printInfo(os);
    return os;
}

string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}



