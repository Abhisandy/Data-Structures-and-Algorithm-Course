#include<bits/stdc++.h>

using namespace std; 

class Cars{
public:
	string id;
	int x, y;
	Cars(string id, int x, int y){
		this->id = id;
		this->x = x;
		this->y = y;
	}

	int dist() const{
		return x*x + y*y;
	}

};

class CarCompare{
public:
	bool operator()(const Cars A, const Cars B){
		return A.dist() < B.dist();   //max heap
	}
};

void printNearestCar(vector<Cars> cars, int k){

	priority_queue<Cars, vector<Cars>, CarCompare> max_heap(cars.begin(), cars.begin()+k);

	for(int i=k; i<cars.size(); i++){

		auto car = cars[i];
		if( car.dist() < max_heap.top().dist() ){
			max_heap.pop();
			max_heap.push(car);
		}
	}

	vector<Cars> output;
	while(!max_heap.empty()){
		 output.push_back(max_heap.top());
		 max_heap.pop();
	}
	reverse(output.begin(), output.end());

	for(auto car: output){
		cout<<car.id<<endl;
	}
	return;
}

int main(){

	vector<Cars> cars; 
	int N, K;
	cin>>N>>K;

	string id;
	int x, y;
	for(int i=0; i<N; i++){
		cin>>id>>x>>y;
		Cars car(id,x,y);
		cars.push_back(car);
	}

	printNearestCar(cars, K);
	return 0;
}


//input
// 5 3
// C1 1 1
// C2 2 1
// C3 3 2
// C4 0 1
// C5 2 3