#include <unistd.h>
#include <stdio.h>


int count3s = 0;
int counter = 0;
int nums[1024];
int counterss = 256;

int count3(int i, int j) {

int count = 0;
for(i; i < j; i++) {
if(nums[i] == 3)
  count++;
}
return count;
}


int main(int argc, char **argv) {

int j;
for(j = 0; j<1024; j++) {
nums[j] = rand() % 10;
}

pid_t pids[4];
int i;
int n = 4;

// count number of 3s in serial
int k;
int count3sSerial = 0;
for(k = 0; k<1024; k++) {
if(nums[k] == 3) {
count3sSerial += 1;
}
}
printf("number of 3s in serial = %d\n",count3sSerial);


for(i = 0; i<n; i++) {
pids[i] = fork();

if(pids[i] < 0) {
perror("fork");
abort();
}
else if(pids[i] == 0) {
printf("pid is ");
int x = count3(counterss*i, counterss*(i+1));
exit(x);
}
}

int status;
pid_t pid;
while(n > 0) {
int val = -1;
pid = wait(&val);
printf("", val);
count3s += val/255;
printf("count3s = %d\n", count3s);
n--;
}
return;
}
