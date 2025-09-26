/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ClapTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:05 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/26 20:42:36 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
    private:
        std::string _name;
        int         _hitPoints = 10;
        int         _energyPoints = 10;
        int         _attackDamage = 0;
    
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap&   operator=(const ClapTrap& other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif