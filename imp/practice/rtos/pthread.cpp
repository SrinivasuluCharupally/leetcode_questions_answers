#include<iostream>
#include<pthread.h>

using namespace std;

void *task1(void *arg) {
 cout << "Thrad 1" << endl;
 return NULL;
}

void *task2(void *arg) {
	cout << "Thread 2 " << endl;
	return NULL;
}

int main() {
	pthread_t t1, t2;

	int rc1, rc2;

	rc1 = pthread_create(&t1, NULL, task1, NULL) ;
	rc2 = pthread_create(&t2, NULL, task2, NULL) ;


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}

