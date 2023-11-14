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

// #include <cmath>
// #include <utility>

// namespace BPW {

// template<typename NumType>
// struct vec2 {
//     vec2() = default;
//     constexpr explicit vec2(const NumType X,  const NumType Y ) noexcept;
//     constexpr          vec2(const vec2<NumType>& cpy_vec)       noexcept = default; //cpy ctor
//     constexpr          vec2(vec2<NumType>&& mov_vec)            noexcept = default; //move ctor

//     NumType x { 0 };
//     NumType y { 0 };

// /* ASSIGMENT */
//     vec2<NumType>& operator=(const vec2<NumType>& copy_from) noexcept;
//     vec2<NumType>& operator=(vec2<NumType>&& move_from)      noexcept;
//     vec2<NumType>& operator+=(const vec2<NumType>& num)      noexcept;
//     vec2<NumType>& operator-=(const vec2<NumType>& num)      noexcept;
//     vec2<NumType>& operator*=(const vec2<NumType>& num)      noexcept;
//     vec2<NumType>& operator/=(const vec2<NumType>& num)      noexcept;

// /* OPERATIONS */
//     constexpr vec2<NumType> operator+(const vec2<NumType>& num) const noexcept;
//     constexpr vec2<NumType> operator-(const vec2<NumType>& num) const noexcept;
//     constexpr vec2<NumType> operator*(const vec2<NumType>& num) const noexcept;
//     constexpr vec2<NumType> operator/(const vec2<NumType>& num) const noexcept;

// /* OPERATIONS W/ NO VEC*/
//     constexpr vec2<NumType> operator+(const NumType& num) const noexcept;
//     constexpr vec2<NumType> operator-(const NumType& num) const noexcept;
//     constexpr vec2<NumType> operator*(const NumType& num) const noexcept;
//     constexpr vec2<NumType> operator/(const NumType& num) const noexcept;

// /* FUNCTIONS */
//     constexpr NumType length()    const noexcept;
//     constexpr NumType length2()   const noexcept;
//     constexpr void    normalize()       noexcept;
// };

// template <typename NumType> constexpr vec2<NumType>::vec2(const NumType X,  const NumType Y ) noexcept : x(X), y(Y) { }

// /* ASSIGMENT */
// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator=(const vec2<NumType>& copy_from) noexcept { //copy assigment 
//     x = copy_from.x; 
//     y = copy_from.y; 
//     return *this; 
// }

// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator=(vec2<NumType>&& move_from) noexcept { //move assigment
//     x = std::exchange(move_from.x, 0); 
//     y = std::exchange(move_from.y, 0);
//     return *this;
// }

// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator+=(const vec2<NumType>& num) noexcept {
//     x += num.x;
//     y += num.y;
//     return *this;
// }

// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator-=(const vec2<NumType>& num) noexcept {
//     x -= num.x;
//     y -= num.y;
//     return *this;
// }

// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator*=(const vec2<NumType>& num) noexcept {
//     x *= num.x;
//     y *= num.y;
//     return *this;
// }

// template <typename NumType> 
// vec2<NumType>& 
// vec2<NumType>::operator/=(const vec2<NumType>& num) noexcept {
//     x /= num.x;
//     y /= num.y;
//     return *this;
// }


// /* OPERATIONS */
// template <typename NumType> constexpr 
// vec2<NumType>
// vec2<NumType>::operator+(const vec2<NumType>& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x + num.x;
//     new_vec.y = y + num.y;
//     return new_vec;
// }

// template <typename NumType> constexpr
// vec2<NumType>
// vec2<NumType>::operator-(const vec2<NumType>& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x - num.x; 
//     new_vec.y = y - num.y; 
//     return new_vec;
// }

// template <typename NumType> constexpr 
// vec2<NumType> 
// vec2<NumType>::operator*(const vec2<NumType>& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x * num.x; 
//     new_vec.y = y * num.y; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// vec2<NumType> 
// vec2<NumType>::operator/(const vec2<NumType>& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x / num.x; 
//     new_vec.y = y / num.y; 
//     return new_vec;
// }


// /* OPERATIONS W/ NO VEC*/
// template <typename NumType> constexpr
// vec2<NumType> 
// vec2<NumType>::operator+(const NumType& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x + num; 
//     new_vec.y = y + num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// vec2<NumType> 
// vec2<NumType>::operator-(const NumType& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x - num; 
//     new_vec.y = y - num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// vec2<NumType> 
// vec2<NumType>::operator*(const NumType& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x * num; 
//     new_vec.y = y * num; 
//     return new_vec;
// }

// template <typename NumType> constexpr
// vec2<NumType> 
// vec2<NumType>::operator/(const NumType& num) const noexcept {
//     vec2<NumType> new_vec { };
//     new_vec.x = x / num; 
//     new_vec.y = y / num; 
//     return new_vec;
// }


// /* FUNCTIONS */
// template <typename NumType>constexpr 
// NumType 
// vec2<NumType>::length() const noexcept {
//     return std::sqrt( (x * x) + (y * y) );
// }

// template <typename NumType> constexpr
// NumType
// vec2<NumType>::length2() const noexcept {
//     return (x*x) + (y*y);
// }

// template <typename NumType> constexpr 
// void 
// vec2<NumType>::normalize() noexcept {
//     auto module = length();
    
//     if(module != 0) {
//         x /= module; y /= module;
//     }
//     else {
//         x = 0; y = 0;
//     }
// }

// }