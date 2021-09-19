/**
 * @file linear_search.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>
#include <vector>

/**
 * @brief routine to search a target element linearly
 * 
 * @tparam T works for data of all data types
 * @param ar 
 * @param target element to be found 
 * @return int  -1 if not found elese index of target in ar
 */
template<typename T>
int linear_search(const std::vector<T> &ar,const T &target)
{
    int size_ar=ar.size();
    for(int i=0;i<size_ar;i++)
        if(ar[i]==target) return i;
    return -1;
}