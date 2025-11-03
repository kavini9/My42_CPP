/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:26:51 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/03 23:42:30 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char* shrubbery = R"(


             ,,**+;.
          %%%,%%%%%%%
        +,'%%**\#-/*%%%%%%` 
     ;%%%%%*%   \# %%%%*+
      ,%%% \\/*  \\_.*%%%%.
   ```% *%%,#,%%%%*(  **** ```
    ***+%%  ,*%%% )#\,%%*%,++
        *+%*+_-\/ #).-"*%%*
             *.) ,/ *%,
______________/)#(_______________
)";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target) {
    std::cout << "ShrubberyCreationForm: Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {
    std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;   
}

const std::string& ShrubberyCreationForm::getTarget() const {return (_target);}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecutability(executor);
    std::ofstream outf ((this->getTarget() + "_shrubbery").c_str());
    if (!outf.is_open())
        throw FileOpenFailException();
    outf << shrubbery << std::endl;
    outf.close();
}

const char* ShrubberyCreationForm::FileOpenFailException::what() const noexcept {
    return "ShrubberyCreationForm::file_open_failed";
}