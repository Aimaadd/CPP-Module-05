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
        PresidentialPardonForm forA;
        RobotomyRequestForm forB;
        ShrubberyCreationForm forC;
        // forA.beSigned(a);
        // forA.beSigned(a); //should fail
        // forA.execute(a);
        // forA.execute(a); //should fail
        a.SignForm(forC);
        a.SignForm(forC); //should fail
        a.executeForm(forC);
        a.executeForm(forC); //should fail
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