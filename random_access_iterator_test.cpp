/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:08:18 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 15:31:20 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random_access_iterator.hpp"

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

void test_random_access_iterator(void) {
    std::cout << "Test: random_access_iterator" << std::endl;

    std::vector< int > myvector;
    for (int i = 0; i < 10; i++) myvector.push_back(i);

    typedef std::vector< int >::iterator iter_type;
    iter_type from(myvector.begin());
    iter_type until(myvector.end());

    ft::random_access_iterator< int > ft_from(from.base());
    ft::random_access_iterator< int > ft_until(until.base());

    iter_type std_from(from);
    iter_type std_until(until);

    assert((ft_from < ft_until) == (std_from < std_until));
    std::cout << "\t (ft_from < ft_until) == (std_from < std_until)" << std::endl;

    assert((ft_from <= ft_until) == (std_from <= std_until));
    std::cout << "\t (ft_from <= ft_until) == (std_from <= std_until)"
                << std::endl;

    assert((ft_from > ft_until) == (std_from > std_until));
    std::cout << "\t (ft_from > ft_until) == (std_from > std_until)" << std::endl;

    assert((ft_from >= ft_until) == (std_from >= std_until));
    std::cout << "\t (ft_from >= ft_until) == (std_from >= std_until)"
                << std::endl;

    assert(*ft_from == *std_from);
    std::cout << "\t *ft_from == *std_from" << std::endl;
    assert(*(ft_until - 1) == *(std_until - 1));
    std::cout << "\t *ft_until == *std_until" << std::endl;

    assert(*(ft_from + 5) == *(std_from + 5));
    std::cout << "\t *(ft_from + 5) == *(std_from + 5)" << std::endl;

    assert(*(ft_until - 5) == *(std_until - 5));
    std::cout << "\t *(ft_from - 5) == *(std_from - 5)" << std::endl;

    assert(*(5 + ft_from) == *(5 + std_from));
    std::cout << "\t *(5 + ft_from) == *(5 + std_from)" << std::endl;

    assert((ft_until - ft_from) == (std_until - std_from));
    std::cout << "\t (ft_until - ft_from) == (std_until - std_from)" << std::endl;

    assert(ft_from[5] == std_from[5]);
    std::cout << "\t ft_from[5] == std_from[5]" << std::endl;

    while (ft_from != ft_until && std_from != std_until) {
        assert(std_from.base() == ft_from.base());
        ++ft_from;
        ++std_from;
    }
    std::cout << "\t while (ft_from != ft_until && std_from != "
                "std_until) ++rev_from;"
                << std::endl;

    ft_from = from.base();
    std_from = until;

    while (ft_from != ft_until && std_from != std_until) {
        assert(std_until.base() == ft_until.base());
        --ft_until;
        --std_until;
    }
    std::cout << "\t while (ft_from != ft_until && std_from != "
                "std_until) --rev_until;"
                << std::endl;
}
