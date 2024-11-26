#include <cstdio>
#include <cstring>
#include <cstdlib>

struct Memory{
	char buffer[8]; // 缓冲区大小
	int data = 0; // 一个秘密值
};

bool check_secret(int secret){
	return secret == 97;
}

int main() {
    Memory mem;
    int secret_value=0;
    
    //To simulate unsafe gets
    char* ptr = mem.buffer;
    int ch;
    while ((ch = getchar()) != '\n') {
        *ptr++ = ch; // 写入缓冲区
    }
    *ptr = '\0';
    
    secret_value=mem.data+32;
    // 检查 secret_value 的值
    if (check_secret(secret_value)) {
    //if (mem.secret_value == 97) {
        printf("You've discovered the secret value!\n");
    } else {
        printf("Secret value: %d\n", secret_value);
    }
}

