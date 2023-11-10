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
#include <type_traits>
#include <iostream>

namespace BPW {

template <typename T>
struct fint_t {
    using value_type = T;

/* Data */    
                            value_type number { 0 };
    constexpr static inline value_type SCALE  { 65536 };

/* Ctors */
              fint_t()                           = default;
    constexpr fint_t(const fint_t& rhs) noexcept = default;
    constexpr fint_t(fint_t&& rhs)      noexcept = default;

    // constexpr template<typename U> fint_t(const U rhs) noexcept : number(static_cast<value_type>(rhs * static_cast<U>(SCALE))) {};

/* Assignment */
    constexpr fint_t& operator=(const fint_t& rhs)  noexcept { number = rhs.number;                    return *this; };
    constexpr fint_t& operator=(fint_t&& rhs)       noexcept { number = std::exchange(rhs.number, 0);  return *this; };
    constexpr fint_t& operator+=(const fint_t& rhs) noexcept { number += rhs.number;                   return *this; };
    constexpr fint_t& operator-=(const fint_t& rhs) noexcept { number -= rhs.number;                   return *this; };
    constexpr fint_t& operator*=(const fint_t& rhs) noexcept { number = (number * rhs.number) / SCALE; return *this; };
    constexpr fint_t& operator/=(const fint_t& rhs) noexcept { number = (number * SCALE) / rhs.number; return *this; };

/* Assignment w/ value_type */
    constexpr fint_t& operator+=(const value_type& rhs) noexcept { number += (rhs * SCALE); return *this; };
    constexpr fint_t& operator-=(const value_type& rhs) noexcept { number -= (rhs * SCALE); return *this; };
    constexpr fint_t& operator*=(const value_type& rhs) noexcept { number *= rhs;           return *this; };
    constexpr fint_t& operator/=(const value_type& rhs) noexcept { number /= rhs;           return *this; };

/* Operations */
    constexpr fint_t operator+(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.number = number + rhs.number;           return new_t; };
    constexpr fint_t operator-(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.number = number - rhs.number;           return new_t; };
    constexpr fint_t operator*(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.number = (number * rhs.number) / SCALE; return new_t; };
    constexpr fint_t operator/(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.number = (number * SCALE) / rhs.number; return new_t; };

/* Operations w/ value_type */
    constexpr fint_t operator+(const value_type& rhs) const noexcept { fint_t new_t {}; new_t.number = number + (rhs * SCALE); return new_t; };
    constexpr fint_t operator-(const value_type& rhs) const noexcept { fint_t new_t {}; new_t.number = number - (rhs * SCALE); return new_t; };
    constexpr fint_t operator*(const value_type& rhs) const noexcept { fint_t new_t {}; new_t.number = number * rhs;           return new_t; };
    constexpr fint_t operator/(const value_type& rhs) const noexcept { fint_t new_t {}; new_t.number = number / rhs;           return new_t; };

/* Logical comparations */
    constexpr bool operator>(const fint_t& rhs)  const noexcept { return number > rhs.number;  };
    constexpr bool operator<(const fint_t& rhs)  const noexcept { return number < rhs.number;  };
    constexpr bool operator!=(const fint_t& rhs) const noexcept { return number != rhs.number; };
    constexpr bool operator==(const fint_t& rhs) const noexcept { return number == rhs.number; };

/* Getters */
    template<typename U> constexpr U base() const noexcept { 
        if constexpr(std::is_same_v<value_type, U>) { return number / SCALE; } 
        else { return static_cast<U>(number) / static_cast<U>(SCALE); } 
    };
};

using fint64_t = fint_t<std::int64_t>;
using fint32_t = fint_t<std::int32_t>;

template<typename T, typename U> 
constexpr fint_t<T> 
make_fint_t(const U rhs) noexcept {
    fint_t<T> new_t {};
    new_t.number = rhs * fint_t<T>::SCALE;
    return new_t;
};

template<typename U> 
constexpr fint64_t make_fint64_t(const U rhs) noexcept {
    return make_fint_t<std::int64_t>(rhs);
};

template<typename U> 
constexpr fint32_t make_fint32_t(const U rhs) noexcept {
    return make_fint_t<std::int32_t>(rhs);
};


}