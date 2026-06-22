/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:57:47 by kkido             #+#    #+#             */
/*   Updated: 2026/06/22 17:16:01 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  {
    FragTrap frag("Fraggy");
    frag.attack("Target Dummy");
  }
  {
    FragTrap frag("Chappy");
    frag.highFivesGuys();
  }
  {
    FragTrap frag("LowEnergyBot");
    std::cout << "--- エネルギーを100回消費させます ---" << std::endl;
    for (int i = 0; i < 100; i++) {
      frag.beRepaired(1);
    }
    std::cout << "--- エネルギーが切れた後の行動チェック ---" << std::endl;
    frag.attack("Target");
    frag.beRepaired(5);
    frag.highFivesGuys();
  }
  {
    FragTrap frag("FragileBot");
    std::cout << "--- 120ポイントのダメージを与えます ---" << std::endl;
    frag.takeDamage(120);
    std::cout << "--- 体力が尽きた後の行動チェック ---" << std::endl;
    frag.attack("Target");
    frag.beRepaired(10);
    frag.highFivesGuys();
  }
  {
    FragTrap original("Golden");
    original.highFivesGuys();
    std::cout << "--- コピーコンストラクタの呼び出し ---" << std::endl;
    FragTrap copyConstructed(original);
    copyConstructed.highFivesGuys();
    std::cout << "--- コピー代入演算子の呼び出し ---" << std::endl;
    FragTrap copyAssigned("Temporary");
    copyAssigned = original;
    copyAssigned.highFivesGuys();
  }

  return 0;
}