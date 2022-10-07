#include"app.h"
#include"../../include/nuclear/nuclear.h"
#include<stdio.h>


extern Application* getapp();

Application* app;

int main()
{
    int x=1;
    scanf("%d",&x);
    printf("%d \n", x);
    app = getapp();
    app->key(x);

    return 0;
}