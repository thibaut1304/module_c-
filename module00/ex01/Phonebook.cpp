/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:43:06 by thhusser          #+#    #+#             */
/*   Updated: 2022/01/02 16:39:06 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
}

std::string Phonebook::getFirst_name() const {
    return (this->first_name);
}

std::string Phonebook::getLast_name() const {
    return (this->last_name);
}

std::string Phonebook::getNickname() const {
    return (this->nickname);
}

std::string Phonebook::getPhone_number() const {
    return (this->phone_number);
}

std::string Phonebook::getDarkest_secret() const {
    return (this->darkest_secret);
}

void    Phonebook::add(std::string FN, std::string LN, std::string NN, std::string PN, std::string DS) {
    this->first_name = FN;
    this->last_name = LN;
    this->nickname = NN;
    this->phone_number = PN;
    this->darkest_secret = DS;
}
