#include "../includes/Bureaucrat.hpp"

int main() {
    // ----- Exception tests -----
    try {
        Bureaucrat();
        Bureaucrat a("A", 1);
        Bureaucrat b("B", 150);
        Bureaucrat d("D", 151);
        Bureaucrat c("C", 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat a("A", 1);
        a.decrementGrade();
        a.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // ----- Basic tests -----
    // Bureaucrat a("A", 1);
    // std::cout << a << std::endl;
    // std::cout << a.getName() << std::endl;
    // std::cout << a.getGrade() << std::endl;
    // try {
    //     a.incrementGrade();
    // }
    // catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }
    return 0;
}