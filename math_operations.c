#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

// Basit bir fonksiyon: iki string'in eşit olmadığını kontrol et


// Basit bir fonksiyon: iki sayının çarpımını döndür
int multiply(int a, int b) {

    // Socket açma işlemi
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket açma hatası");
        // exit(EXIT_FAILURE);
    }

    // Socket kapatma işlemi
    close(sockfd);
    
    return a * b;
}
