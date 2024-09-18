#include <stdio.h>
#include <string.h>
#define max 10000

typedef struct Stack {
    int t; // Đỉnh của stack
    int a[max];
} Stack;

// Khởi tạo Stack
void createStack(Stack &s) {
    s.t = -1;
}

// Phương thức isEmpty
bool isEmpty(Stack s) {
    return s.t == -1;
}

// Phương thức Push
bool pushStack(Stack &s, int x) {
    if (s.t >= max - 1) // Nếu đầy stack
        return false;
    else {
        s.t += 1;
        s.a[s.t] = x;
        return true;
    }
}

// Phương thức Pop
bool popStack(Stack &s, int &x) {
    if (isEmpty(s)) 
        return false;
    else {
        x = s.a[s.t];
        s.t -= 1;
        return true;
    }
}

// Phương thức Top
bool topStack(Stack &s, int &x) {
    if (isEmpty(s)) 
        return false;
    else {
        x = s.a[s.t];
        return true;
    }
}

int main() {
    Stack s;
    createStack(s);
    int n, k;
    scanf("%d%d", &n, &k);

    while (k--) {
        char str[100];
        gets(str);
        if (str == "PUSH") {
            int x;
            scanf("%d", &x);
            pushStack(s, x);
        } 
        else if (str == "POP") {
            int x;
            popStack(s, x);
        }
    }
    
    while (!isEmpty(s)) {
    	int x;
    	topStack(s, x);
    	popStack(s, x);
    	printf("%d", x);
	}
    
    return 0;
}

