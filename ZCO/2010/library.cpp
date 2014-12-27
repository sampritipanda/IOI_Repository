// Library Committee

#include <stdio.h>
#include <set>

int main(){
	int N1, N2, N3;
	scanf("%d %d %d", &N1, &N2, &N3);
	int book;
	std::set<int> books;
	
	while(N1--){
		scanf("%d", &book);
		books.insert(book);
	}
	while(N2--){
		scanf("%d", &book);
		books.insert(book);
	}
	while(N3--){
		scanf("%d", &book);
		books.insert(book);
	}
	printf("%d\n", books.size());
}