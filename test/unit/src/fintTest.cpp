#include <gtest/gtest.h>

#include <types/fint_t.hpp>

TEST(fint_t, Ctor) {
    constexpr auto iBase     { 5i64 };
    constexpr auto fixedBase { BPW::make_fint64_t(iBase) };
    EXPECT_EQ(fixedBase.Number,  iBase * BPW::fint64_t::kScale);
    EXPECT_EQ(fixedBase.base<std::int64_t>(),  iBase);

    constexpr auto dBase      { 2.5 };
    constexpr auto fixedBase2 { BPW::make_fint64_t(dBase) };
    EXPECT_EQ(fixedBase2.Number, dBase * BPW::fint64_t::kScale);
    EXPECT_EQ(fixedBase2.base<double>(), dBase);

    constexpr auto fBase      { 2.5f };
    constexpr auto fixedBase3 { BPW::make_fint64_t(fBase) };
    EXPECT_EQ(fixedBase3.Number, fBase * BPW::fint64_t::kScale);
    EXPECT_EQ(fixedBase3.base<float>(), fBase);
}

TEST(fint_t, Operations) {
    constexpr auto base    { 2.5 };
    constexpr auto fixed   { BPW::make_fint64_t(base) };
    constexpr auto epsilon { 0.001 };
    
    constexpr auto multBase  { base * base };
    constexpr auto multFixed { fixed * fixed };
    EXPECT_NEAR(multBase, multFixed.base<double>(), epsilon);

    constexpr auto divBase  { base / base };
    constexpr auto divFixed { fixed / fixed };
    EXPECT_NEAR(divBase, divFixed.base<double>(), epsilon);

    constexpr auto sumBase  { base + base };
    constexpr auto sumFixed { fixed + fixed };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);

    constexpr auto subsBase  { base - base };
    constexpr auto subsFixed { fixed - fixed };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);
}

TEST(fint_t, Extra_Operations) {
              auto base    { 1.0 };
              auto fixed   { BPW::make_fint64_t(base) };
    constexpr auto base2   { 2.0 };
    constexpr auto fixed2  { BPW::make_fint64_t(base2) };
    constexpr auto epsilon { 0.001 };

    ++base;
    ++fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    --base;
    --fixed;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);


}

TEST(fint_t, Operations_Assignment) {
              auto base    { 1.0 };
              auto fixed   { BPW::make_fint64_t(base) };
    constexpr auto epsilon { 0.001 };

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

TEST(fint_t, Operations_Primitive_Type) {
    constexpr auto base    { 2.5 };
    constexpr auto fixed   { BPW::make_fint64_t(base) };
    constexpr auto epsilon { 0.001 };
    
    constexpr auto multBase  { base * base };
    constexpr auto multFixed { fixed * base };
    EXPECT_NEAR(multBase, multFixed.base<double>(), epsilon);

    constexpr auto divBase  { base / base };
    constexpr auto divFixed { fixed / base };
    EXPECT_NEAR(divBase, divFixed.base<double>(), epsilon);

    constexpr auto sumBase  { base + base };
    constexpr auto sumFixed { fixed + base };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);

    constexpr auto subsBase  { base - base };
    constexpr auto subsFixed { fixed - base };
    EXPECT_NEAR(sumBase, sumFixed.base<double>(), epsilon);
}

TEST(fint_t, Operations_Assignment_Primitive_Type) {
    constexpr auto epsilon { 0.001 };

    auto base  { 1.0 };
    auto fixed { BPW::make_fint64_t(base) };
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    fixed += base;
    base  += base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    fixed *= base;
    base  *= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);

    fixed /= base;
    base  /= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
    
    fixed -= base;
    base  -= base;
    EXPECT_NEAR(base, fixed.base<double>(), epsilon);
}

TEST(fint_t, Logical_Operations) {
    constexpr auto epsilon { 0.001 };
    constexpr auto lhs     { BPW::make_fint64_t(5.0) };
              auto rhs     { BPW::make_fint64_t(2.5) };

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