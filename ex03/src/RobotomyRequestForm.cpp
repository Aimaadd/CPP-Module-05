#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    this->_robotomized = false;
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) {
    this->_robotomized = false;
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::Robotomize(Bureaucrat &Bureaucrat) const {
    std::srand(std::time(0));
    int randValue = std::rand();
    if (randValue % 2 == 0) {
        std::cout << Bureaucrat.getName() << " is being robotomized" << std::endl;
        this->_robotomized = true;
    }
    else {
        std::cout << Bureaucrat.getName() << " will not get robotomized" << std::endl;
        this->_robotomized = false;
    }
}

bool RobotomyRequestForm::execute(Bureaucrat &executor) const {
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
    Robotomize(executor);
    this->_executed = true;
    return _executed;
}

bool RobotomyRequestForm::getRobo() {
    return this->_robotomized;
}