/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:12 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 13:50:41 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <iostream>
#include <cstddef>

namespace ft {

    /*
    Classe vide pour identifier la catégorie d'un itérateur
    en tant qu'itérateur d'entrée.
    */

    struct input_iterator_tag {};

    /*
    Classe vide pour identifier la catégorie d'un itérateur
    en tant qu'itérateur de sortie.
    */

    struct output_iterator_tag {};

    /*
    Classe vide pour identifier la catégorie d'un itérateur
    en tant qu'itérateur avant.
    */

    struct forward_iterator_tag : public input_iterator_tag {};

    /*
    Classe vide pour identifier la catégorie d'un itérateur
    en tant qu'itérateur birectionnel.
    */

    struct bidirectional_iterator_tag : public forward_iterator_tag {};

    /*
    Classe vide pour identifier la catégorie d'un itérateur
    en tant qu'itérateur d'accés aléatoire.
    */

    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    /*
    std::iterator est la classe de base fournie pour simplifier les définitions de
    types requis pour les itérateurs.

    @tparam _Category, c'est la catégorie de l'itérateur. Doit être l'un des itérateurs
    balises de catégorie.
    @tparam _T c'est le type des valeurs que l'on peut obtenir en déréférencant l'itérateur.
    Ce type doit être vide pour les itérateurs de sortie.
    @tparam _Distance c'est un type qui peut être utilisé pour identifier la distance entre les itérateurs
    @tparam _Pointer définit un pointeur vers le type itéré sur (_T)
    @tparam _Reference définit une référence au type itéré sur (_T)
    */

    template < class Category, class T, class Distance = std::ptrdiff_t,
            class Pointer = T*, class Reference = T& >
    struct iterator {
        //c'est la catégorie de l'itérateur
        typedef Category iterator_category;

        //le type des valeurs que l'on peut obtenir en déréférencant l'itérateur
        typedef T value_type;

        //type utilisé pour identifier la distance entre les itérateurs
        typedef Distance difference_type;

        //définit un pointeur vers le type itéré (value_type)
        typedef Pointer pointer;

        //définit une référence au type itéré (value_type)
        typedef Reference reference;
    };

    /*
    Classe de traits définissant les propriétés des itérateurs.
    Les algorithmes standard déterminent certaines propriétés
    des itérateurs qui leur sont passés et l'intervalle qu'ils
    représentent en utilisant les membres du correspondant
    instanciation iterator_traits.

    @tparam Iterator ft:iterator
    */

    template < class Iterator >
    struct iterator_traits {

        //la catégorie de l'itérateur
        typedef typename Iterator::iterator_category iterator_category;

        //le type des valeurs que l'on peut obtenir en déréférencant l'itérateur
        typedef typename Iterator::value_type value_type;

        //type utilisé pour identifier la distance entre les itérateurs
        typedef typename Iterator::difference_type difference_type;

        //définit un pointeur vers le type itéré (value_type)
        typedef typename Iterator::pointer pointer;

        //définit une référence au type itéré (value_type)
        typedef typename Iterator::reference reference;
    };

    /*
    Classe de traits définissant les propriétés des itérateurs.
    Les algorithmes standard déterminent certaines propriétés
    des itérateurs qui leur sont passés et l'intervalle qu'ils
    représentent en utilisant les membres du correspondant
    instanciation iterator_traits.

    @tparam T value_type
    */

    template < class T >
    struct iterator_traits< T* > {
        //c'est la catégorie de l'itérateur
        typedef random_access_iterator_tag iterator_category;

        //le type des valeurs que l'on peut obtenir en déréférencant l'itérateur
        typedef T value_type;

        //type utilisé pour identifier la distance entre les itérateurs
        typedef ptrdiff_t difference_type;

        //définit un pointeur vers le type itéré (value_type)
        typedef T * pointer;

        //définit une référence au type itéré (value_type)
        typedef T & reference;
    };

    /*
    Classe de traits définissant les propriétés des itérateurs.
    Les algorithmes standard déterminent certaines propriétés
    des itérateurs qui leur sont passés et l'intervalle qu'ils
    représentent en utilisant les membres du correspondant
    instanciation iterator_traits.

    @tparam T ft:iterator
    */

    template < class T >
    struct iterator_traits< T* const > {
        //c'est la catégorie de l'itérateur
        typedef random_access_iterator_tag iterator_category;

        //le type des valeurs que l'on peut obtenir en déréférencant l'itérateur
        typedef T value_type;

        //type utilisé pour identifier la distance entre les itérateurs
        typedef ptrdiff_t difference_type;

        //définit un pointeur vers le type itéré (value_type)
        typedef const T * pointer;

        //définit une référence au type itéré (value_type)
        typedef const T & reference;
    };

    /*
    Cette classe inverse le sens dans lequel un itérateur
    bidirectionnel à accès aléatoire parcourt une intervalle

    @tparam Iterator Iterator Class
    */

    template < class Iterator >
    class reverse_iterator {
        public:
            // type d'itérateur
            typedef Iterator iterator_type;

            // Conserve la catégorie de l'itérateur
            typedef typename iterator_traits< Iterator >::iterator_category iterator_category;

            // Conserve le type de la valeur de l'itérateur
            typedef typename iterator_traits< Iterator >::value_type value_type;

            // Préserve le type de différence d'Iterator
            typedef typename iterator_traits< Iterator >::difference_type difference_type;

            // Préserve le type de pointeur de l'Iterator
            typedef typename iterator_traits< Iterator >::pointer pointer;

