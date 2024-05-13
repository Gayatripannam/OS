#include<stdio.h>
#include<unistd.h>

int main()
{
	int ret1, ret2, ret3, ret4,ret5;
	int child_pid,i,s;
	ret1 = fork();
	if(ret1 == 0){

	for(i=1; i<=5; i++) {
			printf("child: %d\n", i);
			sleep(1);
		}
		_exit(2);}

    ret2 = fork();
    if(ret2 == 0){
  
    for(i=1; i<=5; i++) {
              printf("child: %d\n", i);
              sleep(1);
          }
          _exit(2);}
     ret3 = fork();
     if(ret3 == 0){
  
     for(i=1; i<=5; i++) {
              printf("child: %d\n", i);
              sleep(1);
          }
          _exit(2);}

       ret4 = fork();
       if(ret4 == 0){
     
       for(i=1; i<=5; i++) {
                printf("child: %d\n", i);
                sleep(1);
            }
            _exit(2);}

        ret5 = fork();
         if(ret5 == 0){
     
         for(i=1; i<=5; i++) {
                  printf("child: %d\n", i);
                  sleep(1);
              }
              _exit(2);}
  




else {
		// parent process
		for(i=1; i<=10; i++) {
			printf("parent: %d\n", i);
			sleep(1);
			child_pid = wait(&s);


}

}
    return 0;
}

