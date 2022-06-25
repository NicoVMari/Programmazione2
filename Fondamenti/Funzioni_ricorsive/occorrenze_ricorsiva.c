void dividix(int A[], int n, int x) {
if (n>=0) {
if ((A[n] % x) == 0) A[n]=A[n]/x;
dividix(A,n-1,x);
}
}