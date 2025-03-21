#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Random"), _grade(150) {
    std::cout << _name << " Bureaucrat constructor called " << "grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
    std::cout << _name << "Bureaucrat copy constructor called" << "grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << _name << " Bureaucrat constructor called " << "grade : " << _grade << std::endl;
    if (grade < 1) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

int& Bureaucrat::getGrade() {
    return this->_grade;
}

const std::string& Bureaucrat::getName() {
    return (this->_name);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
    this->_grade = src._grade;
    return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src) {
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

void Bureaucrat::incrementGrade() {
    if (this->_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    std::cout << "Incrementing grade from " << _grade << " to : ";
    this->_grade--;
    std::cout << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << "Decrementing grade from " << _grade << " to : ";
    this->_grade++;
    std::cout << _grade << std::endl;
}