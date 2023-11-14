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

// #pragma once

// #include "types/fint_t.hpp"

// #include <cmath>
// #include <utility>

// namespace BPW {

// template<typename NumType>
// struct fvec2 {
//     fvec2() = default;
//     constexpr          fvec2(const NumType X,  const NumType Y ) noexcept : x(X), y(Y) { };
//     constexpr          fvec2(const fvec2<NumType>& cpy_vec)      noexcept = default; //cpy ctor
//     constexpr          fvec2(fvec2<NumType>&& mov_vec)           noexcept = default; //move ctor

//     NumType x { 0l };
//     NumType y { 0l };

// /* ASSIGMENT */
//     fvec2<NumType>& operator=(const fvec2<NumType>& copy_from) noexcept;
//     fvec2<NumType>& operator=(fvec2<NumType>&& move_from)      noexcept;
//     fvec2<NumType>& operator+=(const fvec2<NumType>& num)      noexcept;
//     fvec2<NumType>& operator-=(const fvec2<NumType>& num)      noexcept;
//     fvec2<NumType>& operator*=(const fvec2<NumType>& num)      noexcept;
//     fvec2<NumType>& operator/=(const fvec2<NumType>& num)      noexcept;

// /* ASSIGMENT W/ NO VEC*/
//     fvec2<NumType>& operator=(const NumType& copy_from) noexcept;
//     fvec2<NumType>& operator=(NumType&& move_from)      noexcept;
//     fvec2<NumType>& operator+=(const NumType& num)      noexcept;
//     fvec2<NumType>& operator-=(const NumType& num)      noexcept;
//     fvec2<NumType>& operator*=(const NumType& num)      noexcept;
//     fvec2<NumType>& operator/=(const NumType& num)      noexcept;

// /* OPERATIONS */
//     constexpr fvec2<NumType> operator+(const fvec2<NumType>& num) const noexcept;
//     constexpr fvec2<NumType> operator-(const fvec2<NumType>& num) const noexcept;
//     constexpr fvec2<NumType> operator*(const fvec2<NumType>& num) const noexcept;
//     constexpr fvec2<NumType> operator/(const fvec2<NumType>& num) const noexcept;

// /* OPERATIONS W/ NO VEC*/
//     constexpr fvec2<NumType> operator+(const NumType& num) const noexcept;
//     constexpr fvec2<NumType> operator-(const NumType& num) const noexcept;
//     constexpr fvec2<NumType> operator*(const NumType& num) const noexcept;
//     constexpr fvec2<NumType> operator/(const NumType& num) const noexcept;

// /* FUNCTIONS */
//     constexpr auto    length()     const noexcept;
//     constexpr NumType length_fix() const noexcept;
//     constexpr NumType length2()    const noexcept;
//     constexpr void    normalize()        noexcept;
//     constexpr void    setZero()          noexcept;
// };

// /* ASSIGMENT */
// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator=(const fvec2<NumType>& copy_from) noexcept { //copy assigment 
//     x = copy_from.x; 
//     y = copy_from.y; 
//     return *this; 
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator=(fvec2<NumType>&& move_from) noexcept { //move assigment
//     x = std::exchange(move_from.x, 0l); 
//     y = std::exchange(move_from.y, 0l);
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator+=(const fvec2<NumType>& num) noexcept {
//     x += num.x;
//     y += num.y;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator-=(const fvec2<NumType>& num) noexcept {
//     x -= num.x;
//     y -= num.y;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator*=(const fvec2<NumType>& num) noexcept {
//     x *= num.x;
//     y *= num.y;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator/=(const fvec2<NumType>& num) noexcept {
//     x /= num.x;
//     y /= num.y;
//     return *this;
// }


// /* ASSIGMENT W/ NO VEC */
// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator=(const NumType& copy_from) noexcept { //copy assigment 
//     x = copy_from; 
//     y = copy_from; 
//     return *this; 
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator=(NumType&& move_from) noexcept { //move assigment
//     x = y = std::exchange(move_from, NumType { });
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator+=(const NumType& num) noexcept {
//     x += num;
//     y += num;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator-=(const NumType& num) noexcept {
//     x -= num;
//     y -= num;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator*=(const NumType& num) noexcept {
//     x *= num;
//     y *= num;
//     return *this;
// }

// template <typename NumType> 
// fvec2<NumType>& 
// fvec2<NumType>::operator/=(const NumType& num) noexcept {
//     x /= num;
//     y /= num;
//     return *this;
// }


// /* OPERATIONS */
// template <typename NumType> constexpr 
// fvec2<NumType>
// fvec2<NumType>::operator+(const fvec2<NumType>& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x + num.x;
//     new_vec.y = y + num.y;
//     return new_vec;
// }

// template <typename NumType> constexpr
// fvec2<NumType>
// fvec2<NumType>::operator-(const fvec2<NumType>& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x - num.x; 
//     new_vec.y = y - num.y; 
//     return new_vec;
// }

// template <typename NumType> constexpr 
// fvec2<NumType> 
// fvec2<NumType>::operator*(const fvec2<NumType>& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x * num.x; 
//     new_vec.y = y * num.y; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// fvec2<NumType> 
// fvec2<NumType>::operator/(const fvec2<NumType>& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x / num.x; 
//     new_vec.y = y / num.y; 
//     return new_vec;
// }


// /* OPERATIONS W/ NO VEC*/
// template <typename NumType> constexpr
// fvec2<NumType> 
// fvec2<NumType>::operator+(const NumType& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x + num; 
//     new_vec.y = y + num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// fvec2<NumType> 
// fvec2<NumType>::operator-(const NumType& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x - num; 
//     new_vec.y = y - num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// fvec2<NumType> 
// fvec2<NumType>::operator*(const NumType& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x * num; 
//     new_vec.y = y * num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// fvec2<NumType> 
// fvec2<NumType>::operator/(const NumType& num) const noexcept {
//     fvec2<NumType> new_vec { };
//     new_vec.x = x / num; 
//     new_vec.y = y / num; 
//     return new_vec;
// }


// /* FUNCTIONS */
// template <typename NumType> constexpr 
// auto 
// fvec2<NumType>::length() const noexcept {
//     auto x_no { x.getNoScaled() };
//     auto y_no { y.getNoScaled() };

//     return x_no = std::sqrt( (x_no * x_no) + (y_no * y_no) );
// }

// template <typename NumType> constexpr 
// NumType
// fvec2<NumType>::length_fix() const noexcept {
//     auto sqrt = length();
//     return NumType { sqrt };
// }

// template <typename NumType> constexpr
// NumType
// fvec2<NumType>::length2() const noexcept {
//     return (x*x) + (y*y);
// }

// template <typename NumType> constexpr 
// void 
// fvec2<NumType>::normalize() noexcept {
//     auto module = length();
    
//     if(module != 0) {
//         x /= module; y /= module;
//     }
//     else {
//         x.number = 0l; y.number = 0l;
//     }
// }

// template <typename NumType> constexpr 
// void 
// fvec2<NumType>::setZero() noexcept {
//     x.number = 0l; y.number = 0l;
// }

// }
