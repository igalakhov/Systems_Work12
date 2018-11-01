#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>


char * s = ".";

char * formatsize(int size){
	char * p = malloc(100 * sizeof(char));
	sprintf(p, "%d GB, %d MB, %d KB, %d B",
	(size/(1024 * 1024 * 1024) % 1024),
	(size/(1024 * 1024) % 1024),
	(size/(1024) % 1024),
	(size % 1024));
	return p;
}

void printdir(char * dir){
  DIR * curdir;
	curdir = opendir(dir);

	struct dirent * cur;

	int dirsize = 0;
	char * dirs  = malloc(1 * sizeof(char));
	char * files = malloc(1 * sizeof(char));

	while((cur = readdir(curdir))){
			printf("Directory entry [%s]\n", cur->d_name);

	}
	closedir(curdir);
}

int main(){
	printdir(s);

	return 0;
}
