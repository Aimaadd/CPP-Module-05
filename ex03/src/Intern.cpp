#include "../includes/Intern.hpp"

Intern::Intern() : _jobDone(false) {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
    this->_jobDone = src._jobDone;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &src) {
    if (this != &src) {
        this->_jobDone = src._jobDone;
    }
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    if (formName == "robotomy request") {
        this->_jobDone = true;
        return new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        this->_jobDone = true;
        return new PresidentialPardonForm(target);
    } else if (formName == "shrubbery creation") {
        this->_jobDone = true;
        return new ShrubberyCreationForm(target);
    } else {
        this->_jobDone = true;
        throw Intern::FormNotFoundException();
    }
}