#include <benchmark/benchmark.h>

#include "MyLib/MyClass.hpp"

// Define benchmark
static void BM_StringCreation(benchmark::State &state) {
  MyLib::MyClass mc;
  mc.setA(3);
  for (auto _ : state) std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

BENCHMARK_MAIN();
