#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	char buff[10];
	int fd,val; // fd: ファイル記述子
	fd = open("test.txt", O_RDONLY); // 最初に必ずファイルを開く
	val = fd;
	if(val < 0){
		perror("こめんと:");
		exit(1);
	}
	val = read(fd, buff, 10); // ファイルからデータを読む
	if(val < 0){
		perror("コメント:");
		exit(1);
	}
	val = write(1, buff, 10); // ファイルにデータを書く
	if(val < 0){
		perror("コメント:");
		exit(1);
	}
	val = close(fd); // 使い終わったらファイルを閉じる
	if(val < 0){
		perror("コメント:");
		exit(1);
	}
}
