#include "kmp.hpp"

int main()
{
    std::string test_string("mississippi");
    std::string pattern("issippi");
    std::cout << std::endl;
    std::cout << "Pattern '" << pattern << " ' found starting from index " << KMP(test_string, pattern) << " in test string ' " << test_string << " ' " << std::endl;
    return 0;
}
