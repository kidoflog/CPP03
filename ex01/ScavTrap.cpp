/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:27:25 by kkido             #+#    #+#             */
/*   Updated: 2026/06/14 21:40:09 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Anonymous", 100, 50, 20), is_guard(false) {
  std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, 100, 50, 20), is_guard(false) {
  std::cout << "ScavTrap: String constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
  std::cout << "ScavTrap: Copy constructor called" << std::endl;
  this->is_guard = src.is_guard;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
  if (this != &src) {
    ClapTrap::operator=(src);
    this->is_guard = src.is_guard;
  }
  std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (!has_enough_hp() || !has_enough_ep()) {
    std::cout << "Attack failed..." << std::endl;
    return;
  }
  if (is_guard) {
    std::cout << "ScavTrap " << this->_name
              << " can't attack! (Gate keeper mode)" << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl;
  _energy_points--;
}

void ScavTrap::guardGate() {
  if (is_guard) {
    std::cout << "ScavTrap " << _name << " is already Gate keeper mode!"
              << std::endl;
    return;
  }
  std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!"
            << std::endl;
  is_guard = true;
}
