#include <gtest/gtest.h>

#include <Geometry/Types/TypeAliases.hpp>

using namespace BPW;

TEST(Vec2, Ctor) {
    constexpr Vec2i32_t r {};
    EXPECT_EQ(r.X, 0);
    EXPECT_EQ(r.Y, 0);

    constexpr Vec2i32_t s {r + 4};
    EXPECT_EQ(s.X, 4);
    EXPECT_EQ(s.Y, 4);
}

TEST(Vec2, Operations) {
    constexpr Vec2fi64_t r       { 2.5, 3.0 };
    constexpr auto       epsilon { 0.001 };
    
    constexpr auto multR { r * r };
    constexpr auto divR { multR / r };
    EXPECT_EQ(r.X, divR.X);
    EXPECT_EQ(r.Y, divR.Y);

    constexpr auto sumR { r + r };
    constexpr auto subR { sumR - r };
    EXPECT_EQ(r.X, subR.X);
    EXPECT_EQ(r.Y, subR.Y);
}

TEST(Vec2, Operations_Assignment) {
    constexpr Vec2d_t r       { 2.5, 3.0 };
              Vec2d_t s       { r };
    constexpr auto    epsilon { 0.001 };

    s *= r;
    s /= r;
    EXPECT_NEAR(r.X, s.X, epsilon);
    EXPECT_NEAR(r.Y, s.Y, epsilon);

    s += r;
    s -= r;
    EXPECT_NEAR(r.X, s.X, epsilon);
    EXPECT_NEAR(r.Y, s.Y, epsilon);
}

TEST(Vec2, Operations_Primitive_Type) {
    constexpr double  x       { 2.5 };
              Vec2d_t s       { x, x };
    constexpr auto    epsilon { 0.001 };

    s *= x;
    s /= x;
    EXPECT_NEAR(x, s.X, epsilon);
    EXPECT_NEAR(x, s.Y, epsilon);

    s += x;
    s -= x;
    EXPECT_NEAR(x, s.X, epsilon);
    EXPECT_NEAR(x, s.Y, epsilon);
}

TEST(Vec2, Logical_Operations) {
    constexpr Vec2d_t lhs { 5.0, 5.0 };
              Vec2d_t rhs { 2.5, 2.5 };

    EXPECT_FALSE(lhs == rhs);
    EXPECT_FALSE(lhs < rhs);
    EXPECT_TRUE(lhs > rhs);
    EXPECT_TRUE(lhs != rhs);

    rhs *= 2.0;
    EXPECT_TRUE(lhs == rhs);
    EXPECT_FALSE(lhs < rhs);
    EXPECT_FALSE(lhs > rhs);
    EXPECT_FALSE(lhs != rhs);

    rhs *= 2.0;
    EXPECT_FALSE(lhs == rhs);
    EXPECT_TRUE(lhs < rhs);
    EXPECT_FALSE(lhs > rhs);
    EXPECT_TRUE(lhs != rhs);
}

TEST(Vec2, Extra_Operations) {
    constexpr Vec2d_t lhs     { 5.0, 5.0 };
    constexpr auto    epsilon { 0.001 };
    EXPECT_NEAR(lhs.Length() * lhs.Length(), lhs.LengthSqr(), epsilon);
}