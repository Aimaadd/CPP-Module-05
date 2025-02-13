#include "../includes/Intern.hpp"

AForm Intern::makeForm(std::string formName, std::string target) {
    AForm form;
    if (formName == "robotomy request") {
        form = RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        form = PresidentialPardonForm(target);
    } else if (formName == "shrubbery creation") {
        form = ShrubberyCreationForm(target);
    } else {
        throw Intern::FormNotFoundException();
    }
    return form;
}