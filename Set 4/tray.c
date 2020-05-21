#include<stdio.h>

int min_unused_area(int x,int y,int a,int b){
	int area= x*y;
	int first =(x/a)*(y/b);
	int second = (x/b)*(y/a);
	if(first>second){
		return area-first*a*b;
	}
	return area-second*a*b;
}

double min_perimeter(int a,int b){
	int i;
	double x = a*1.0;
	double y = b*1.0;
	for(i=0;i<3;i++){
		if(x>y)x/=2.0;
		else y/=2.0;
	}
	return 2.0*(x+y);
}

int main(void) {   
	int trayHeight, trayWidth, slabHeight, slabWidth;
	printf("Enter size of tray: ");
	scanf("%d %d",&trayHeight,&trayWidth);
	printf("Enter size of slab: ");
	scanf("%d %d",&slabHeight,&slabWidth);
	int minArea = min_unused_area(trayHeight,trayWidth,slabHeight,slabWidth);
	printf("Minimum unused area = %d\n",minArea);
	double minPer=min_perimeter(trayHeight,trayWidth);
	printf("Minimum perimeter after folding = %.2lf\n", minPer);     
	return 0; 
}
