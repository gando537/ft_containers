/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:05:04 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 13:51:34 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALGORYTHME_HPP_
#define _ALGORYTHME_HPP_

namespace ft {
    /*
    test si les éléments entre deux intervalles sont égales
    Compare les éléments de l'intervalle [first1,last1) avec ceux de l'intervalle
    commençant par first2, et renvoie true si tous les éléments des deux intervalles
    coincident
    */

    template < class InputIterator1, class InputIterator2 >
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
        for (; first1 != last1; ++first1, (void)++first2)
            if (!(*first1 == *first2))
                return false;
        return true;
    }

    /*
    test si les éléments entre deux intervalles sont égales
    Compare les éléments de l'intervalle [first1,last1) avec ceux de l'intervalle
    commençant par first2, et renvoie true si tous les éléments des deux intervalles
    coincident

    @param pred est une Fonction binaire qui accepte deux éléments en argument (l'un
    chacune des deux séquences, dans le même ordre), et retourne une valeur
    convertible en booléen. La valeur retournée indique si les éléments sont
    considérés comme correspondant dans le cadre de cette fonction. La fonction ne doit pas
    modifier n'importe lequel de ses arguments. Il peut s'agir soit d'un pointeur de fonction, soit d'un
    objet de fonction.
    */

    template < class InputIterator1, class InputIterator2, class BinaryPredicate >
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
            BinaryPredicate pred) {
        for (; first1 != last1; ++first1, (void)++first2)
            if (!bool(pred(*first1, *first2)))
                return false;
        return true;
    }

    /* Renvoie true si l'intervalle [first1,last1] est inférieur à, lexicographiquement,
    l'intervalle [first2, last2].

    @param first1, les itérateurs aux positions initiale et finale de la première
    séquence. L'intervalle utilisée est [first1,last1), qui contient tous les éléments
    entre first1 et last1, y compris l'élément pointé par first1 mais pas le
    élément pointé par last1.
    @param first2, les Itérateurs d'entrée aux positions initiale et finale de la
    deuxième séquence. La plage utilisée est [first2,last2).
    */

    template < class InputIterator1, class InputIterator2 >
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2) {
        while (first1 != last1) {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    /* Renvoie true si l'intervalle [first1,last1] est inférieur à, lexicographiquement,
    l'intervalle [first2, last2].

    @param first1, les itérateurs aux positions initiale et finale de la première
    séquence. L'intervalle utilisée est [first1,last1), qui contient tous les éléments
    entre first1 et last1, y compris l'élément pointé par first1 mais pas le
    élément pointé par last1.
    @param first2, les Itérateurs d'entrée aux positions initiale et finale de la
    deuxième séquence. La plage utilisée est [first2,last2).

    @param comp est une Fonction binaire qui accepte deux arguments de types pointeurs, pointés
    par les itérateurs, et retourne une valeur convertible en bool. La valeur renvoyée
    indique si le premier argument est considéré comme précédant le second dans
    l'ordre faible strict spécifique qu'il définit. La fonction ne doit pas modifier
    n'importe lequel de ses arguments. Il peut s'agir soit d'un pointeur de fonction, soit d'une fonction
    objet.
    */

    template < class InputIterator1, class InputIterator2, class Compare >
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp) {
        while (first1 != last1) {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif
