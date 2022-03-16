#include<bits/stdc++.h>

using namespace std;



class Point{
public:
	int x;
	int y;

	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Compare{
public:
	bool operator()(Point p1, Point p2){
		if(p1.x==p2.x){
			return p1.y<p2.y;
		}
		return p1.x < p2.x;
	}
};

int countRect(vector<Point> points){

	set<Point, Compare> s;  //using comaparator so that we can look up in logn time

	for(Point p: points){
		s.insert(p);
	}

	int ans=0;

	for(auto it = s.begin();it!=prev(s.end());it++){
		for(auto jt = next(it);jt!=s.end();jt++){

			Point p1 = *it;
			Point p2 = *jt;

			if(p2.x==p1.x or p2.y == p1.y){
				continue;
			}

			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);

			if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
				ans+=1;
			}
		}
	}
	return ans/2;

}


int main(){

	int N;
	cin>>N;
	int x;
	int y;

	vector<Point> points;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		Point p(x,y);
		points.push_back(p);
	}

	cout<<countRect(points);

	return 0;
}

// input:
// 8
// 4 1
// 4 0
// 0 0
// 0 1
// 1 1
// 1 0
// 2 0
// 2 1