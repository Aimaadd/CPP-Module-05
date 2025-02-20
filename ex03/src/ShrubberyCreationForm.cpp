#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm(src) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

bool ShrubberyCreationForm::execute(Bureaucrat &executor) const {
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
    std::cout << _target + "_shrubbery file created !" << std::endl;
    this->writeToFile(this->_target + "_shrubbery");
    return _executed;
}

void ShrubberyCreationForm::writeToFile(std::string filename) const {
    std::ofstream file;
    int filename_len = filename.length();
    char tmp[filename_len + 1];
    strcpy(tmp, filename.c_str());
    file.open(tmp);
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}