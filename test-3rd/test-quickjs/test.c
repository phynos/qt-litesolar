#include "js-runtime.h"
#include <pthread.h>

void *thread(void *arg)
{
    test_quickjs();
}

int main(int argc, char **argv)
{
    pthread_t th;
    int ret;
    int arg = 10;
    int *thread_ret = NULL;
    ret = pthread_create(&th, NULL, thread, &arg);
    if (ret != 0)
    {
        printf("Create thread error!\n");
        return -1;
    }
    printf("This is the main process.\n");
    pthread_join( th, (void**)&thread_ret );

    while (1)
    {
        _sleep(100);
    }
    
    return 0;
}