            // Préserve le type de référence de l'Iterator
            typedef typename iterator_traits< Iterator >::reference reference;

        protected:
            iterator_type current;

        public:
            /*
            @Constructeur par défaut

            Construit un itérateur inverse qui ne pointe sur aucun objet.
            L'itérateur de base interne est initialisé en valeur.
            */
            reverse_iterator() : current(){};

            /*
            constructeur d'initialisation
            Construit un itérateur inverse à partir d'un itérateur d'origine.
            Le comportement de l'objet construit réplique l'original, sauf qu'il itère
            à travers ses éléments pointés dans l'ordre inverse.
            @param it Un itérateur, dont le sens d'itération est inversé dans l'objet construit.
            Le type de membre iterator_type est le type d'itérateur bidirectionnel
            sous-jacent (le paramètre de modèle de classe : Iterator).
            */
            explicit reverse_iterator(iterator_type it) : current(it){};

            /*
            Construit un itérateur inverse à partir d'un autre itérateur inverse. le
            l'objet construit garde le même sens d'itération que rev_it.

            @param rev_it Un itérateur de type reverse_iterator, dont le sens de
            l'itération est conservée.
            */
            template < class Iter >
            reverse_iterator(const reverse_iterator< Iter >& rev_it) : current(rev_it.base()){};

            virtual ~reverse_iterator(){};

            /**
             * @brief Renvoie une copie de l'itérateur de base.
             */
            iterator_type base() const { return current; };

            /**
             * @brief Renvoie une copie de l'itérateur de base.
             */
            operator reverse_iterator< const Iterator >() const { return this->current; }

            /**
             * @brief Renvoie une référence de l'élément pointé par l'itérateur
             */
            reference operator*() const {
                iterator_type tmp_iter = current;
                return *(--tmp_iter);
            };

            /**
             * @brief Renvoie un itérateur inverse pointant vers l'élément situé à n
             * positions de l'élément vers lequel pointe actuellement l'itérateur.
             */
            reverse_iterator operator+(difference_type n) const {
                return reverse_iterator(current - n);
            };

            /**
             * @brief Avance le reverse_iterator d'une position
             * @example ++ri;
             */
            reverse_iterator & operator++() {
                --current;
                return *this;
            };

            /**
             * @brief Avance le reverse_iterator d'une position
             * @example ri++;
             */
            reverse_iterator operator++(int) {
                reverse_iterator tmp = *this;
                --current;
                return tmp;
            };

            /**
             * @brief Avance le reverse_iterator de n positions
             */
            reverse_iterator& operator+=(difference_type n) {
                current -= n;
                return *this;
            };

            /**
             * @brief Renvoie un itérateur inverse pointant vers l'élément
             * situé à n positions avant l'élément vers lequel l'itérateur
             * pointe actuellement.
             */

            reverse_iterator operator-(difference_type n) const {
                return reverse_iterator(current + n);
            };

            /**
             * @brief Recule le reverse_iterator d'une position
             * @example --ri;
             */
            reverse_iterator & operator--() {
                ++current;
                return *this;
            };

            /**
             * @brief Recule le reverse_iterator d'une position
             * @example ri++;
             */
            reverse_iterator operator--(int) {
                reverse_iterator tmp = *this;
                ++current;
                return tmp;
            };

            /**
             * @brief Avance le reverse_iterator de n positions.
             */
            reverse_iterator & operator-=(difference_type n) {
                current += n;
                return *this;
            };

            /**
             * @brief Renvoie un pointeur sur l'élément pointé par
             * l'itérateur (afin d'accéder à l'un de ses membres).
             */
            pointer operator->() const { return &(operator*()); };

            /**
             * @brief Accède à l'élément situé à n positions de
             * l'élément actuellement pointé par l'itérateur.
             */
            reference operator[](difference_type n) const { return (current[-n - 1]); };
    };

    /**
     * @brief Opérateurs relationnels == pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator==(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() == rhs.base());
    }

    /**
     * @brief Opérateurs relationnels != pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator!=(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() != rhs.base());
    }

    /**
     * @brief Opérateurs relationnels < pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator<(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() > rhs.base());
    }

    /**
     * @brief Opérateurs relationnels <= pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator<=(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() >= rhs.base());
    }

    /**
     * @brief Opérateurs relationnels > pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator>(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() < rhs.base());
    }

    /**
     * @brief Opérateurs relationnels >= pour reverse_iterator
     */
    template < class Iterator1, class Iterator2 >
    bool operator>=(const reverse_iterator< Iterator1 >& lhs,
                    const reverse_iterator< Iterator2 >& rhs) {
        return (lhs.base() <= rhs.base());
    }

    /**
     * @brief Renvoie un itérateur inverse pointant vers
     * l'élément situé à n positions de l'élément pointé par rev_it.
     *
     * @param n Nombre d'éléments à décaler. Le type de membre
     * difference_type est un alias du propre type de différence d'Iterator.
     * @param rev_it Itérateur inverse.
     */
    template < class Iterator >
    reverse_iterator< Iterator > operator+(
        typename reverse_iterator< Iterator >::difference_type n,
        const reverse_iterator< Iterator >& rev_it) {
        return rev_it + n;
    }

    /**
     * @brief Renvoie la distance entre lhs et rhs.
     */
    template < class Iterator1, class Iterator2 >
    typename reverse_iterator< Iterator1 >::difference_type operator-(
        const reverse_iterator< Iterator1 >& lhs,
        const reverse_iterator< Iterator2 >& rhs) {
        return rhs.base() - lhs.base();
    }
}

#endif
