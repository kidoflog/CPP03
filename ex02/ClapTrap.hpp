/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:02 by kkido             #+#    #+#             */
/*   Updated: 2026/06/23 13:25:59 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const std::string& name, const unsigned int new_hp,
           const unsigned int new_ep, const unsigned int new_ad);
  ClapTrap(const ClapTrap& src);
  ClapTrap& operator=(const ClapTrap& src);
  virtual ~ClapTrap();
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 protected:
  std::string _name;
  unsigned int _hit_points;
  unsigned int _energy_points;
  unsigned int _attack_damage;
  bool has_enough_hp();
  bool has_enough_ep();
};

#endif
