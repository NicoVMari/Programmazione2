#include <stdio.h>
#include <stdlib.h>


struct punto {
    float x;
    float y;
};

struct puntoint {
    int x;
    int y;
}pint;

struct rect {
struct punto x;
struct punto y;
};

struct punto set(int a, int b) {
struct punto temp;
temp.x=a;
temp.y=b;
return(temp);
}

struct punto somma(struct punto a, struct punto b) {
a.x += b.x;
a.y += b.y;
return(a);
}


int main (int argc, char **argv) {
    struct punto apoint, bpoint, cpoint;
    struct punto p = {5, 10};

    
    
    
    pint.x= 7;
    pint.y =3;
    
    printf("%d %d %.2f %.2f\n",pint.x,pint.y,p.x,p.y);
    
    apoint = set(3,3);
    bpoint = set(4,4);
    cpoint = somma(apoint,bpoint);
    
    printf("%.2f %.2f\n",apoint.x,apoint.y);
    printf("%.2f %.2f\n",bpoint.x,bpoint.y);
    printf("%.2f %.2f\n",cpoint.x,cpoint.y);

    
    return 0;
    
}
