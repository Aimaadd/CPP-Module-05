#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main() {
    // ----- Exception tests -----
    std::cout << "-----Exception tests----" << std::endl;
    try {
        Bureaucrat a("A", 2);
        // ShrubberyCreationForm forA;
        Intern Interntest;
        std::cout << "intern is creating receive form\n";
        AForm *receive(Interntest.makeForm("shrubbery creation", "forA"));        
        // receive = Interntest.makeForm("robotomy request", "forA");
        a.SignForm(*receive);
        // a.SignForm(receive); //should fail
        std::cout << "bureaucrat a is executing the form created by the intern\n";
        a.executeForm(*receive);
        // a.executeForm(forA); //should fail
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // ----- Basic tests -----
    std::cout << "\n -----Basic tests-----" << std::endl;
    Bureaucrat a("A", 1);
    RobotomyRequestForm forA("file_for_A");
    forA.beSigned(a);
    forA.execute(a);
    return 0;
}