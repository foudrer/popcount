#include "popcount.h"

uint32_t direct_popcount_32(uint32_t num) {
	return 0;
}

uint32_t directop_popcount_32(uint32_t num) {
	return 0;
}

uint32_t fast_popcount_32(uint32_t num) {
	return 0;
}

uint32_t parallel_popcount_32(uint32_t num) {
	return 0;
}

uint32_t cpu_popcount_32(uint32_t num) {
	return _mm_popcnt_u32(num);
}

uint64_t direct_popcount_64(uint64_t num) {
	return 0;
}

uint64_t directop_popcount_64(uint64_t num) {
	return 0;
}

uint64_t fast_popcount_64(uint64_t num) {
	return 0;
}

uint64_t parallel_popcount_64(uint64_t num) {
	return 0;
}

uint64_t cpu_popcount_64(uint64_t num) {
	return _mm_popcnt_u64(num);
}
