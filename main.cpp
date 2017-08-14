#define PICOCOLOR_IMPL
#include "picocolor.hpp"

#define TEST_STRING " + "

std::ostream& ShowVersion(std::ostream& os)
{
        os << "picocolor 0.0.1";
}

int main(int argc, char* argv[])
{
        std::cout << ShowVersion << std::endl;

        std::cout << fg(Black) << TEST_STRING;
        std::cout << fg(Red) << TEST_STRING;
        std::cout << fg(Green) << TEST_STRING;
        std::cout << fg(Yellow) << TEST_STRING;
        std::cout << fg(Blue) << TEST_STRING;
        std::cout << fg(Magenta) << TEST_STRING;
        std::cout << fg(Cyan) << TEST_STRING;
        std::cout << fg(White) << TEST_STRING;
        std::cout << fg(Reset) << std::endl;
        std::cout << bg(Black) << TEST_STRING;
        std::cout << bg(Red) << TEST_STRING;
        std::cout << bg(Green) << TEST_STRING;
        std::cout << bg(Yellow) << TEST_STRING;
        std::cout << bg(Blue) << TEST_STRING;
        std::cout << bg(Magenta) << TEST_STRING;
        std::cout << bg(Cyan) << TEST_STRING;
        std::cout << bg(White) << TEST_STRING;
        std::cout << bg(Reset) << std::endl;

        return 0;
}
