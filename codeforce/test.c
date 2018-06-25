#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char buf[105];
    int n, fd;
    int source_file = open("/Users/huangjiaming/Documents/Algorithm/oj/codeforce/testfile.txt", O_RDONLY);
    if (source_file < 0) {
        perror("打开文件出错");
        exit(1);
    }
    char des_file_name[20] = "file2.txt";
    int des_file = open(des_file_name, O_WRONLY|O_CREAT, 0644);
    while ((n = read(source_file, buf, 105)) > 0){
        puts(buf);
        int z = write(des_file, buf, n);
        if (z < 0) {
            perror("写文件错误");
            exit(3);
        }
    }
    puts("复制文件testfile成功");
    close(source_file);
    return 0;
}