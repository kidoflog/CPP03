/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:46:55 by kkido             #+#    #+#             */
/*   Updated: 2026/06/22 17:27:33 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Anonymous", 100, 100, 30), is_highfive(false) {
  std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name, 100, 100, 30), is_highfive(false) {
  std::cout << "FragTrap: String constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
  std::cout << "FragTrap: Copy constructor called" << std::endl;
  this->is_highfive = src.is_highfive;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
  std::cout << "FragTrap: Copy assignment operator called" << std::endl;
  if (this != &src) {
    ClapTrap::operator=(src);
    this->is_highfive = src.is_highfive;
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
  if (!has_enough_hp() || !has_enough_ep()) {
    std::cout << "Attack failed..." << std::endl;
    return;
  }
  if (is_highfive) {
    std::cout << "FragTrap " << this->_name
              << " can't attack! (Giving highfive)" << std::endl;
    return;
  }
  std::cout << "FragTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << std::endl;
  _energy_points--;
}

void FragTrap::highFivesGuys() {
  if (!has_enough_hp()) {
    std::cout << "Highfive failed..." << std::endl;
    return;
  }
  if (is_highfive) {
    std::cout << "FragTrap " << _name << " is already giving highfive!"
              << std::endl;
    return;
  }
  std::cout << "FragTrap " << _name << " giving highfive!" << std::endl;
  is_highfive = true;
}
