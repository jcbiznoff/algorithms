#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> vecPst;
vector<int> vecPend;
vector<int> vecCtik;
vector<double> vecCPU;
vector<int> secVec;
vector< pair<string,int> > pairPName;

int totSize =0;
int totSec = 0;

void insertVals(string& line, int idx){
	string buf;
	stringstream ss(line);
	int i=0;
	while (getline(ss,buf,' ')) {
		switch(i){
		case 0:
			pairPName.push_back(make_pair(buf,idx));
			break;
		case 1:
			vecPst.push_back(atoi(buf.c_str())); break;
		case 2:
			vecPend.push_back(atoi(buf.c_str())); break;
		case 3:
			vecCtik.push_back(atoi(buf.c_str())); break;
		}
		//cout << buf << " " << i << endl;
		i++;
	}	
}

void sortNames(){
	sort(pairPName.begin(), pairPName.end());
	
	int i=0;
	for (i=0;i<totSize;i++){
		if(vecCPU.at(pairPName.at(i).second) !=0 )
			cout << pairPName.at(i).first << " "<< vecCPU.at(pairPName.at(i).second) <<"\%" << endl;
	}
	while(!vecCPU.empty()){
		vecCPU.pop_back();
	}
}

void calcCPU(){
	int i,j =0;
	double densum =0.0;
	double tempcpu = 0.0;
	double tempnum =0.0;

	for(j=0; j<totSec;j++){
		densum =0.0;
		tempcpu = 0.0;
		tempnum =0.0;
		//it = vecCPU.begin();

		for (i=0; i<totSize ;i++){
			if(secVec.at(j) >= vecPst.at(i) && secVec.at(j) < vecPend.at(i))
				densum = densum + vecCtik.at(i)/(vecPend.at(i) - vecPst.at(i));
		}
		//cout << "densum "<< densum << endl;
		for (i=0; i<totSize ;i++){
			tempcpu = 0.0;
			tempnum =0.0;
			if(secVec.at(j) >= vecPst.at(i) && secVec.at(j) < vecPend.at(i)){
				tempnum = vecCtik.at(i)/(vecPend.at(i) - vecPst.at(i));
			}
			tempcpu =  ceil(tempnum/densum *1000)/10;
			//cout << "tempcpu "<< tempcpu << endl;
			vecCPU.push_back(tempcpu);
			
		}
		cout << secVec.at(j) << endl;
		sortNames();
	}
}

int main() {
	int i, tempnum;
	string line;
	int inputline;
	while (true){
		i=0;
		tempnum=0;
		inputline = 1;
		totSize =0; totSec = 0;
		//Read line 1
		while ( getline(cin, line) ){
			if(line.empty()) break;
			if (inputline == 1){
				string buf;
				stringstream ss(line);
				while (ss>>buf) {
					secVec.push_back(atoi(buf.c_str()));
					totSec++;
				}
				inputline++;
			}else{
				//cout << "success" << endl;
				insertVals(line, totSize);
				totSize++;
			}
		}
		calcCPU();

		//empty vectors 
		while(!vecPst.empty()){
			vecPst.pop_back();
		}
		while(!vecPend.empty()){
			vecPend.pop_back();
		}
		while(!vecCtik.empty()){
			vecCtik.pop_back();
		}
		while(!vecCPU.empty()){
			vecCPU.pop_back();
		}
		while(!secVec.empty()){
			secVec.pop_back();
		}
		while(!pairPName.empty()){
			pairPName.pop_back();
		}
		//cout << "calc done" << endl;
	}
	//getline(cin,line);
	return 0;
}