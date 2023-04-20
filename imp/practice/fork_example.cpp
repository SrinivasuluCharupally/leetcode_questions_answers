#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main() { // 3690

pid_t pid1 = fork(); 
pid_t pid2 = fork(); // 3692 will be from main() process
printf("helo %d\n", pid1);
printf("helo %d\n", pid2);
return 0;
}
