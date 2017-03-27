#ifndef POPCOUNT_H
#define POPCOUNT_H

#include <iostream>
#include <nmmintrin.h>
#include <time.h>
#include <stdint.h>
#include <random>
#include <unistd.h>

uint32_t direct_popcount_32(uint32_t num);
uint32_t directop_popcount_32(uint32_t num);
uint32_t fast_popcount_32(uint32_t num);
uint32_t parallel_popcount_32(uint32_t num);
uint32_t hackmem_popcount_32(uint32_t num);
uint32_t cpu_popcount_32(uint32_t num);

uint64_t direct_popcount_64(uint64_t num);
uint64_t directop_popcount_64(uint64_t num);
uint64_t fast_popcount_64(uint64_t num);
uint64_t parallel_popcount_64(uint64_t num);
uint64_t hackmem_popcount_64(uint64_t num);
uint64_t cpu_popcount_64(uint64_t num);

#endif

