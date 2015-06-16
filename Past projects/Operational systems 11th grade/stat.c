#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char const *argv[])
{
	
	struct stat sts;
	int i;
	for ( i = 1; i < argc; ++i)
	{
		if(stat(argv[i], &sts) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    	}
    	else{
			printf("%lld\n", (long long) sts.st_size);
			 printf("Ownership:      UID=%ld   GID=%ld\n",(long) sts.st_uid, (long) sts.st_gid);
			 printf("Mode:           %lo (octal)\n",(unsigned long) sts.st_mode);

			 printf(S_ISDIR(sts.st_mode) ? "d" : "-" );
			 printf(sts.st_mode & S_IWUSR ? "w" : "-" );
			 printf(sts.st_mode & S_IXUSR ? "x" : "-" );
			 printf(sts.st_mode & S_IRGRP ? "r" : "-" );
			 printf(sts.st_mode & S_IWGRP ? "w" : "-" );
			 printf(sts.st_mode & S_IXGRP ? "x" : "-" );
			 printf(sts.st_mode & S_IROTH ? "r" : "-" );
			 printf(sts.st_mode & S_IWOTH ? "w" : "-" );
			 printf(sts.st_mode & S_IXOTH ? "x" : "-" );

			  printf("LastModified: %s", ctime(&sts.st_mtime));
		}
	}

	

	return 0;
}
