/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:20:09 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 15:32:12 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "test.hpp"
#include "vector.hpp"

int main(void) {
    std::cout << "Test: ft_containers" << std::endl;

    // test_iterator_traits();
    // test_reverse_iterator();
    // test_algorithm();
    // test_utility();
    // test_random_access_iterator();

    test_vector();

    return 0;
}
