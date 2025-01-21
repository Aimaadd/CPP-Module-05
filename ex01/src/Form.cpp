#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("Random"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooLowException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooHighException();
    }
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

bool Form::beSigned(Bureaucrat &bureaucrat) {
    if (this->_signed == true) {
        std::cout << "Form is already signed" << std::endl;
        return false;
    }
    try {
        if (bureaucrat.getGrade() > this->_gradeToSign) {
            throw Form::GradeTooLowException();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    std::cout << "Form " << this->_name << " is signed by " << bureaucrat.getName() << std::endl;
    return this->_signed = true;
}

Form &Form::operator=(Form const &src) {
    if (this != &src) {
        this->_signed = src._signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& src) {
    os << "Form: " << src.getName() << ", Grade to Sign: " << src.getGradeToSign() 
       << ", Grade to Execute: " << src.getGradeToExecute();
    return os;
}

const std::string& Form::getName() const {
    return this->_name;
}

int Form::getGradeToSign() const{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}