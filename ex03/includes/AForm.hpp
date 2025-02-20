#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    protected:
        const std::string _name;
        bool _signed;
        mutable bool _executed;
        const int _gradeToSign;
        const int _gradeToExecute;
        std::string _target;
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &src);
        ~AForm();
        bool beSigned(Bureaucrat &bureaucrat);
        virtual bool execute(Bureaucrat &bureaucrat) const;
        AForm& operator=(AForm const &src);
        const std::string& getName() const;
        std::string getTarget();
        int getGradeToSign() const;
        int getGradeToExecute() const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& src);

#endif