/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:09:49 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 15:11:29 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool mycomp(char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }

void test_lexicographical_compare(void) {
    std::cout << "\t lexicographical_compare" << std::endl;

    char foo[] = "Apple";
    char bar[] = "apartment";

    assert(std::lexicographical_compare(foo, foo + 5, bar, bar + 9) ==
            ft::lexicographical_compare(foo, foo + 5, bar, bar + 9));

    assert(std::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp) ==
            ft::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp));
}

bool mypredicate(int i, int j) { return (i == j); }

void test_equal(void) {
    std::cout << "\t equal" << std::endl;

    int myints[] = {20, 40, 60, 80, 100};
    std::vector< int > myvector(myints, myints + 5);

    assert(std::equal(myvector.begin(), myvector.end(), myints) ==
            ft::equal(myvector.begin(), myvector.end(), myints));
    myvector[3] = 81;

    assert(std::equal(myvector.begin(), myvector.end(), myints, mypredicate) ==
            ft::equal(myvector.begin(), myvector.end(), myints, mypredicate));
}

void test_algorithm(void) {
    std::cout << "Test: algorithm" << std::endl;
    test_equal();
    test_lexicographical_compare();
}
