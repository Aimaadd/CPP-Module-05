#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
    // ----- Exception tests -----
    try {
        Bureaucrat a("A", 1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form forA("A", 1, 1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // ----- Basic tests -----
    Bureaucrat a("A", 1);
    Form forA("A", 1, 1);
    forA.beSigned(a);
    return 0;
}