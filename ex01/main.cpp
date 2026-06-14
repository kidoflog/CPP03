/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:51:06 by kkido             #+#    #+#             */
/*   Updated: 2026/06/14 21:42:12 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap scav("Scavy");
  scav.attack("TargetDummy");
  ScavTrap gater("Gater");
  gater.guardGate();
  gater.guardGate();
  gater.attack("Intruder");
  ScavTrap weakling("NoEnergyBot");
  std::cout << "--- エネルギーを50回消費させます ---" << std::endl;
  for (int i = 0; i < 50; i++) {
    weakling.attack("Training Dummy");
  }
  weakling.attack("Training Dummy");
  weakling.beRepaired(10);
  ScavTrap target("FragileBot");
  target.takeDamage(120);
  target.attack("Enemy");
  target.beRepaired(10);
  ScavTrap original("Original");
  original.guardGate();
  ScavTrap copy(original);
  copy.attack("Enemy");
  ScavTrap assign;
  assign = original;
  assign.attack("Enemy");

  return 0;
}
