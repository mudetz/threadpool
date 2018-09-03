#include <array>
#include <future>
#include <iostream>
#include "threadpool.h"

#define JOBS 10000

int main(void)
{
	// Create TP with 4 threads. If no param is given, threads are hardware
	// detected.
	ThreadPool T(4);

	// Create an array for pending jobs. It will be filled with the
	// functions return value. Note that "int" is the return type, for void
	// functions use void.
	std::array<std::future<size_t>, JOBS> jobs;
	for (size_t i = 0; i < JOBS; i++)
		jobs[i] = T.enqueue([i]() {
			return i;
		});

	// Wait until each job is finished
	for (auto &job : jobs)
		job.wait();

	// Get jobs return value. If function is void, then this for-loop is not
	// required. If you want to immediately use the return value, you can
	// skip the job.wait() loop and use this directly. It will wait for
	// values to be available.
	for (auto &job : jobs)
		std::cout << job.get() << '\n';
	return 0;
}
