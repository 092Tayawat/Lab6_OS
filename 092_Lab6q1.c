//64050092 Tayawat Songcharoensuk
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int msum;
int csum;
void *runner(void *param);
int main(int argc, char *argv[]) {
	pthread_t  tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, argv[1]);

	int pUpper = atoi(argv[1]);
	if(pUpper > 0) {
		for (int i = 1; i <= pUpper; i++ ) 
			msum += i;
	 }
	pthread_join(tid,NULL);
	printf("msum = %d\ncsum = %d\n",msum,csum);
	printf("difference = %d\n ",csum-msum);
	return 0;
}
void *runner(void *param){
    int upper = atoi(param);
    int i;
    csum = 0;
    if(upper > 0) {
    	for (i = 1; i <= 2*upper; i++ )
		csum += i; 
    	}

    pthread_exit(0);
 }



