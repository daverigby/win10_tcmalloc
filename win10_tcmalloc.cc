#include <cstdio>
#include <gperftools/tcmalloc.h>
#include <thread>

int main() {
	fprintf(stderr, "%s\n", tc_version(nullptr, nullptr, nullptr));

	std::thread t1{[](){
		fprintf(stderr, "[T1] Created\n");
	}};

	fprintf(stderr, "[T0] Joining t1\n");
	t1.join();
	fprintf(stderr, "[T0] Joined t1\n");
}