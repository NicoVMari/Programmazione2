void printlis_rt(LINK lis) {
if (lis != NULL) {
printf(">>>> %d\n"
, lis->d); 
printlis_rt(lis->next);
}
}