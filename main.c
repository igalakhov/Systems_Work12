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

	if(!curdir){
		printf(" Directory doesn't exist!!!\n");
		exit(1);
	}

	struct dirent * cur;
	cur = readdir(curdir);

	int dirsize = 0;
	char * dirs = malloc(1);
	char * files = malloc(1);

	struct stat file;

	while((cur = readdir(curdir))){
		if(cur->d_type == DT_DIR){
			dirs = realloc(dirs, sizeof(dirs) + sizeof(cur->d_name));

			strcat(dirs, cur->d_name);
			strcat(dirs, "\n ");
		} else {
			files = realloc(files, sizeof(files) + sizeof(cur->d_name) + 2); // 2 for space and newline
			strcat(files, cur->d_name);
			strcat(files, "\n ");

			// statistics
			stat(cur->d_name, &file);

			dirsize += file.st_size;
		}
	}
	printf("Total directory size: %s\n", formatsize(dirsize));
	printf("Directory entries:\n %s\n", dirs);
	printf("File entries:\n %s", files);
	closedir(curdir);
}

int main(int argc, char * argv[]){
	char dir[256];
	char *dir2;
    if(argc > 1){
		// use command line input
		dir2 = argv[1];
		printdir(dir2);
    } else {
		// ask user for input
		printf("No directory specified, please enter one: ");
		scanf("%s",dir);
		printdir(dir);
    }
		printf("\n");
    return 0;
}
