#include <gtest/gtest.h>

#include <geometry/types/type_aliases.hpp>

using namespace bpw;

TEST(fint_t, ctor) {
    constexpr auto     iBase     { 5l };
    constexpr fint64_t fixedBase { iBase };
    EXPECT_EQ(fixedBase.Number,  iBase * fint64_t::kScale);
    EXPECT_EQ(fixedBase.base<std::int64_t>(),  iBase);

    constexpr auto     dBase      { 2.5 };
    constexpr fint64_t fixedBase2 { dBase };
    EXPECT_EQ(fixedBase2.Number, dBase * fint64_t::kScale);
    EXPECT_EQ(fixedBase2.base<double>(), dBase);

    constexpr auto     fBase      { 2.5f };
    constexpr fint64_t fixedBase3 { fBase };
    EXPECT_EQ(fixedBase3.Number, fBase * fint64_t::kScale);
    EXPECT_EQ(fixedBase3.base<float>(), fBase);
}

TEST(fint_t, operations) {
    constexpr auto     base    { 2.5 };
    constexpr fint64_t fixed   { base };
    constexpr auto     epsilon { 0.001 };
    
    constexpr auto multBase  { base * base };
    constexpr auto multFixed { fixed * fixed };
    EXPECT_NEAR(multBase, multFixed.base<double>(), epsilon);

    constexpr auto divBase  { base / base };
    constexpr auto divFixed { fixed / fixed };
    EXPECT_NEAR(divBase, divFixed.base<double>(), epsilon);

    constexpr auto sumBase  { base + base };
    constexpr auto sumFixed { fixed + fixed };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);

    constexpr auto subBase  { base - base };
    constexpr auto subFixed { fixed - fixed };
    EXPECT_NEAR(subBase, subFixed.base<double>(), epsilon);
}

TEST(fint_t, extra_operations) {
              auto     base    { 1.0 };
              fint64_t fixed   { base };
    constexpr auto     base2   { 2.0 };
    constexpr fint64_t fixed2  { base2 };
    constexpr auto     epsilon { 0.001 };

    ++base;
    ++fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    --base;
    --fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
}

TEST(fint_t, operations_assignment) {
              auto     base    { 2.5 };
              fint64_t fixed   { base };
    constexpr auto     epsilon { 0.001 };

    base  += base;
    fixed += fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    base  *= base;
    fixed *= fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    base  /= base;
    fixed /= fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
    
    base  -= base;
    fixed -= fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
}

TEST(fint_t, operations_primitive_type) {
    constexpr auto     base    { 2.5 };
    constexpr fint64_t fixed   { base };
    constexpr auto     epsilon { 0.001 };
    
    constexpr auto     multBase  { base * base };
    constexpr fint64_t multFixed { fixed * base };
    EXPECT_NEAR(multBase, multFixed.base<double>(), epsilon);

    constexpr auto     divBase  { base / base };
    constexpr fint64_t divFixed { fixed / base };
    EXPECT_NEAR(divBase, divFixed.base<double>(), epsilon);

    constexpr auto     sumBase  { base + base };
    constexpr fint64_t sumFixed { fixed + base };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);

    constexpr auto     subBase  { base - base };
    constexpr fint64_t subFixed { fixed - base };
    EXPECT_NEAR(subBase, subFixed.base<double>(), epsilon);
}

TEST(fint_t, operations_assignment_primitive_type) {
    constexpr auto epsilon { 0.001 };

    auto     base  { 2.5 };
    fint64_t fixed { base };
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    fixed *= base;
    base  *= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    fixed /= base;
    base  /= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
    
    fixed += base;
    base  += base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    
    fixed -= base;
    base  -= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
}

TEST(fint_t, logical_operations) {
    constexpr fint64_t lhs { 5.0 };
              fint64_t rhs { 2.5 };

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