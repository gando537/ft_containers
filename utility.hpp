/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:59:27 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 11:31:45 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

namespace ft {

    /**
     * @brief Paire de valeurs
     * Cette classe couple un couple de valeurs, qui peuvent être de types différents (T1 et T2).
     * Les valeurs individuelles sont accessibles via ses membres publics d'abord et ensuite.
     * Les paires sont un cas particulier de tuple.
     * @tparam T1 Type de membre en premier, alias first_type.
     * @tparam T2 Type de membre en second, alias second_type.
     */
    template < class T1, class T2 >
    struct pair {
        public:
        /* TLe premier paramètre de modèle (T1) Type de membre en premier. */
        typedef T1 first_type;
        /* Le second paramètre de modèle (T1) Type de membre en second. */
        typedef T2 second_type;

        /* La première valeur de la paire */
        first_type first;
        /* La seconde valeur de la paire */
        second_type second;

        /* Construit un objet paire avec ses éléments initialisés en valeur. */
        pair() : first(), second(){};

        /**
         * L'objet est initialisé avec le contenu de l'objet pr pair.
         * Le membre correspondant de pr est passé au constructeur de chacun de ses membres.
         * @param pr Un autre objet paire.
         * Il peut s'agir d'un objet du même type que l'objet en
         * cours de construction ou d'un type de paire dont les types
         * d'éléments sont implicitement convertibles en ceux de la paire en cours de construction.
         */
        template < class U, class V >
        pair(const pair< U, V >& pr) : first(pr.first), second(pr.second){};


         /**
         * @brief Le membre premier est construit avec a et le membre second avec b.
         * @param a Un objet du type de premier, ou un autre type implicitement convertible en celui-ci.
         * @param b Un objet du type de second, ou un autre type implicitement convertible en celui-ci.
         * pair(const first_type& a, const second_type& b) : first(a), second(b){};
         */
        pair(const first_type& a, const second_type& b) : first(a), second(b){};

        /**
         * Affecte pr comme nouveau contenu pour l'objet paire.
         *
         * @param pr Un autre objet paire.
         */
        pair& operator=(const pair& pr) {
            first = pr.first;
            second = pr.second;

            return *this;
        };
    };

    template < class T1, class T2 >
    bool operator==(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template < class T1, class T2 >
    bool operator!=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return !(lhs == rhs);
    }

    template < class T1, class T2 >
    bool operator<(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return lhs.first < rhs.first ||
            (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template < class T1, class T2 >
    bool operator<=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return !(rhs < lhs);
    }

    template < class T1, class T2 >
    bool operator>(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return rhs < lhs;
    }

    template < class T1, class T2 >
    bool operator>=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
        return !(lhs < rhs);
    }

    /**
     * @brief Exchanges the values of a and b.
     */
    template < class T >
    void swap(T& a, T& b) {
        T c(a);
        a = b;
        b = c;
    }

    /**
     * @brief Construit un objet paire avec son premier élément
     * défini sur x et son deuxième élément défini sur y.
     * @param x Valeurs pour les membres premier et deuxième,
     * respectivement, de l'objet paire en cours de construction.
     * @param y Valeurs pour les membres premier et deuxième,
     * respectivement, de l'objet paire en cours de construction.
     */
    template < class T1, class T2 >
    pair< T1, T2 > make_pair(T1 x, T2 y) {
        return (pair< T1, T2 >(x, y));
    }

}

#endif
