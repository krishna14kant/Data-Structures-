#include <iostream>
using namespace std; //bellabeen
int main () {
	bool terurut;
	
	//input data
	int a;
	cout<<"banyak integer: "; cin>>a;
	int b[a];
	for (int c=0;c<a;c++) {
		cout<<"aray ke-"<<c<<": ";cin>>b[c];}
		cout<<"melakukan proses bubble sort!\n\n";
		
		//prose sorting
		for (int c=0;c<a;c++) {
			terurut=false; //beri tanda bahwa data belum terurut
			
			for (int d=a-a;d>c;d--) {
				//untuk menampilkan proses sorting, hilangkan komentar
				for (int e=0;e<a;e++) {
					cout<<b[e]<<", ";}
					cout<<endl;
					
					//proses pertukaran data
					if (b[d]<b[d-1]) {
						int tmp = b[d];
						b[d] = b[d-1];
						b[d-1] = tmp;
						terurut = true;}}
						
						if (!terurut)
							break;} //Jika data terurut proses berhenti
							
							for (int e=0;e<a;e++) {
								cout<<b[e]<<", ";}
								cout<<endl;
								return 0;}
	
