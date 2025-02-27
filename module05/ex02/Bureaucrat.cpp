/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:10:24 by thhusser          #+#    #+#             */
/*   Updated: 2022/05/09 12:45:40 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(0) {
	for (int i = 0; i < grade; i++) {
		gradeIncrement();
	}
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name){
	if (src._grade > 150)
		throw Bureaucrat::GradeTooHighException();
	if (src._grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = src._grade;
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		if (rhs._grade > 150)
			throw Bureaucrat::GradeTooHighException();
		if (rhs._grade < 1)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string		Bureaucrat::getName(void) const {
	return (this->_name);
}

int				Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void			Bureaucrat::gradeIncrement(void) {
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::gradeDecrement(void) {
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

const char		*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high !\n");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low !\n");
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName();
	o << ", bureaucrat grade : ";
	o << rhs.getGrade();
	o << ".\n";
	return (o);
}

void			Bureaucrat::executeForm(Form const & form) {
	if(!form.getSigned()) {
		std::cout << "Form is not signed : " << form.getName() << " !\n";
	}
	else if (form.getGradeExecute() < this->_grade)
		std::cout << this->_name << " grade too low for executs " << form.getName() << " !\n";
	else
		std::cout << this->_name << " execute " << form.getName() << " !\n";
	form.execute(*this);
}

void			Bureaucrat::signForm(Form & src) {
	src.beSigned(*this);
	if (src.getSigned() == true)
		std::cout << this->_name << " signed " << src.getName() << " !" << std::endl;
	else {
		std::cout << this->_name << " couldn’t sign " << src.getName() << " because ";
		std::cout << "grade for sign is too low !\nYour grade is " << this->_grade;
		std::cout << " and grade for sign is " << src.getGradeSigned() << std::endl;
	}
}
