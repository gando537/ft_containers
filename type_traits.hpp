/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:36:41 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 13:54:35 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPE_TRAITS_HPP_
#define _TYPE_TRAITS_HPP_

namespace ft {

    /**
     * @brief Si B est vrai, std::enable_if a un type
     * typedef de membre public, égal à T ;
     * sinon, il n'y a pas de typedef de membre.
     */
    template < bool B, class T = void >
    struct enable_if {};

    template < class T >
    struct enable_if< true, T > {
        typedef T type;
    };

    struct true_type {
        static const bool value = true;
        typedef bool value_type;
        typedef true_type type;
    };

    struct false_type {
        static const bool value = false;
        typedef bool value_type;
        typedef false_type type;
    };

    /**
     * @brief Vérifie si T est un type intégral.
     * Fournit la valeur constante du membre qui est égale à true,
     * si T est le type bool, char, char8_ (depuis C++20), char16_t,
     * char32_t, wchar_t, short, int, long, long long ou toute
     * extension définie par l'implémentation des types entiers,
     * y compris les variantes signées, non signées et qualifiées cv.
     * Sinon, value est égal à false.
     *
     * @tparam T integral type
     */
    template < class T >
    struct is_integral : public false_type {};

    template <>
    struct is_integral< bool > : public true_type {};
    template <>
    struct is_integral< char > : public true_type {};
    template <>
    struct is_integral< char16_t > : public true_type {};
    template <>
    struct is_integral< char32_t > : public true_type {};
    template <>
    struct is_integral< wchar_t > : public true_type {};
    template <>
    struct is_integral< signed char > : public true_type {};
    template <>
    struct is_integral< short int > : public true_type {};
    template <>
    struct is_integral< int > : public true_type {};
    template <>
    struct is_integral< long int > : public true_type {};
    // template <>
    // struct is_integral< long long int > : public true_type {};
    template <>
    struct is_integral< unsigned char > : public true_type {};
    template <>
    struct is_integral< unsigned short int > : public true_type {};
    template <>
    struct is_integral< unsigned int > : public true_type {};
    template <>
    struct is_integral< unsigned long int > : public true_type {};
    // template <>
    // struct is_integral< unsigned long long int > : public true_type {};

}

#endif
