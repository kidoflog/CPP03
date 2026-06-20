/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:46:58 by kkido             #+#    #+#             */
/*   Updated: 2026/06/20 16:57:00 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& src);
  FragTrap& operator=(const FragTrap& src);
  ~FragTrap();
  void highFivesGuys();
};

#endif
