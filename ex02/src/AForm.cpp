#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Random"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _executed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooLowException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(AForm const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

bool AForm::beSigned(Bureaucrat &bureaucrat) {
    if (this->_signed == true) {
        std::cout << "AForm is already signed" << std::endl;
        return _signed;
    }
    try {
        if (bureaucrat.getGrade() > this->_gradeToSign) {
            std::cout << bureaucrat.getName() << " can't sign this form : ";
            throw AForm::GradeTooLowException();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    std::cout << "AForm " << this->_name << " is signed by " << bureaucrat.getName() << std::endl;
    return this->_signed = true;
}

std::string AForm::getTarget() {
    return this->_target;
}

bool AForm::execute(Bureaucrat &executor) const {
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

AForm &AForm::operator=(AForm const &src) {
    if (this != &src) {
        this->_signed = src._signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& src) {
    os << "AForm: " << src.getName() << ", Grade to Sign: " << src.getGradeToSign() 
       << ", Grade to Execute: " << src.getGradeToExecute();
    return os;
}

const std::string& AForm::getName() const {
    return this->_name;
}

int AForm::getGradeToSign() const{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

const char *AForm::AlreadySignedException::what() const throw() {
    return "Form is already signed";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}