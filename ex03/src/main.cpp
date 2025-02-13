#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main() {
    // ----- Exception tests -----
    std::cout << "-----Exception tests----" << std::endl;
    try {
        Bureaucrat a("A", 2);
 
        a.SignForm(forA);
        a.SignForm(forA); //should fail
        a.executeForm(forA);
        a.executeForm(forA); //should fail
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // ----- Basic tests -----
    std::cout << "\n -----Basic tests-----" << std::endl;
    Bureaucrat a("A", 1);
    ShrubberyCreationForm forA("file_for_A");
    forA.beSigned(a);
    return 0;
}