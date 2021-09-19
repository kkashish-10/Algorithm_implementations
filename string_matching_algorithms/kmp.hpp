/**
 * @file kmp.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief Knuth-Morris-Pratt String matching algorithm
 * @version 0.1 (Simple implementations using LPS)
 * @date 2021-09-08
 * 
 * Time complexity : O(n+m) 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>

// time complexity O(n)
std::vector<std::size_t> generateLPSarray(const std::string &pattern_str)
{
    std::vector<std::size_t> lps_array(pattern_str.size());
    lps_array[0] = 0;
    //length of previous longest proper prefix that is also a suffix
    std::size_t score = 0;
    for (std::size_t i = 1; i < pattern_str.size();)
    {
        //if pattern matches at current indices
        if (pattern_str[i] == pattern_str[score])
            lps_array[i++] = ++score;
        // if pattern does not match at current indices
        else
        {
            //if score of previous lps is not zero
            if (score != 0)
                score = lps_array[score - 1];
            // if (score == 0)
            else
                lps_array[i++] = 0;
        }
    }
    return lps_array;
}

/**
 * @brief function to perform string matching using KMP algorithm
 * Time complexity [O(m+n)]
 * Worst time complexity of KMP algorithm is O(m+n).
 * O(m) time is taken for lps table creation.
 * Once this prefix suffix table is created, actual search complexity is O(n).
 * 
 * @param test_str [test string of size 'n']
 * @param pattern_str [pattern string to be searched for, of size'm']
 * @return std::size_t [index in test string, where pattern string's first character was found]
 */
std::size_t KMP(const std::string &test_str, const std::string &pattern_str)
{
    std::size_t h_size = test_str.size();
    std::size_t n_size = pattern_str.size();
    //if pattern to be matched is null string 
    if (n_size == 0)
        return 0;
    //generate lps table 
    std::vector<std::size_t> lps_array = generateLPSarray(pattern_str);
    for (std::size_t i = 0, j = 0; i < h_size;)
    {
        //if character matches continue matching
        if (test_str[i] == pattern_str[j])
            i++, j++;
        //whole of the pattern string was matched return i-j
        if (j == n_size)
            return i - j;
        //if characters don't match
        if (i < h_size && test_str[i] != pattern_str[j])
            j != 0 ? j = lps_array[j - 1] : i++;
    }
    return -1;
}

