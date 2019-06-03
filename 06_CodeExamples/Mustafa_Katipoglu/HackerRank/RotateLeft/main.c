
/* Hackerrank Array Left Rotation Challenge */

void rotateLeft(int* a, int n){
    int temp = *a;
    memmove(a,a+1, sizeof(int) * (n-1) );
    *(a+n-1) = temp;
}
