/*************************************************************************
    > File Name: no_mutex.c
    > Author: couldtt(fyby)
    > Mail: fuyunbiyi@gmail.com
    > Created Time: 2013年12月15日 星期日 17时52分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int sharedi = 0;
int sharedj = 200020;
void* increse_num(void*);

int main(){
    int ret;
    pthread_t thrd[20];
   for(int i=0;i<20;i++){

   // ret = pthread_create(&thrd1, NULL, increse_num, NULL);
  //  ret = pthread_create(&thrd2, NULL, increse_num, NULL);
    ret = pthread_create(&thrd[i], NULL, increse_num, NULL);

   // pthread_join(thrd1, NULL);
 //   pthread_join(thrd2, NULL);
   // pthread_join(thrd[i], NULL);
      pthread_detach(thrd[i]);
      //pthread_detach(thrd2);
      //pthread_detach(thrd3);
}
sleep(30);
    printf("sharedi = %d\n", sharedi);

    return 0;

}

void* increse_num(void*) {
    long i,tmp;
    for(i=0; i<=100000; i++) {
        //tmp = sharedi;
	sharedj=sharedj-1;
	sharedi=sharedi+1;
       // tmp = tmp + 1;
        //sharedi = tmp;
	usleep(20);
    }
	printf("i%d\n",sharedi);
	printf("j%d\n",sharedj);

}
