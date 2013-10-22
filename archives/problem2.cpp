/*
title: problem 2
author: Hyunjin Chung
date: April 11th, 2013

finds minimum packing box size for input rectangles

*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct _rect{
	int xinit, yinit;
	int width, height;
	int rotate;
}rect; 

int bigwidth;
int bigheight;


int main(){
	int N;
	string line;
	int i=0;
	int sum =0;
	int max =0;
	int temp =0;

	scanf("%d", &N);
	//cout << "read first line : " << N << endl;	

	rect * rectarr;
	rectarr = (rect*)malloc(sizeof(rect)*N);
	
	for(i=0; i<N; i++){
		scanf("%d %d", &rectarr[i].width, &rectarr[i].height);
		//cout << "stored width: " << rectarr[i].width << "stored height" << rectarr[i].height << endl;
		rectarr[i].rotate = 0;
	}

	//main algorithm:
	for(i=0;i<N;i++) {
		if(rectarr[i].width > rectarr[i].height) {
			temp = rectarr[i].width;
			rectarr[i].width = rectarr[i].height;
			rectarr[i].height = temp;

			rectarr[i].rotate = 1;
		}
	}
	for(i=0;i<N;i++){
		sum = sum + rectarr[i].width;
		rectarr[i].xinit = sum;
		rectarr[i].yinit = 0;
	}

	max = rectarr[0].height; 

	for(i=0;i<N;i++) if(rectarr[i].height > max) max = rectarr[i].height;

	bigwidth = sum;
	bigheight = max;


	//print result
	cout << bigwidth << " " << bigheight << endl;
	for(i=0;i<N;i++)
		cout << rectarr[i].xinit << " " << rectarr[i].yinit << " " <<rectarr[i].rotate <<  endl;
	free(rectarr);
	scanf("%d", &N);
	return 0;

}