#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
int count = 0;
int nums[1024];
int j;
for(j = 0; j<1024; j++) {
nums[j] = rand() % 10;
}
int i;
for(i = 0; i < 1024; i++) {
if(nums[i] == 3)
  count++;
}

printf("value = %d", count);


}
