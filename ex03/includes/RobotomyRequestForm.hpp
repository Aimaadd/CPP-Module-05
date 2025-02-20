#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        mutable bool _robotomized;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        bool execute(Bureaucrat &executor) const;
        bool getRobo();
        void Robotomize(Bureaucrat &Bureaucrat) const;
        RobotomyRequestForm& operator=(RobotomyRequestForm const &src);
};

#endif