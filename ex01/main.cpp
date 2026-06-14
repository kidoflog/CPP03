/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/06/14 19:28:46 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap clappy("Clappy");
  ClapTrap target("TargetDummy");

  clappy.attack("TargetDummy");
  target.takeDamage(5);
  clappy.beRepaired(3);

  target.takeDamage(20);
  target.attack("Clappy");
  target.beRepaired(5);

  for (int i = 0; i < 8; i++) {
    clappy.beRepaired(1);
  }
  clappy.attack("TargetDummy");
  clappy.beRepaired(1);

  return 0;
}
