#include <gtest/gtest.h>

#include <types/fint_t.hpp>

TEST(fint_t, Ctor) {
    constexpr auto iBase     { 5i64 };
    constexpr auto fixedBase { BPW::make_fint64_t(iBase) };
    EXPECT_EQ(fixedBase.number,  iBase * BPW::fint64_t::SCALE);
    EXPECT_EQ(fixedBase.base<std::int64_t>(),  iBase);

    constexpr auto dBase      { 2.5 };
    constexpr auto fixedBase2 { BPW::make_fint64_t(dBase) };
    EXPECT_EQ(fixedBase2.number, dBase * BPW::fint64_t::SCALE);
    EXPECT_EQ(fixedBase2.base<double>(), dBase);

    constexpr auto fBase      { 2.5f };
    constexpr auto fixedBase3 { BPW::make_fint64_t(fBase) };
    EXPECT_EQ(fixedBase3.number, fBase * BPW::fint64_t::SCALE);
    EXPECT_EQ(fixedBase3.base<float>(), fBase);
}