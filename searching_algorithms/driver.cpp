/**
 * @file drive.cpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief driver function for searching algorithns
 * @version 0.1
 * @date 2021-09-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// #include "linear_search.hpp"
#include "binary_search.hpp"
#include <iostream>
int main()
{
    std::vector<int> ar = {1, 2, 4, 6, 8, 16, 20, 45, 88};
    // std::cout<<"\n Target found at index : "<<linear_search(ar,5);
    std::cout << "\n Target found at index : " << binary_search(ar, 0, ar.size() - 1, 6);
}