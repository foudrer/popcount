#include "popcount.h"

// uint32_t direct_popcount_32(uint32_t num)
// uint32_t directop_popcount_32(uint32_t num)
// uint32_t fast_popcount_32(uint32_t num)
// uint32_t parallel_popcount_32(uint32_t num)
// uint32_t cpu_popcount_32(uint32_t num)

int main() {
	uint32_t num = 256;
	struct timespec time_start={0, 0},time_end={0, 0};

	clock_gettime(CLOCK_REALTIME, &time_start);
	std ::cout << "direct_popcount_32 result: " << direct_popcount_32(num) << std::endl;	
	clock_gettime(CLOCK_REALTIME, &time_end);
	std::cout << "##########################direct_popcount_32 duration: " << time_end.tv_sec-time_start.tv_sec << "s " << time_end.tv_nsec-time_start.tv_nsec << "ns" << std::endl;

	clock_gettime(CLOCK_REALTIME, &time_start);
	std ::cout << "directop_popcount_32 result: " << directop_popcount_32(num) << std::endl;	
	clock_gettime(CLOCK_REALTIME, &time_end);
	std::cout << "##########################directop_popcount_32 duration: " << time_end.tv_sec-time_start.tv_sec << "s " << time_end.tv_nsec-time_start.tv_nsec << "ns" << std::endl;

	clock_gettime(CLOCK_REALTIME, &time_start);
	std ::cout << "fast_popcount_32 result: " << fast_popcount_32(num) << std::endl;	
	clock_gettime(CLOCK_REALTIME, &time_end);
	std::cout << "##########################fast_popcount_32 duration: " << time_end.tv_sec-time_start.tv_sec << "s " << time_end.tv_nsec-time_start.tv_nsec << "ns" << std::endl;

	clock_gettime(CLOCK_REALTIME, &time_start);
	std ::cout << "parallel_popcount_32 result: " << parallel_popcount_32(num) << std::endl;	
	clock_gettime(CLOCK_REALTIME, &time_end);
	std::cout << "##########################parallel_popcount_32 duration: " << time_end.tv_sec-time_start.tv_sec << "s " << time_end.tv_nsec-time_start.tv_nsec << "ns" << std::endl;

	clock_gettime(CLOCK_REALTIME, &time_start);
	std ::cout << "cpu_popcount_32 result: " << cpu_popcount_32(num) << std::endl;	
	clock_gettime(CLOCK_REALTIME, &time_end);
	std::cout << "##########################cpu_popcount_32 duration: " << time_end.tv_sec-time_start.tv_sec << "s " << time_end.tv_nsec-time_start.tv_nsec << "ns" << std::endl;

	return 0;
}
