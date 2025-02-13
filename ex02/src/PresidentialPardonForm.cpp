#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat &executor) const {
    if (this->_signed == false) {
        std::cout << "This form is not signed and can't be executed\n";
        this->_executed = false;
        return _executed;
    }
    if (this->_executed == true) {
        std::cout << "This form can't be executed more than once\n";
        return _executed;
    }
    try {
        if (executor.getGrade() > this->_gradeToExecute) {
            std::cout << executor.getName() << " can't execute this form : ";
            throw AForm::GradeTooLowException();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    std::cout << "AForm " << this->_name << " is executed by " << executor.getName() << std::endl;
    this->_executed = true;
    return _executed;
}

