#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const &src);
        bool execute(Bureaucrat &executor) const;
    private:
        std::string _target;
};


#endif 