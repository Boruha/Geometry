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

#include <utility>

// #include <type_traits>
// TODO: Add Type_traits

namespace BPW {

template <typename T>
struct fint_t {
/* Data */    
                            T Number { 0 };
    constexpr static inline T kScale { 65536 };

/* Ctors */
              fint_t()                           = default;
    constexpr fint_t(const fint_t& rhs) noexcept = default;
    constexpr fint_t(fint_t&& rhs)      noexcept = default;

    template<typename U> constexpr fint_t(const U rhs) : Number(kScale * rhs) {};

/* Assignment */
    constexpr fint_t& operator=(const fint_t& rhs)  noexcept { Number = rhs.Number;                     return *this; };
    constexpr fint_t& operator=(fint_t&& rhs)       noexcept { Number = std::exchange(rhs.Number, 0);   return *this; };
    constexpr fint_t& operator+=(const fint_t& rhs) noexcept { Number += rhs.Number;                    return *this; };
    constexpr fint_t& operator-=(const fint_t& rhs) noexcept { Number -= rhs.Number;                    return *this; };
    constexpr fint_t& operator*=(const fint_t& rhs) noexcept { Number = (Number * rhs.Number) / kScale; return *this; };
    constexpr fint_t& operator/=(const fint_t& rhs) noexcept { Number = (Number * kScale) / rhs.Number; return *this; };

/* Assignment w/ primitive_type */
    template<typename U> constexpr fint_t& operator+=(const U& rhs) noexcept { Number += (rhs * kScale); return *this; };
    template<typename U> constexpr fint_t& operator-=(const U& rhs) noexcept { Number -= (rhs * kScale); return *this; };
    template<typename U> constexpr fint_t& operator*=(const U& rhs) noexcept { Number *= rhs;            return *this; };
    template<typename U> constexpr fint_t& operator/=(const U& rhs) noexcept { Number /= rhs;            return *this; };

/* Operations */
    constexpr fint_t operator+(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.Number = Number + rhs.Number;            return new_t; };
    constexpr fint_t operator-(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.Number = Number - rhs.Number;            return new_t; };
    constexpr fint_t operator*(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.Number = (Number * rhs.Number) / kScale; return new_t; };
    constexpr fint_t operator/(const fint_t& rhs) const noexcept { fint_t new_t {};  new_t.Number = (Number * kScale) / rhs.Number; return new_t; };

/* Extra Operations */
    constexpr fint_t& operator++() noexcept { Number += kScale; return *this; };
    constexpr fint_t& operator--() noexcept { Number -= kScale; return *this; };

/* Operations w/ primitive_type */
    template<typename U> constexpr fint_t operator+(const U& rhs) const noexcept { fint_t new_t {}; new_t.Number = Number + (rhs * kScale); return new_t; };
    template<typename U> constexpr fint_t operator-(const U& rhs) const noexcept { fint_t new_t {}; new_t.Number = Number - (rhs * kScale); return new_t; };
    template<typename U> constexpr fint_t operator*(const U& rhs) const noexcept { fint_t new_t {}; new_t.Number = Number * rhs;            return new_t; };
    template<typename U> constexpr fint_t operator/(const U& rhs) const noexcept { fint_t new_t {}; new_t.Number = Number / rhs;            return new_t; };

/* Logical comparations */
    constexpr bool operator>(const fint_t& rhs)  const noexcept { return Number > rhs.Number;  };
    constexpr bool operator<(const fint_t& rhs)  const noexcept { return Number < rhs.Number;  };
    constexpr bool operator!=(const fint_t& rhs) const noexcept { return Number != rhs.Number; };
    constexpr bool operator==(const fint_t& rhs) const noexcept { return Number == rhs.Number; };

/* Logical comparations w/primitive_type */
    template<typename U> constexpr bool operator>(const U& rhs)  const noexcept { return Number > (rhs * kScale);  };
    template<typename U> constexpr bool operator<(const U& rhs)  const noexcept { return Number < (rhs * kScale);  };
    template<typename U> constexpr bool operator!=(const U& rhs) const noexcept { return Number != (rhs * kScale); };
    template<typename U> constexpr bool operator==(const U& rhs) const noexcept { return Number == (rhs * kScale); };

/* Getters */
    template<typename U> constexpr U base() const noexcept { 
        if constexpr(std::is_same_v<T, U>) { return Number / kScale; } 
        else { return static_cast<U>(Number) / static_cast<U>(kScale); } 
    };
};

}