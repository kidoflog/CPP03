/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:27:35 by kkido             #+#    #+#             */
/*   Updated: 2026/06/14 20:44:23 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& src);
  ScavTrap& operator=(const ScavTrap& src);
  ~ScavTrap();
  void attack(const std::string& target);
  void guardGate();

 private:
  bool is_guard;
};

#endif
