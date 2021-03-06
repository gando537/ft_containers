/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_test.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:07:32 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 15:25:01 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#include "iterator.hpp"

void test_reverse_iterator(void) {
    std::cout << "Test: reverse_iterator" << std::endl;

    std::vector< int > myvector;
    for (int i = 0; i < 10; i++) myvector.push_back(i);

    typedef std::vector< int >::iterator iter_type;
    iter_type from(myvector.begin());
    iter_type until(myvector.end());

    ft::reverse_iterator< iter_type > ft_rev_from(until);
    ft::reverse_iterator< iter_type > ft_rev_until(from);

    std::reverse_iterator< iter_type > std_rev_from(until);
    std::reverse_iterator< iter_type > std_rev_until(from);

    int arr[] = {1, 2, 3, 4};
    ft::reverse_iterator< int* > it_arr(arr + 4);
    ft::reverse_iterator< int* > it_copy(it_arr);
    (void)it_copy;

    assert((ft_rev_from < ft_rev_until) == (std_rev_from < std_rev_until));
    std::cout
        << "\t (ft_rev_from < ft_rev_until) == (std_rev_from < std_rev_until)"
        << std::endl;

    assert((ft_rev_from <= ft_rev_until) == (std_rev_from <= std_rev_until));
    std::cout
        << "\t (ft_rev_from <= ft_rev_until) == (std_rev_from <= std_rev_until)"
        << std::endl;

    assert((ft_rev_from > ft_rev_until) == (std_rev_from > std_rev_until));
    std::cout
        << "\t (ft_rev_from > ft_rev_until) == (std_rev_from > std_rev_until)"
        << std::endl;

    assert((ft_rev_from >= ft_rev_until) == (std_rev_from >= std_rev_until));
    std::cout
        << "\t (ft_rev_from >= ft_rev_until) == (std_rev_from >= std_rev_until)"
        << std::endl;

    assert(*ft_rev_from == *std_rev_from);
    std::cout << "\t *ft_rev_from == *std_rev_from" << std::endl;
    assert(*(ft_rev_until - 1) == *(std_rev_until - 1));
    std::cout << "\t *ft_rev_until == *std_rev_until" << std::endl;

    assert(*(ft_rev_from + 5) == *(std_rev_from + 5));
    std::cout << "\t *(ft_rev_from + 5) == *(std_rev_from + 5)" << std::endl;

    assert(*(ft_rev_until - 5) == *(std_rev_until - 5));
    std::cout << "\t *(ft_rev_from - 5) == *(std_rev_from - 5)" << std::endl;

    assert(*(5 + ft_rev_from) == *(5 + std_rev_from));
    std::cout << "\t *(5 + ft_rev_from) == *(5 + std_rev_from)" << std::endl;

    assert((ft_rev_until - ft_rev_from) == (std_rev_until - std_rev_from));
    std::cout
        << "\t (ft_rev_until - ft_rev_from) == (std_rev_until - std_rev_from)"
        << std::endl;

    assert(ft_rev_from[5] == std_rev_from[5]);
    std::cout << "\t ft_rev_from[5] == std_rev_from[5]" << std::endl;

    std::map< int, std::string > numbers;
    numbers.insert(std::make_pair(1, "one"));
    numbers.insert(std::make_pair(2, "two"));
    numbers.insert(std::make_pair(3, "three"));

    typedef std::map< int, std::string >::iterator map_iter;

    ft::reverse_iterator< map_iter > ft_rev_end(numbers.begin());
    ft::reverse_iterator< map_iter > ft_rev_iterator(numbers.end());

    std::reverse_iterator< map_iter > std_rev_end(numbers.begin());
    std::reverse_iterator< map_iter > std_rev_iterator(numbers.end());

    while ((ft_rev_iterator != ft_rev_end) && (std_rev_iterator != std_rev_end)) {
        assert((ft_rev_iterator->first == std_rev_iterator->first) &&
            (ft_rev_iterator->second == std_rev_iterator->second));
        ++ft_rev_iterator;
        ++std_rev_iterator;
    }
    std::cout << "\t ft_rev_iterator->* == std_rev_iterator->*" << std::endl;

    while (ft_rev_from != ft_rev_until && std_rev_from != std_rev_until) {
        assert(std_rev_from.base() == ft_rev_from.base());
        ++ft_rev_from;
        ++std_rev_from;
    }
    std::cout << "\t while (ft_rev_from != ft_rev_until && std_rev_from != "
                "std_rev_until) ++rev_from;"
                << std::endl;

    ft_rev_from = ft::reverse_iterator< iter_type >(until);
    std_rev_from = std::reverse_iterator< iter_type >(until);

    while (ft_rev_from != ft_rev_until && std_rev_from != std_rev_until) {
        assert(std_rev_until.base() == ft_rev_until.base());
        --ft_rev_until;
        --std_rev_until;
    }
    std::cout << "\t while (ft_rev_from != ft_rev_until && std_rev_from != "
                "std_rev_until) --rev_until;"
                << std::endl;
}
