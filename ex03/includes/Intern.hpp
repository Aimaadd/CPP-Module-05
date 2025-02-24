#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    private: 
        bool _jobDone;
    public:
        Intern();
        Intern(Intern const &src);
        ~Intern();
        Intern& operator=(Intern const &src);
        AForm* makeForm(std::string formName, std::string target);
        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form not found";
                }
        };
};

#endif