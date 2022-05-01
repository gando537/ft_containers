/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:52:08 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/07 14:57:11 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include "iterator.hpp"

namespace ft {

    struct nullptr_t {
    private:
    void operator&() const;

    public:
    template < class T >
    inline operator T*() const {
        return 0;
    }

    template < class C, class T >
    inline operator T C::*() const {
        return 0;
    }
};

static nullptr_t u_nullptr = {};

template < class InputIterator >
typename ft::iterator_traits< InputIterator >::difference_type difference(
    InputIterator first, InputIterator last) {
    typedef
        typename ft::iterator_traits< InputIterator >::difference_type size_type;
    size_type n = 0;
    for (; first != last; ++first) {
        ++n;
    }
    return n;
}

}

#endif
