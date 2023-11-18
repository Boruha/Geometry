#include <benchmark/benchmark.h>

#include <types/fint_t.hpp>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace BPW;

static void 
BM_doubles(benchmark::State& state) {
    std::vector<double> values(1000ul);

    for(auto _ : state) {
        std::iota(values.begin(), values.end(), 0.0);
        std::for_each(values.begin(), values.end(), [](auto& val) { val *= val; }); 
    }
}

static void 
BM_fint64t(benchmark::State& state) {
    std::vector<fint64_t> values(1000ul);

    for(auto _ : state) {
        std::iota(values.begin(), values.end(), fint64_t {0.0});
        std::for_each(values.begin(), values.end(), [](auto& val) { val *= val; }); 
    }
}

BENCHMARK(BM_doubles);
BENCHMARK(BM_fint64t);