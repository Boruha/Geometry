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

#include "geometry/utils.hpp"

#include <utility>

namespace bpw {

template<typename T>
struct Vec2 {
    T X { 0 };
    T Y { 0 };
    
              Vec2() = default;
    constexpr Vec2(const T X,  const T Y ) noexcept : X(X), Y(Y) {}; 
    constexpr Vec2(const Vec2& rhs)        noexcept = default; 
    constexpr Vec2(Vec2&& rhs)             noexcept = default;

/* Assigment */
    constexpr Vec2& operator=(const Vec2& rhs) noexcept { X = rhs.X; Y = rhs.Y; return *this; }
    constexpr Vec2& operator=(Vec2&& rhs)      noexcept { X = std::exchange(rhs.X, 0); Y = std::exchange(rhs.Y, 0); return *this; }

/* Operations w/ assigment */
    constexpr Vec2& operator+=(const Vec2& rhs) noexcept { X += rhs.X; Y += rhs.Y; return *this; };
    constexpr Vec2& operator-=(const Vec2& rhs) noexcept { X -= rhs.X; Y -= rhs.Y; return *this; };
    constexpr Vec2& operator*=(const Vec2& rhs) noexcept { X *= rhs.X; Y *= rhs.Y; return *this; };
    constexpr Vec2& operator/=(const Vec2& rhs) noexcept { X /= rhs.X; Y /= rhs.Y; return *this; };

/* Operations */
    constexpr Vec2 operator+(const Vec2& rhs) const noexcept { return Vec2 { X + rhs.X, Y + rhs.Y }; };
    constexpr Vec2 operator-(const Vec2& rhs) const noexcept { return Vec2 { X - rhs.X, Y - rhs.Y }; };
    constexpr Vec2 operator*(const Vec2& rhs) const noexcept { return Vec2 { X * rhs.X, Y * rhs.Y }; };
    constexpr Vec2 operator/(const Vec2& rhs) const noexcept { return Vec2 { X / rhs.X, Y / rhs.Y }; };

/* Operations w/ T assigment */
    constexpr Vec2& operator+=(const T& rhs) noexcept { X += rhs; Y += rhs; return *this; };
    constexpr Vec2& operator-=(const T& rhs) noexcept { X -= rhs; Y -= rhs; return *this; };
    constexpr Vec2& operator*=(const T& rhs) noexcept { X *= rhs; Y *= rhs; return *this; };
    constexpr Vec2& operator/=(const T& rhs) noexcept { X /= rhs; Y /= rhs; return *this; };

/* Operations w/ T */
    constexpr Vec2 operator+(const T& rhs) const noexcept { return Vec2 { X + rhs, Y + rhs }; };
    constexpr Vec2 operator-(const T& rhs) const noexcept { return Vec2 { X - rhs, Y - rhs }; };
    constexpr Vec2 operator*(const T& rhs) const noexcept { return Vec2 { X * rhs, Y * rhs }; };
    constexpr Vec2 operator/(const T& rhs) const noexcept { return Vec2 { X / rhs, Y / rhs }; };


/* Logical comparations */
    constexpr bool operator>(const Vec2& rhs)  const noexcept { return LengthSqr() > rhs.LengthSqr();  };
    constexpr bool operator<(const Vec2& rhs)  const noexcept { return LengthSqr() < rhs.LengthSqr();  };
    constexpr bool operator!=(const Vec2& rhs) const noexcept { return X != rhs.X || Y != rhs.Y; };
    constexpr bool operator==(const Vec2& rhs) const noexcept { return Epsilon(X, rhs.X) && Epsilon(Y, rhs.Y); };

/* Functions */
    constexpr T LengthSqr()          const noexcept { return (X * X) + (Y * Y); };
    constexpr T Length()             const noexcept { return std::sqrt( LengthSqr() ); };
    constexpr T Dot(const Vec2& rhs) const noexcept { return (X * rhs.Y) - (Y * rhs.X); }

    constexpr void Normalize() noexcept {
        constexpr auto mod { Length() };

        if(mod != 0) { X /= mod; Y /= mod; }
        else         { X = 0; Y = 0; } 
    };
};

}