#include <stdio.h>
#include <iostream>
#include<math.h>
#include <graphics.h>

//Submitted By:Shreyansh Jain (17bce1018)

using namespace std;

const int xmax = 450;
const int xmin = 150;
const int ymax = 300;
const int ymin = 150;

float min(int x, int y){
	if(x < y){
		return x;
	}
	return y;
}

float max(int x, int y){
	if(x > y){
		return x;
	}
	return y;
}


void Liang_Barsky(int x1, int y1, int x2, int y2){
	int p[4], q[4], t[4], dx = x2 - x1, dy = y2 - y1;
	float tmin = 0, tmax = 1;
	p[0] = -(x2 - x1);
	p[1] = (x2 - x1);
	p[2] = -(y2 - y1);
	p[3] = (y2 - y1);
	q[0] = x1 - xmin;
	q[1] = xmax - x1;
	q[2] = y1 - ymin;
	q[3] = ymax - y1;
	
	for(int i = 0; i < 4; i++){
		if(p[i] < 0){
			tmin = max(tmin, (float)q[i]/(float)p[i]);
		}
		else if(p[i] > 0){
			tmax = min(tmax, (float)q[i]/(float)p[i]);
		}
		else{
			if(q[i] < 0){
				tmax = 0;
				tmin = 1;
				break;
			}
			}
		}

	//cout<<tmin<<" "<<tmax<<endl;
	if(tmin < tmax){
		cout<<ceil(x1 + tmin * dx)<<" "<<ceil(y1 + tmin * dy)<<" "<<floor(x1 + tmax * dx)<<" "<<floor(y1 + tmax * dy)<<endl;
		setcolor(RED);
		line(x1 + tmin * dx, y1 + tmin * dy, x1 + tmax * dx, y1 + tmax * dy);
	}
	else{
		cout<<"Line is outside the boudary";
		cout<<"\n";
	}
}
int main(){
	initwindow(640, 480, "H");
	rectangle(150,150,450,300);
	Liang_Barsky(100,400, 500, 100);
	Liang_Barsky(300,100, 300, 350);
	Liang_Barsky(200, 200, 400, 200);
	Liang_Barsky(40, 40, 40, 101);
	getch();
}
