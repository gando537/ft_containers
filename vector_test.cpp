/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:19:07 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 15:32:54 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void test_vector(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};

    std::vector< int > std_default;
    std::vector< int > std_fill(5, 42);
    std::vector< int > std_range(arr, arr + (sizeof(arr) / sizeof(int)));
    std::vector< int > std_copy(std_range);

    ft::vector< int > ft_default;
    ft::vector< int > ft_fill(5, 42);
    ft::vector< int > ft_range(arr, arr + (sizeof(arr) / sizeof(int)));
    ft::vector< int > ft_copy(ft_range);

    assert(*std_range.begin() == *ft_range.begin());
    assert(*(std_range.end() - 1) == *(ft_range.end() - 1));
    assert(std_range.size() == ft_range.size());
    assert(std_range.max_size() == ft_range.max_size());

    assert(std_range[1] == ft_range[1]);
    assert(std_range.at(1) == ft_range.at(1));
    assert(std_range.front() == ft_range.front());
    assert(std_range.back() == ft_range.back());

    try {
        // ft_range.resize(ft_range.max_size() + 1);
        // throw "error";
    }
    catch (const std::length_error& e) {}
    catch (...) { assert(false); }

    ft_range.resize(3);
    std_range.resize(3);
    assert(std_range.size() == ft_range.size());
    assert(std_fill.capacity() == ft_fill.capacity());

    assert(ft_default.empty() == true);
    assert(ft_fill.empty() == false);

    ft_default.reserve(100);
    assert(ft_default.capacity() == 100);
}
