/**
 * @file binary_search.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief routine to search for a target element using binary search
 * @version 0.1
 * @date 2021-09-19
 * 
 * @copyright Copyright (c) 2021
 * 
 * Time Complexity O(log(n))
 * Space complexity O(1)
 */
#include<vector>

template<typename T>
int binary_search(const std::vector<T> &ar,int l,int h,const int &target)
{ 
    int mid;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(ar[mid]==target) return mid;
        ar[mid]>target?h=mid-1:l=mid+1;
    }

    //if target is not in given vector
    return -1;
}