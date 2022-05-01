/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:31:39 by mdiallo           #+#    #+#             */
/*   Updated: 2022/03/14 14:35:37 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <memory>

#include "algorithm.hpp"
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "type_traits.hpp"
#include "util.hpp"

namespace ft {
    /**
     * @brief Un conteneur standard qui offre un accès à durée fixe
     * aux éléments individuels dans n'importe quel ordre.
     *
     * @tparam _T Type des éléments.
     * @tparam _Alloc Type de l'objet d'allocation utilisé pour définir
     * le modèle d'allocation de stockage, par défaut `allocator<_T>`.
     */
    template < class _T, class _Alloc = std::allocator< _T > >
    class vector {
        public:
            /**
             * @brief Le premier paramètre du template (_T)
             */
            typedef _T value_type;
            /**
             * @brief Le premier paramètre du template (_T)
             */
            typedef _T const const_value_type;
            /**
             * @brief Le deuxième paramètre du template (_Alloc),
             * par défaut à `_Alloc<value_type>`
             */
            typedef _Alloc allocator_type;
            /* allocator_type::reference, par défaut à `value_type&` */
            typedef typename allocator_type::reference reference;
            /* allocator_type::const_reference, par défaut à `const_value_type&` */
            typedef typename allocator_type::const_reference const_reference;
            /* allocator_type::pointeur, par défaut à ` type_valeur * ` */
            typedef typename allocator_type::pointer pointer;
            /* allocator_type::const_pointer, par défaut à `const value_type*` */
            typedef typename allocator_type::const_pointer const_pointer;

            /* un itérateur d'accès aléatoire à value_type */
            typedef typename ft::random_access_iterator< value_type > iterator;

            /* const_iterator, un itérateur d'accès aléatoire à const value_type */
            typedef typename ft::random_access_iterator< const_value_type >
                const_iterator;

            /* reverse_iterator<iterator>	*/
            typedef typename ft::reverse_iterator< iterator > reverse_iterator;

            /* reverse_iterator<const_iterator>	*/
            typedef typename ft::reverse_iterator< const_iterator >
                const_reverse_iterator;

            /* un type intégral signé, identique à :
            iterator_traits<iterator>::difference_type	 */
            typedef
                typename ft::iterator_traits< iterator >::difference_type difference_type;

            /*  un type intégral non signé qui peut représenter n'importe
            quelle valeur non négative de type_différence */
            typedef typename allocator_type::size_type size_type;

        private:
            allocator_type _alloc;
            pointer _start;
            pointer _end;
            pointer _end_capacity;

        public:
            /**
             * @brief constructeur de conteneur vide (constructeur par défaut)
             * Construit un conteneur vide, sans éléments.
             */
            explicit vector(const allocator_type& alloc = allocator_type())
                : _alloc(alloc),
                    _start(u_nullptr),
                    _end(u_nullptr),
                    _end_capacity(u_nullptr){};

            /**
             * @brief constructeur de remplissage
             * Construit un conteneur avec n éléments. Chaque élément est une copie de val.
             *
             * @param n Taille initiale du conteneur (c'est-à-dire
             * le nombre d'éléments dans le conteneur à la construction).
             * @param val Valeur avec laquelle remplir le conteneur.
             * Chacun des n éléments du conteneur sera initialisé
             * avec une copie de cette valeur. Le type de membre value_type
             * est le type des éléments dans le conteneur, défini dans le vecteur
             * comme alias de son premier paramètre de modèle (T).
             */
            explicit vector(size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type())
                : _alloc(alloc) {
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_end_capacity = this->_start + n;
                while (n--) this->_alloc.construct(this->_end++, val);
            };

            /**
             * @brief constructeur d'intervalle
             * Construit un conteneur avec autant d'éléments que l'intervalle [first, last),
             * avec chaque élément construit à partir de son élément correspondant
             * dans cette intervalle, dans le même ordre.
             */
            template < class InputIterator >
            vector(InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<
                        !ft::is_integral< InputIterator >::value >::type* = u_nullptr)
                : _alloc(alloc) {
                size_type n = ft::difference(first, last);
                this->_start = this->_alloc.allocate(n);
                this->_end_capacity = this->_start + n;
                this->_end = this->_start;
                while (n--) this->_alloc.construct(this->_end++, *first++);
            };

            /**
             * @brief constructeur par copie
             * Construit un conteneur avec une copie
             * de chacun des éléments de x, dans le même ordre.
             */
            vector(const vector& x) : _alloc(x._alloc) {
                size_type n = x.size();
                this->_start = this->_alloc.allocate(n);
                this->_end_capacity = this->_start + n;
                this->_end = this->_start;

                pointer other = x._start;
                while (n--) this->_alloc.construct(this->_end++, *other++);
            };

            vector& operator=(const vector& x) {
                if (this != &x) {
                    this->clear();
                    this->insert(this->_start, x.begin(), x.end());
                }
                return *this;
            };

            /**
             * @brief Destructeur de vecteur
             * Détruit l'objet conteneur.
             */
            ~vector() {
                this->clear();
                this->_alloc.deallocate(this->_start, this->capacity());
            };

            /**
             * @brief Retourne l'itérateur au début
             * Renvoie un itérateur pointant vers le premier élément du vecteur.
             */
            iterator begin() { return (this->_start); };

            /**
             * @brief Retourne l'itérateur au début
             * Renvoie un itérateur pointant vers le premier élément du vecteur.
             */
            const_iterator begin() const { return (this->_start); };

            /**
             * @brief Retourne un reverse itérateur au début
             * Renvoie un itérateur inverse pointant vers le dernier
             * élément du vecteur (c'est-à-dire son début inverse).
             */
            reverse_iterator rbegin() { return reverse_iterator(iterator(this->_end)); };

            /**
             * @brief Retourne un reverse itérateur au début
             * Renvoie un itérateur inverse pointant vers le dernier
             * élément du vecteur (c'est-à-dire son début inverse).
             */
            const_reverse_iterator rbegin() const { return (this->_end); };

            /**
             * @brief Renvoie l'itérateur à la fin
             * Renvoie un itérateur faisant référence à l'élément
             * après la fin dans le vecteur conteneur.
             */
            iterator end() { return (this->_end); }
            /**
             * @brief Retourner l'itérateur à la fin
             * Retourne un itérateur faisant référence à l'élément
             * après la fin dans le conteneur du vecteur.
             */
            const_iterator end() const { return (this->_end); }

            /**
             * @brief Renvoie l'itérateur inverse à l'extrémité inverse
             * Renvoie un itérateur inverse pointant vers le dernier
             * élément du vecteur (c'est-à-dire son extrémité inverse).
             */
            reverse_iterator rend() { return reverse_iterator(this->_start); };

            /**
             * @brief Renvoie l'itérateur inverse à l'extrémité inverse
             * Renvoie un itérateur inverse pointant vers le dernier
             * élément du vecteur (c'est-à-dire son extrémité inverse).
             */
            const_reverse_iterator rend() const { return (this->_start); };

            /**
             * @brief Taille de retour
             * Renvoie le nombre d'éléments dans le vecteu
             */
            size_type size() const { return (this->_end - this->_start); };

            /**
             * @brief Renvoyer la taille maximale
             * Renvoie le nombre maximum d'éléments que le vecteur peut contenir.
             */
            size_type max_size() const { return (this->_alloc.max_size()); };

            /**
             * @brief Changer la taille
             * Redimensionne le conteneur afin qu'il contienne n éléments.
             *
             * @param n Nouvelle taille du conteneur, exprimée en nombre d'éléments.
             * Le type de membre size_type est un type intégral non signé.
             * @param val Objet dont le contenu est copié dans les éléments ajoutés au cas où
             * n est supérieur à la taille actuelle du conteneur. S'il n'est pas spécifié,
             * le constructeur par défaut est utilisé à la place.
             */
            void resize(size_type n, value_type val = value_type()) {
                if (n > this->max_size()) {
                    throw std::out_of_range("ft::vector");
                }
                size_type prev_size = this->size();
                if (prev_size > n) {
                    while (prev_size-- > n) {
                        this->_alloc.destroy(--this->_end);
                    }
                    return;
                }
                this->insert(this->_end, n - prev_size, val);
            };

            /**
             * @brief Taille de retour de la capacité de stockage allouée
             * Renvoie la taille de l'espace de stockage actuellement
             * alloué au vecteur, exprimée en termes d'éléments.
             */
            size_type capacity() const { return (this->_end_capacity - this->_start); };

            /**
             * @brief Tester si le vecteur est vide
             * Renvoie 1 si le vecteur est vide (c'est-à-dire si sa taille est 0).
             */
            bool empty() const { return (this->size() == 0); };

            /**
             * @brief Demande un changement de capacité
             * Demande que la capacité du vecteur soit
             * au moins suffisante pour contenir n éléments.
             *
             * @param n Capacité minimale pour le vecteur.
             */
            void reserve(size_type n) {
                if (n > this->max_size()) {
                    throw std::out_of_range("ft::vector");
                }

                if (this->capacity() >= n) {
                    return;
                }

                pointer prev_start = this->_start;
                pointer prev_end = this->_end;
                size_type prev_capacity = this->capacity();

                this->_start = this->_alloc.allocate(n);
                this->_end_capacity = this->_start + n;
                this->_end = this->_start;

                for (pointer target = prev_start; target != prev_end; ++target) {
                    this->_alloc.construct(this->_end++, *target);
                }
                for (size_type len = prev_end - prev_start; len > 0; --len) {
                    this->_alloc.destroy(--prev_end);
                }
                this->_alloc.deallocate(prev_start, prev_capacity);
            };

            /**
             * @brief Élément d'accès
             * Renvoie une référence à l'élément à la position n dans le conteneur vectoriel
             */
            reference operator[](size_type n) { return (this->_start[n]); };

            /**
             * @brief Élément d'accès
             * Renvoie une référence à l'élément à la position n dans le conteneur vectoriel
             */
            const_reference operator[](size_type n) const { return (this->_start[n]); };

            /**
             * @brief Élément d'accès
             * Renvoie une référence à l'élément à la position n dans le conteneur vectoriel
             */
            reference at(size_type n) {
                if (this->size() < n) {
                    throw std::out_of_range("ft::vector");
                }
                return (this->_start[n]);
            };

            /**
             * @brief Élément d'accès
             * Renvoie une référence à l'élément à la position n dans le conteneur vectoriel
             */
            const_reference at(size_type n) const {
                if (this->size() < n) {
                    throw std::out_of_range("ft::vector");
                }
                return (this->_start[n]);
            };

            /**
             * @brief Accéder au premier élément
             * Renvoie une référence au premier élément du vecteur.
             */
            reference front() { return (*this->_start); };

            /**
             * @brief Accéder au premier élément
             * Renvoie une référence au premier élément du vecteur.
             */
            const_reference front() const { return (*this->_start); };

            /**
             * @brief Accéder au dernier élément
             * Renvoie une référence au dernier élément du vecteur.
             */
            reference back() { return *(this->_end - 1); };

            /**
             * @brief Accéder au dernier élément
             * Renvoie une référence au dernier élément du vecteur.
             */
            const_reference back() const { return *(this->_end - 1); };

            /**
             * @brief Attribution de contenu vectoriel
             * Attribue un nouveau contenu au vecteur, en remplaçant
             * son contenu actuel, et modifier sa taille en conséquence.
             *
             * @tparam InputIterator
             * @param first start
             * @param last end
             */
            template < class InputIterator >
            void assign(
                InputIterator first, InputIterator last,
                typename ft::enable_if<
                    !ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
                size_type n = ft::difference(first, last);
                if (this->capacity() < n) {
                    this->_start = this->_alloc.allocate(n);
                    this->_end_capacity = this->_start + n;
                    this->_end = this->_start;
                } else {
                    this->clear();
                }
                while (n--) this->_alloc.construct(this->_end++, *first++);
            };

            /**
             * @brief Attribution de contenu vectoriel
             * Attribue un nouveau contenu au vecteur, en remplaçant
             * son contenu actuel, et modifier sa taille en conséquence.
             *
             * @param n Nouvelle taille conteneur.
             * @param val Valeur avec laquelle remplir le conteneur
             */
            void assign(size_type n, const value_type& val) {
                this->clear();
                if (this->capacity() >= n) {
                    while (n--) this->_alloc.construct(this->_end++, val);
                } else {
                    this->_start = this->_alloc.allocate(n);
                    this->_end_capacity = this->_start + n;
                    this->_end = this->_start;
                    while (n--) this->_alloc.construct(this->_end++, val);
                }
            };

            /**
             * @brief Ajouter un élément à la fin
             *
             * @param val : Valeur à copier (ou déplacer) vers le nouvel élément.
             */
            void push_back(const value_type& val) {
                if (this->_end_capacity == this->_end) {
                    size_type capacity =
                        (this->size() == 0) ? 1 : (this->_end_capacity - this->_start) * 2;
                    this->reserve(capacity);
                }
                this->_alloc.construct(this->_end++, val);
            };

            /**
             * @brief Supprimer le dernier élément
             * Supprime le dernier élément du vecteur,
             * réduisant efficacement la taille conteneur.
             */
            void pop_back() { this->_alloc.destroy(--this->_end); };

            /**
             * @brief Insert élément
             *
             * @param position
             * @param val
             * @return itérateur, Un itérateur qui pointe vers le premier
             * des éléments nouvellement insérés éléments.
             */
            iterator insert(iterator position, const value_type& val) {
                size_type pos_at = &(*position) - this->_start;
                this->insert(position, 1, val);
                return (this->_start + pos_at);
            };

            /**
             * @brief Remplir, Insérer des éléments
             *
             * @param position
             * @param n
             * @param val
             */
            void insert(iterator position, size_type n, const value_type& val) {
                size_type pos_at = &(*position) - this->_start;

                if (this->capacity() >= this->size() + n) {
                    for (size_type i = 0; i < this->size() - pos_at; ++i) {
                        this->_alloc.construct(this->_end + n - i, *(this->_end - i));
                        this->_alloc.destroy(this->_end - i);
                    }
                    this->_end = this->_start + this->size() + n;
                    for (size_type i = 0; i < n; ++i) {
                        this->_alloc.construct(this->_start + pos_at + i, val);
                    }
                    return;
                }

                size_type next_capacity = this->size() + n;

                pointer prev_start = this->_start;
                pointer prev_end = this->_end;
                size_type prev_size = this->size();
                size_type prev_capacity = this->capacity();

                this->_start = this->_alloc.allocate(next_capacity);
                this->_end = this->_start + prev_size + n;
                this->_end_capacity = this->_end;

                for (size_type i = 0; i < pos_at; ++i) {
                    this->_alloc.construct(this->_start + i, *(prev_start + i));
                    this->_alloc.destroy(prev_start + i);
                }

                for (size_type i = 0; i < prev_size - pos_at; ++i) {
                    this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
                    this->_alloc.destroy(prev_end - i - 1);
                }

                for (size_type i = 0; i < n; ++i) {
                    this->_alloc.construct(this->_start + pos_at + i, val);
                }

                this->_alloc.deallocate(prev_start, prev_capacity);
                return;
            };

            /**
             * @brief Intervalle d'insertion d'éléments
             *
             * @tparam InputIterator
             * @param position
             * @param first
             * @param last
             */
            template < class InputIterator >
            void insert(
                iterator position, InputIterator first, InputIterator last,
                typename ft::enable_if<
                    !ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
                size_type pos_at = &(*position) - this->_start;
                size_type n = ft::difference(first, last);

                if (this->capacity() >= this->size() + n) {
                    for (size_type i = 0; i < this->size() - pos_at; ++i) {
                        this->_alloc.construct(this->_end + n - i, *(this->_end - i));
                        this->_alloc.destroy(this->_end - i);
                    }
                    this->_end = this->_start + this->size() + n;
                    for (size_type i = 0; i < n; ++i) {
                        this->_alloc.construct(this->_start + pos_at + i, *first++);
                    }
                    return;
                }

                size_type next_capacity = this->size() + n;

                pointer prev_start = this->_start;
                pointer prev_end = this->_end;
                size_type prev_size = this->size();
                size_type prev_capacity = this->capacity();

                this->_start = this->_alloc.allocate(next_capacity);
                this->_end = this->_start + prev_size + n;
                this->_end_capacity = this->_end;

                for (size_type i = 0; i < pos_at; ++i) {
                    this->_alloc.construct(this->_start + i, *(prev_start + i));
                    this->_alloc.destroy(prev_start + i);
                }

                for (size_type i = 0; i < prev_size - pos_at; ++i) {
                    this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
                    this->_alloc.destroy(prev_end - i - 1);
                }

                for (size_type i = 0; i < n; ++i) {
                    this->_alloc.construct(this->_start + pos_at + i, *first++);
                }
                this->_alloc.deallocate(prev_start, prev_capacity);
                return;
            }

            /**
             * @brief Supprimer des éléments
             *
             * @param position
             * @return iterator
             */
            iterator erase(iterator position) {
                size_type pos_at = &(*position) - this->_start;
                this->_alloc.destroy(&(*position));
                for (size_type i = 0; i < this->size() - pos_at; ++i) {
                    this->_alloc.construct(this->_start + pos_at + i,
                                        *(this->_start + pos_at + i + 1));
                    this->_alloc.destroy(this->_start + pos_at + i + 1);
                }
                --this->_end;
                return this->_start + pos_at;
            };
            /**
             * @brief Intervalle, Supprimer des éléments
             *
             * @param first
             * @param last
             * @return iterator
             */
            iterator erase(iterator first, iterator last) {
                size_type pos_at = &(*first) - this->_start;
                size_type n = last - first;
                for (size_type i = 0; i < n; ++i) {
                    this->_alloc.destroy(&(*(first + i)));
                }
                for (size_type i = 0; i < this->size() - pos_at; ++i) {
                    this->_alloc.construct(this->_start + pos_at + i,
                                        *(this->_start + pos_at + i + n));
                    this->_alloc.destroy(this->_start + pos_at + i + n);
                }
                this->_end = this->_start + this->size() - n;
                return this->_start + pos_at;
            };

            /**
             * @brief Echange de contenu
             *
             * @param x Autre vector;
             */
            void swap(vector& x) {
                if (&x == this) {
                    return;
                }

                pointer start = x._start;
                pointer end = x._end;
                pointer end_capacity = x._end_capacity;
                x._start = this->_start;
                x._end = this->_end;
                x._end_capacity = this->_end_capacity;
                this->_start = start;
                this->_end = end;
                this->_end_capacity = end_capacity;
            };

            /**
             * @brief Effacer le contenu
             * Supprime tous les éléments du vecteur (qui sont détruits),
             * laissant le conteneur à taille 0.
             */
            void clear() {
                while (this->_start != this->_end) {
                    this->_alloc.destroy(--this->_end);
                }
            };

            /**
             * @brief Obtenir l'objet d'allocation
             *
             * @return allocator_type
             */
            allocator_type get_allocator() const { return this->_alloc; };
    };

    /**
     * @brief opérateur de comparaison entre vector
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator==(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    /**
     * @brief opérateur de comparaison entre vector (Not)
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        return !(lhs == rhs);
    }

    /**
     * @brief opérateur de comparaison entre vector
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator<(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end());
    }

    /**
     * @brief opérateur de comparaison entre vector
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        return (!(rhs < lhs));
    }

    /**
     * @brief opérateur de comparaison entre vector
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        return (rhs < lhs);
    }

    /**
     * @brief opérateur de comparaison entre vector
     *
     * @tparam T
     * @tparam Alloc
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    template < class T, class Alloc >
    bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
        return (!(lhs < rhs));
    }

    /**
     * @brief Échanger le contenu des vecteurs
     *
     * @tparam T
     * @tparam Alloc
     * @param x
     * @param y
     */
    template < class T, class Alloc >
    void swap(vector< T, Alloc >& x, vector< T, Alloc >& y) {
        x.swap(y);
    }

}

#endif
