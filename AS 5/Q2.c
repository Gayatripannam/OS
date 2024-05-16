#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int arr1[2], arr2[2], ret,r, s, res;
	int num1;
	int num2;
	int n1, n2;
	ret = pipe(arr1);
	ret = pipe(arr2);
	if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- writer process
		close(arr1[0]);// close read fd
		close(arr2[1]);
		printf("child: enter  numbers: ");
		scanf("%d %d",&num1,&num2);
		ret = write(arr1[1],&num1, sizeof(num1)); // write data in pipe
		ret = write(arr1[1],&num2, sizeof(num2));

		ret = read(arr2[0],&res,sizeof(res));
		printf("result: %d\n", res);
		printf("child: data written in pipe: %d bytes\n", ret);
		close(arr2[0]); // close write fd
		close(arr2[1]);
	}
	else {
		// parent -- reader process
		close(arr1[1]); // close write fd
        close(arr2[0]);
		printf("parent: waiting for data...\n");

	    ret = read(arr1[0], &n1, sizeof(n1));
		ret = read(arr1[0], &n2, sizeof(n2));

		r = n1 + n2;

		printf("parent: data read from pipe: %d  bytes -- %d \n",ret,r);

		ret = write(arr2[1], &r, sizeof(r));
		close(arr2[1]);// close read fd
		close(arr1[0]); 
		waitpid(-1, &s, 0);
	}

	return 0;
}

