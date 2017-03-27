#include "popcount.h"

uint32_t direct_popcount_32(uint32_t num) {
	uint32_t Count = 0;
	for (int i=0; i<32; i++) {
		Count += num & 1;
		num >>= 1;
	}
	return Count;
}

uint32_t directop_popcount_32(uint32_t num) {
	uint32_t Count = 0;
	while (num != 0) {
		Count += num & 1;
		num >>= 1;
	}	
	return Count;
}

uint32_t fast_popcount_32(uint32_t num) {
	uint32_t Count = 0;
	while (num != 0) {
		num &= (num-1);
		Count++;
	}	
	return Count;
}

uint32_t parallel_popcount_32(uint32_t num) {
	num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
	num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
	num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
	num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
	num = (num & 0x0000ffff) + ((num >> 16) & 0x0000ffff);
	return num;
}

uint32_t hackmem_popcount_32(uint32_t num) {
	return 0;
}

uint32_t cpu_popcount_32(uint32_t num) {
	return _mm_popcnt_u32(num);
}

uint64_t direct_popcount_64(uint64_t num) {
	uint64_t Count = 0;
	for (int i=0; i<64; i++) {
		Count += num & 1;
		num >>= 1;
	}
	return Count;
}

uint64_t directop_popcount_64(uint64_t num) {
	uint64_t Count = 0;
	while (num != 0) {
		Count += num & 1;
		num >>= 1;
	}
	return Count;

}

uint64_t fast_popcount_64(uint64_t num) {
	uint64_t Count = 0;
	while (num != 0) {
		num &= (num-1);
		Count++;
	}
	return Count;
}

uint64_t parallel_popcount_64(uint64_t num) {
	num = (num & 0x5555555555555555) + ((num >> 1) & 0x5555555555555555);
	num = (num & 0x3333333333333333) + ((num >> 2) & 0x3333333333333333);
	num = (num & 0x0f0f0f0f0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f0f0f0f0f);
	num = (num & 0x00ff00ff00ff00ff) + ((num >> 8) & 0x00ff00ff00ff00ff);
	num = (num & 0x0000ffff0000ffff) + ((num >> 16) & 0x0000ffff0000ffff);
	num = (num & 0x00000000ffffffff) + ((num >> 32) & 0x00000000ffffffff);
	return num;
}

uint64_t hackmem_popcount_64(uint64_t num) {
	return 0;
}

uint64_t cpu_popcount_64(uint64_t num) {
	return _mm_popcnt_u64(num);
}
