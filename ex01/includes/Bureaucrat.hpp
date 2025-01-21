#include <iostream>

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();
        void SignForm(Form &form);
        Bureaucrat& operator=(Bureaucrat const &src);
        const std::string& getName();
        int& getGrade();
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& os, Bureaucrat &src);