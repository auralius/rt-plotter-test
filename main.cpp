#include <unistd.h>
#include <iostream>
#include <math.h>

#include "shm-access.h"

key_t SHM_ID = 5678;
int SHM_SIZE = 64;

void *shm;

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
	
	ShmAccess shm_access(SHM_SIZE, SHM_ID);
	shm = shm_access.GetShmAddr();
	
	double t = 0;
	while (1){
		double * y = (double *) shm;
		*y = sin(t);
		*(y+1) = cos(t);
		*(y+2) = tan(t);
		printf("%f  %f  %f  %f\n", *(y), *(y+1), *(y+2), *(y+3));
		t = t + 0.1;
		usleep(10000);
	}
		
	
    return 0;
}
