/*
Copyright (C) <2023> Borja Pozo Wals (Tw: @Chico_Riot | GitHub: Boruha)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <cstdint>
#include <utility>

namespace AIP {

template <typename NumType>
struct fint_t {
    fint_t() = default;

    constexpr fint_t(NumType num)                noexcept; //ctor
    constexpr explicit fint_t(float   num)       noexcept; //ctor
    constexpr fint_t(const fint_t<NumType>& num) noexcept = default; //copy ctor
    constexpr fint_t(fint_t<NumType>&& num)      noexcept = default; //move ctor

/* ASSIGMENT */
              fint_t<NumType>& operator=(const fint_t<NumType>& copy_from) noexcept; //copy assigment
              fint_t<NumType>& operator=(fint_t<NumType>&& move_from)      noexcept; //move assigment
    constexpr fint_t<NumType>& operator+=(const fint_t<NumType>& num)      noexcept;
    constexpr fint_t<NumType>& operator-=(const fint_t<NumType>& num)      noexcept;
    constexpr fint_t<NumType>& operator*=(const fint_t<NumType>& num)      noexcept;
    constexpr fint_t<NumType>& operator/=(const fint_t<NumType>& num)      noexcept;

/* ASSIGMENT W/ BASE TYPE */
    constexpr fint_t<NumType>& operator+=(const NumType& num) noexcept;
    constexpr fint_t<NumType>& operator-=(const NumType& num) noexcept;
    constexpr fint_t<NumType>& operator*=(const NumType& num) noexcept;
    constexpr fint_t<NumType>& operator/=(const NumType& num) noexcept;

/* OPERATIONS */
    constexpr fint_t<NumType> operator+(const fint_t<NumType>& num) const noexcept;
    constexpr fint_t<NumType> operator-(const fint_t<NumType>& num) const noexcept;
    constexpr fint_t<NumType> operator*(const fint_t<NumType>& num) const noexcept;
    constexpr fint_t<NumType> operator/(const fint_t<NumType>& num) const noexcept;

/* OPERATIONS W/ BASE TYPE */
    constexpr fint_t<NumType> operator+(const NumType& num) const noexcept;
    constexpr fint_t<NumType> operator-(const NumType& num) const noexcept;
    constexpr fint_t<NumType> operator*(const NumType& num) const noexcept;
    constexpr fint_t<NumType> operator/(const NumType& num) const noexcept;

/* LOGICAL COMPARATIONS */
    constexpr bool operator>( const fint_t<NumType>& num) const noexcept;
    constexpr bool operator<( const fint_t<NumType>& num) const noexcept;
    constexpr bool operator!=(const fint_t<NumType>& num) const noexcept;

/* GETTERS */
    constexpr NumType getNoScaled() const noexcept;
    
/* DATA */    
                            NumType number { 0 };
    constexpr static inline NumType SCALE  { 65536 };
};


/* CTORS & COPY/MOVE */
template <typename NumType> constexpr fint_t<NumType>::fint_t(NumType num)                noexcept : number(num * SCALE)           { } //ctor
template <typename NumType> constexpr fint_t<NumType>::fint_t(float   num)                noexcept : number(num * SCALE)           { } //ctor


/* ASSIGMENT */
template <typename NumType>
fint_t<NumType>& 
fint_t<NumType>::operator=(const fint_t<NumType>& copy_from) noexcept{ //copy assigment 
    number = copy_from.number; 
    return *this; 
}

template <typename NumType>
fint_t<NumType>& 
fint_t<NumType>::operator=(fint_t<NumType>&& move_from) noexcept { //move assigment
    number = std::exchange(move_from.number, 0);
    return *this;
}

template <typename NumType> constexpr
fint_t<NumType>& 
fint_t<NumType>::operator+=(const fint_t<NumType>& num) noexcept {
    number += num.number;
    return *this;
}

template <typename NumType> constexpr
fint_t<NumType>& 
fint_t<NumType>::operator-=(const fint_t<NumType>& num) noexcept {
    number -= num.number;
    return *this;
}

template <typename NumType> constexpr 
fint_t<NumType>& 
fint_t<NumType>::operator*=(const fint_t<NumType>& num) noexcept {
    number = (number * num.number) / SCALE;
    return *this;
}

template <typename NumType> constexpr 
fint_t<NumType>&
fint_t<NumType>::operator/=(const fint_t<NumType>& num) noexcept {
    number = ((number*SCALE) / num.number);
    return *this;
}

/* ASSIGMENT W/ BASE TYPE */
template <typename NumType> constexpr
fint_t<NumType>& 
fint_t<NumType>::operator+=(const NumType& num) noexcept {
    number += (num * SCALE);
    return *this;
}

template <typename NumType> constexpr
fint_t<NumType>& 
fint_t<NumType>::operator-=(const NumType& num) noexcept {
    number -= (num * SCALE);
    return *this;
}

template <typename NumType> constexpr 
fint_t<NumType>& 
fint_t<NumType>::operator*=(const NumType& num) noexcept {
    number *= num;
    return *this;
}

template <typename NumType> constexpr 
fint_t<NumType>& 
fint_t<NumType>::operator/=(const NumType& num) noexcept {
    number /= num;
    return *this;
}


/* OPERATIONS */
template <typename NumType> constexpr
fint_t<NumType> 
fint_t<NumType>::operator+(const fint_t<NumType>& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number + num.number; 
    return new_t;
}

template <typename NumType> constexpr
fint_t<NumType>
fint_t<NumType>::operator-(const fint_t<NumType>& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number - num.number; 
    return new_t;
}

template <typename NumType> constexpr
fint_t<NumType> 
fint_t<NumType>::operator*(const fint_t<NumType>& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = ( number * num.number ) / SCALE;
    return new_t;
}

template <typename NumType> constexpr 
fint_t<NumType> 
fint_t<NumType>::operator/(const fint_t<NumType>& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = ((number*SCALE) / num.number); 
    return new_t;
}


/* OPERATIONS W/ BASE TYPE */
template <typename NumType> constexpr
fint_t<NumType> 
fint_t<NumType>::operator+(const NumType& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number + (num * SCALE); 
    return new_t;
}

template <typename NumType> constexpr 
fint_t<NumType> 
fint_t<NumType>::operator-(const NumType& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number - (num * SCALE);
    return new_t;
}

template <typename NumType> constexpr
fint_t<NumType> 
fint_t<NumType>::operator*(const NumType& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number * num;
    return new_t; 
}

template <typename NumType> constexpr 
fint_t<NumType> 
fint_t<NumType>::operator/(const NumType& num) const noexcept {
    fint_t<NumType> new_t { };
    new_t.number = number / num;
    return new_t;
}


/* LOGICAL COMPARATIONS */
template <typename NumType> constexpr 
bool 
fint_t<NumType>::operator>( const fint_t<NumType>& num) const noexcept {
    return number > num.number;
}

template <typename NumType> constexpr 
bool 
fint_t<NumType>::operator<( const fint_t<NumType>& num) const noexcept {
    return number < num.number;
}

template <typename NumType> constexpr 
bool 
fint_t<NumType>::operator!=(const fint_t<NumType>& num) const noexcept {
    return number != num.number;
}


/* GETTERS */
template <typename NumType> constexpr 
NumType 
fint_t<NumType>::getNoScaled() const noexcept{ 
    return number/SCALE; 
}

}