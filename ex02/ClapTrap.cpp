/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 13:33:18 by kkido             #+#    #+#             */
/*   Updated: 2026/06/23 13:25:57 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Anonymous"),
      _hit_points(10),
      _energy_points(10),
      _attack_damage(0) {
  std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name.empty() ? "Anonymous" : name),
      _hit_points(10),
      _energy_points(10),
      _attack_damage(0) {
  std::cout << "ClapTrap: String constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name, const unsigned int new_hp,
                   const unsigned int new_ep, const unsigned int new_ad)
    : _name(name.empty() ? "Anonymous" : name),
      _hit_points(new_hp),
      _energy_points(new_ep),
      _attack_damage(new_ad) {
  std::cout << "ClapTrap: String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
  std::cout << "Copy constructor called" << std::endl;
  this->_name = src._name;
  this->_hit_points = src._hit_points;
  this->_energy_points = src._energy_points;
  this->_attack_damage = src._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
  std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
  if (this != &src) {
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap: Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (!has_enough_hp() || !has_enough_ep()) {
    std::cout << "Attack failed..." << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl;
  _energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!has_enough_hp()) return;
  if (amount >= _hit_points) {
    std::cout << this->_name << " takes " << _hit_points << " points of damage!"
              << std::endl;
    _hit_points = 0;
  } else {
    std::cout << this->_name << " takes " << amount << " points of damage!"
              << std::endl;
    _hit_points = _hit_points - amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  unsigned int repair;
  if (!has_enough_hp() || !has_enough_ep()) {
    std::cout << "Repair failed..." << std::endl;
    return;
  }
  if (_hit_points > UINT_MAX - amount) {
    repair = UINT_MAX - amount;
  } else {
    repair = amount;
  }
  std::cout << this->_name << " is repaired " << repair << " points of health!"
            << std::endl;
  _hit_points = _hit_points + repair;
  _energy_points--;
}

bool ClapTrap::has_enough_hp() {
  if (_hit_points <= 0) {
    std::cout << this->_name << "'s hit point is zero!" << std::endl;
    return false;
  }
  return true;
}

bool ClapTrap::has_enough_ep() {
  if (_energy_points <= 0) {
    std::cout << this->_name << "'s energy point is zero!" << std::endl;
    return false;
  }
  return true;
}
