#include "popcount.h"

int main() {
	int loop = 5;
	struct timespec time_start={0, 0},time_end={0, 0};
	std::default_random_engine random(time(NULL));
	std::uniform_int_distribution<uint32_t> dis1(0, 4294967295);
	std::uniform_int_distribution<uint64_t> dis2(4294967296, 18446744073709551615ULL);

	std::cout << "32bit number popcount begins..." << std::endl;
	for (int i=0; i<loop; i++) {
		uint32_t num = dis1(random);
		std::cout << "32bit unsigned number: " << num << std::endl;
			
		sleep(2);		
		clock_gettime(CLOCK_REALTIME, &time_start);
        uint32_t result = direct_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "direct_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = directop_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "directop_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = fast_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "fast_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = parallel_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "parallel_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = hackmem_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "hackmem_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = cpu_popcount_32(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "cpu_popcount_32 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;
		std::cout << "next 32bit number sampling" << std::endl;
	    std::cout << " " << std::endl;
	}


	std::cout << "32bit number popcount is over!" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "64bit number popcount begins..." << std::endl;
	sleep(2);		
	
	for (int i=0; i<loop; i++) {
		uint64_t num = dis2(random);
		std::cout << "64bit unsigned number: " << num << std::endl;
		sleep(2);		
		
		clock_gettime(CLOCK_REALTIME, &time_start);
        uint64_t result = direct_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "direct_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = directop_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "directop_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = fast_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "fast_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = parallel_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "parallel_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = hackmem_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "hackmem_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;

		clock_gettime(CLOCK_REALTIME, &time_start);
        result = cpu_popcount_64(num);
		clock_gettime(CLOCK_REALTIME, &time_end);
		std::cout << "cpu_popcount_64 result: " << result << " and duration: " << time_end.tv_sec-time_start.tv_sec << " s " << time_end.tv_nsec-time_start.tv_nsec << " ns" << std::endl;
		std::cout << "next 64bit number sampling" << std::endl;
	    std::cout << " " << std::endl;
	}
	
	std::cout << "64bit number popcount is over!" << std::endl;
	return 0;
}
