#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define MIN_LENGTH 4

int DEBUG;

typedef struct {
    TYPE *array;
    int left;
    int right;
    int tid;
} thread_data_t;

int number_of_threads;
pthread_mutex_t lock_number_of_threads;

// Comparator function, just assumes that there is < and ==
// operator on TYPE
int my_comp(const void *larg, const void *rarg) {
    TYPE l = *(TYPE *)larg;
    TYPE r = *(TYPE *)rarg;
    if (l < r) {
        return -1;
    } else if (l == r) {
        return 0;
    }
    return 1;
}

void merge(TYPE *data, int left, int right, int tid) {
    if (DEBUG) {
        printf("[%d] Merging %d to %d\n", tid, left, right);
    }
    int ctr = 0;
    int i = left;
    int mid = left + ((right - left) / 2);
    int j = mid + 1;
    int *c = (int *) malloc((right - left + 1) * sizeof(int));
    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            c[ctr++] =  data[i++];
        } else {
            c[ctr++] =  data[j++];
        }
    }
    // Either i = mid + 1 OR j = right + 1
    if (i == mid + 1) {
        while (j <= right) {
            c[ctr++] = data[j++];
        }
    } else {
        while (i <= mid) {
            c[ctr++] = data[i++];
        }
    }
    // Copy the data back !
    i = left;
    ctr = 0;
    while (i <= right) {
        data[i++] = c[ctr++];
    }
    free(c);
    return;
}

// The function passed to a pthread_t variable.
void *merge_sort_threaded(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int l = data->left;
    int r = data->right;
    int t = data->tid;
    if (r - l + 1 <= MIN_LENGTH) {
        // Length is too short, let us do a |qsort|.
        if (DEBUG) {
            printf("[%d] Calling qsort(%d, %d).\n", t, l, r);
        }
        qsort(data->array + l, r - l + 1, sizeof(TYPE), my_comp);
    } else {
        // Try to create two threads and assign them work.
        int m = l + ((r - l) / 2);
        
        // Data for thread 1
        thread_data_t data_0;
        data_0.left = l;
        data_0.right = m;
        data_0.array = data->array;
        pthread_mutex_lock(&lock_number_of_threads);
            data_0.tid = number_of_threads++;
        pthread_mutex_unlock(&lock_number_of_threads);
        // Create thread 1
        pthread_t thread0;
        int rc = pthread_create(&thread0,
                                NULL,
                                merge_sort_threaded,
                                &data_0);
        int created_thread_0 = 1;
        if (rc) {
            // Failed to create thread, call |qsort|.
            if (DEBUG) {
                printf("[%d] Failed to create thread, calling qsort.", data_0.tid);
            }
            created_thread_0 = 0;
            qsort(data->array + l, m - l + 1, sizeof(TYPE), my_comp);
        }

        // Data for thread 2
        thread_data_t data_1;
        data_1.left = m + 1;
        data_1.right = r;
        data_1.array = data->array;
        pthread_mutex_lock(&lock_number_of_threads);
        data_1.tid = number_of_threads++;
        pthread_mutex_unlock(&lock_number_of_threads);
        // Create thread 2
        pthread_t thread1;
        rc = pthread_create(&thread1,
                            NULL,
                            merge_sort_threaded,
                            &data_1);
        int created_thread_1 = 1;
        if (rc) {
            // Failed to create thread, call |qsort|.
            if (DEBUG) {
                printf("[%d] Failed to create thread, calling qsort.", data_1.tid);
            }
            created_thread_1 = 0;
            qsort(data->array + m + 1, r - m, sizeof(TYPE), my_comp);
        }
        // Wait for the created threads.
        if (created_thread_0) {
            pthread_join(thread0, NULL);
        }
        if (created_thread_1) {
            pthread_join(thread1, NULL);
        }
        // Ok, both done, now merge.
        // left - l, right - r
        merge(data->array, l, r, t);
    }
    pthread_exit(NULL);
    return NULL;
}

void merge_sort(TYPE *array, int start, int finish) {
    thread_data_t data;
    data.array = array;
    data.left = start;
    data.right = finish;

    // Initialize the shared data.
    number_of_threads = 0;
    pthread_mutex_init(&lock_number_of_threads, NULL);
    data.tid = 0;
    
    // Create and initialize the thread.
    pthread_t thread;
    int rc = pthread_create(&thread,
                            NULL,
                            merge_sort_threaded,
                            &data);
    if (rc) {
        if (DEBUG) {
            printf("[%d] Failed to create thread, calling qsort.",
                   data.tid);
        }
        qsort(array + start,
              finish - start + 1,
              sizeof(TYPE),
              my_comp);
    }
    
    // Wait for thread, i.e. the full merge sort algo.
    pthread_join(thread, NULL);
    return;
}

// Returns a pointer to an array of |n| integers.
int *random_array(int n) {
    int *rand_arr = (int *)malloc(n * sizeof(int));
    if (rand_arr) {
        int i = 0;
        for (i = 0; i < n; ) {
            rand_arr[i++] = rand();
        }
    }
    return rand_arr;
}

int main(int argc, char **argv) {
    //Verify input.
    if (argc < 2) {
        printf("Usage: %s random_array_length [want_debug_output]\n", argv[0]);
        return 0;
    }

    //Declaring and initializing variables.
    DEBUG = 1;
    if (argc == 3) {
        DEBUG = atoi(argv[2]);
    }
    int i;
    int n = atoi(argv[1]);
    int *p = random_array(n);
    if (!p) {
        return 1;
    }
    
    //Sorting
    printf("Before MergeSort: ");
    for(i=0; i<n; ++i)
        printf("%10d ", p[i]);
    printf("\n");
    merge_sort(p, 0, n - 1);
    printf("After MergeSort: ");
    for (i = 0; i < n; ++i)
		printf("%10d ", p[i]);
    printf("\n");
    
    //Clean up.
    free(p);
    pthread_mutex_destroy(&lock_number_of_threads);
    return 0;
}
