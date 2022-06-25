int elev_r (int x,int y) {
if (y==0) return 1;
else return x * elev_r(x,y-1);
}