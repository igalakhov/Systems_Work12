#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

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
	cur = readdir(curdir);

	int dirsize = 0;
	char * dirs = malloc(1);
	char * files = malloc(1);
		
	while(cur = readdir(curdir)){
		if(cur->d_type == 4){		
			dirs = realloc(dirs, sizeof(dirs) + sizeof(cur->d_name));
				
			strcat(dirs, cur->d_name);
			strcat(dirs, "\n");
		}
		else if(cur->d_type == 8){
			files = realloc(files, sizeof(files) + sizeof(cur->d_name));		
			strcat(files, cur->d_name);
			strcat(files, "\n");
				
		}
	}
	
	printf("Directory entry:\n%s\n", dirs);
	printf("File entry:\n%s", files);
	closedir(curdir);
}

int main(){
	printdir(s);

	return 0;
}

















