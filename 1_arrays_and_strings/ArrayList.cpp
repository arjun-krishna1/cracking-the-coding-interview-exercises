#include <stdio.h>


class ArrayList {
	public:
		ArrayList(int size1) {
			this->size = size1;
			this->data = new int[size];
		}

		void print() {
			printf("%d\n", this->size);
		}
	private:
		int size;
		int *data;
};

int main() {
	ArrayList arr(10);
	arr.print();
	printf("Hello World!\n");
	return 0;
}
