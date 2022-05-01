/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:15:16 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 13:51:14 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RANDOM_ACCESS_ITERATOR_HPP_
#define _RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "util.hpp"

namespace ft {

    template < class T >
    class random_access_iterator
        : public ft::iterator< ft::random_access_iterator_tag, T > {
        public:
            /* Préserve les catégories d'itérateurs */
            typedef typename ft::iterator< ft::random_access_iterator_tag,
                                            T >::iterator_category iterator_category;
            /* Préserve le type de valeur d'Iterator  **/
            typedef typename ft::iterator< ft::random_access_iterator_tag, T >::value_type
                value_type;
            /* Préserve la différence d'Iterator *type */
            typedef typename ft::iterator< ft::random_access_iterator_tag,
                                            T >::difference_type difference_type;
            /* Préserve le type de pointeur de l'itérateur *e */
            typedef typename ft::iterator< ft::random_access_iterator_tag, T >::pointer
                pointer;
            /* Préserve le type de référence de l'itérateur */
            typedef typename ft::iterator< ft::random_access_iterator_tag, T >::reference
                reference;

        protected:
            pointer _ptr;

        public:
            /**
             * @brief constructeur par défaut
             */
            random_access_iterator(pointer _ptr = ft::u_nullptr) : _ptr(_ptr){};

            /**
             * @brief copy / type-cast constructeur
             */
            random_access_iterator(const random_access_iterator< T >& other)
                : _ptr(other._ptr){};

            /**
             * @brief random_access_iterator< const T > casting operator
             *
             * @return random_access_iterator< const T >
             */
            operator random_access_iterator< const T >() const { return this->_ptr; }

            /**
             * @brief Avance le random_access_iterator d'une position.
             * @example ++_ptr;
             */
            random_access_iterator& operator++() {
                ++_ptr;
                return *this;
            };

            /**
             * @brief Avance le random_access_iterator d'une position.
             * @example _ptr++;
             */
            random_access_iterator operator++(int) {
                random_access_iterator tmp = *this;
                ++(*this);
                return tmp;
            };

            /**
             * @brief Renvoie une référence pointé par l'itérateur.
             */
            reference operator*() const { return *_ptr; };

            /**
             * @brief Renvoie un pointeur sur l'adresse pointée par l'itérateur
             *  (afin d'accéder à l'un de ses membres).
             */
            pointer operator->() const { return &(operator*()); };

            /**
             * @brief Décrémente le random_access_iterator d'une position.
             * @example --_ptr;
             */
            random_access_iterator& operator--() {
                --_ptr;
                return *this;
            };

            /**
             * @brief Décrémente le random_access_iterator d'une position.
             * @example _ptr--;
             */
            random_access_iterator operator--(int) {
                random_access_iterator tmp = *this;
                --(*this);
                return tmp;
            };

            /**
             * @brief Renvoie un itérateur pointant vers le _ptrent situé
             * à n positions du _ptrent vers lequel pointe l'itérateur _ptrly.
             */
            random_access_iterator operator+(difference_type n) const {
                return random_access_iterator(this->_ptr + n);
            };

            /**
             * @brief Avance le random_access_iterator de n _ptrent positions.
             */
            random_access_iterator& operator+=(difference_type n) {
                this->_ptr += n;
                return *this;
            };

            /**
             * @brief Renvoie un itérateur pointant vers le _ptrent situé n positions
             * avant le _ptrent vers lequel pointe l'itérateur _ptrly.
             */
            random_access_iterator operator-(difference_type n) const {
                return random_access_iterator(this->_ptr - n);
            }

            /**
             * @brief diminue le random_access_iterator de n _ptrent positions.
             */
            random_access_iterator& operator-=(difference_type n) {
                this->_ptr -= n;
                return *this;
            };

            /**
             * @brief Accède au _ptrent situé à n positions du _ptrent
             * _ptrly pointé par l'itérateur.
             */
            reference operator[](difference_type n) const { return (this->_ptr[n]); };

            /**
             * @brief obtenir la base _ptr
             *
             * @return pointer const&
             */
            pointer const& base() const { return this->_ptr; }
    };

    /**
     * @brief Opérateurs relationnels == pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator==(const random_access_iterator< T1 >& lhs,
                    const random_access_iterator< T2 >& rhs) {
        return (lhs.base() == rhs.base());
    }

    /**
     * @brief Opérateurs relationnels != pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator!=(const random_access_iterator< T1 >& lhs,
                    const random_access_iterator< T2 >& rhs) {
        return (lhs.base() != rhs.base());
    }

    /**
     * @brief Opérateurs relationnels < pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator<(const random_access_iterator< T1 > lhs,
                const random_access_iterator< T2 >& rhs) {
        return (lhs.base() < rhs.base());
    }

    /**
     * @brief Opérateurs relationnels <= pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator<=(const random_access_iterator< T1 >& lhs,
                    const random_access_iterator< T2 >& rhs) {
        return (lhs.base() <= rhs.base());
    }

    /**
     * @brief Opérateurs relationnels > pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator>(const random_access_iterator< T1 > lhs,
                const random_access_iterator< T2 >& rhs) {
        return (lhs.base() > rhs.base());
    }

    /**
     * @brief Opérateurs relationnels >= pour random_access_iterator
     */
    template < class T1, class T2 >
    bool operator>=(const random_access_iterator< T1 >& lhs,
                    const random_access_iterator< T2 >& rhs) {
        return (lhs.base() >= rhs.base());
    }

    /**
     * @brief Renvoie un itérateur pointant vers le _ptrent situé
     *  à n positions du _ptrent pointé par iter.
     * @param n Nombre de _ptrents à décaler.
     * Le type de membre difference_type est un alias du propre
     * type de différence d'Iterator.
     * @param iter itérateur.
     */
    template < class Iterator >
    random_access_iterator< Iterator > operator+(
        typename random_access_iterator< Iterator >::difference_type n,
        const random_access_iterator< Iterator >& iter) {
            return iter + n;
    }

    /**
     * @brief Renvoie la distance entre lhs et rhs.
     */
    template < class T1, class T2 >
    typename random_access_iterator< T1 >::difference_type operator-(
        const random_access_iterator< T2 >& lhs,
        const random_access_iterator< T1 >& rhs) {
    return lhs.base() - rhs.base();
    }
}

#endif
