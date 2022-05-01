/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:56:59 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/07 14:35:42 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
#define _BIDIRECTIONAL_ITERATOR_HPP_

#include "iterator.hpp"
#include "util.hpp"

namespace ft {

    template < class T >
    class bidirectional_iterator
        : public ft::iterator< ft::bidirectional_iterator_tag, T > {
        public:
            /* Préserve les catégories d'itérateurs */
            typedef typename ft::iterator< ft::bidirectional_iterator_tag,
                                            T >::iterator_category iterator_category;

            /* Préserve le type de valeur d'Iterator **/
            typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::value_type
                value_type;

            /* Préserve la différence d'Iterator *type */
            typedef typename ft::iterator< ft::bidirectional_iterator_tag,
                                            T >::difference_type difference_type;

            /* Préserve le type de pointeur de l'itérateur *e */
            typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::pointer
                pointer;

            /* Préserve le type de référence de l'itérateur */
            typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::reference
                reference;

        protected:
            pointer ptr;

        public:
            /**
             * @brief constructeur par défaut
             */
            bidirectional_iterator(pointer ptr = ft::u_nullptr) : ptr(ptr){};

            /**
             * @brief copy / type-cast constructeur
             */
            bidirectional_iterator(const bidirectional_iterator& other)
                : ptr(other.ptr){};

            template < typename diffT >
            bidirectional_iterator(const bidirectional_iterator< diffT >& other)
                : ptr(other.base()) {}

            /**
             * @brief Avance le bidirectional_iterator d'une position.
             * @example ++ptr;
             */
            bidirectional_iterator& operator++() {
                ++ptr;
                return *this;
            };

            /**
             * @brief Avance le bidirectional_iterator d'une position.
             * @example ptr++;
             */
            bidirectional_iterator operator++(int) {
                bidirectional_iterator tmp = *this;
                ++(*this);
                return tmp;
            };

            /**
             * @brief Opérateurs relationnels == pour bidirectional_iterator
             */
            bool operator==(const bidirectional_iterator< T >& other) {
                return (this->ptr == other.ptr);
            };

            /**
             * @brief Opérateurs relationnels != pour bidirectional_iterator
             */
            bool operator!=(const bidirectional_iterator< T >& other) {
                return (this->ptr != other.ptr);
            };

            /**
             * @brief Renvoie une référence pointé par l'itérateur bidirectionnel.
             */
            reference operator*() const { return *ptr; };

            /**
             * @brief Renvoie un pointeur sur l'adresse pointée par bidirectional_iterator
             *  (afin d'accéder à l'un de ses membres).
             */
            pointer operator->() const { return &(operator*()); };

            /**
             * @brief Décrémente le bidirectional_iterator d'une position.
             * @example --ptr;
             */
            bidirectional_iterator& operator--() {
                --ptr;
                return *this;
            };

            /**
             * @brief Décrémente le bidirectional_iterator d'une position.
             * @example ptr--;
             */
            bidirectional_iterator operator--(int) {
                bidirectional_iterator tmp = *this;
                --(*this);
                return tmp;
            };

            pointer const & base() const { return ptr; }
    };

}

#endif
