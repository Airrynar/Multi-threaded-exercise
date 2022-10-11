#include <bits/stdc++.h>
#include <thread>
#include <mutex>
//#include <semaphore.h>
using namespace std;

int size=19;
vector<double>v;int tot=1000;
void init(){
	for (int i=1;i<=tot;i++)v.push_back(i);
}
void feedData(double *buffer,int size){
	for (int i=0;i<size;i++)cout<<buffer[i]<<" ";cout<<endl;
}
int cnt=0;
int loadData(double *buffer,int size){
	size=min(size,int(v.size()-cnt));
	for (int i=0;i<size;i++)buffer[i]=v[cnt++];
	return size;
}

int S1,S2;
double *p1,*p2;
atomic<int>f;
void feed(){
	feedData(p1,S1);
	f--;
}
void load(){
	S2=loadData(p2,size);
	f--;
}
void run(){
	p1=new double[size];
	p2=new double[size];
	S1=loadData(p1,size);
	while (1){
		f=2;
		thread th1(load);
		thread th2(feed);
		th1.join();
		th2.join();
		while(f);
		for(int i=0;i<size;i++)p1[i]=p2[i];S1=S2;
		if (S1==0)break;
	}
	delete p1;delete p2;
}
int main(){
	init();
	run();
	return 0;
}
