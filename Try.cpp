#include <iostream>
#include <random>
using namespace std;

class Block {
private:
	int block[4]{0};
	int index{ 0 };
	Block* next = nullptr, *prev = nullptr;
public:
	Block() {
	}

	Block(int data) {
		block[index++] = data;
	}

	bool write(int data) {
		if (index >= 4)
			return false;

		block[index++] = data;

		return true;		
	}

	int* getNum() {
		return block;
	}

	void printBlock() {
		for (int i = 0; i < index; ++i) {
			cout << i + 1 << " : " << block[i] << endl;
		}
	}

	void setNextPtr(Block* ptr) {
		next = ptr;
	}

	Block* getNextPtr() {
		return next;
	}

	void setPrevPtr(Block* ptr) {
		prev = ptr;
	}
};

int main(int argc, char* argv[])
{
	Block* root;
	int num = rand() % 5 + 1;

	int data = 1;

	root = new Block(data);
	--num;

	Block* now = root;

	long amount = 100;

	// cout << "데이터 생성 중\n";
	while (--amount) {
		for (; num > 0; --num) {
			if (now->write(data))
				continue;
			else {
				Block* node = new Block(data);
				node->setPrevPtr(now);
				now->setNextPtr(node);

				now = node;
			}
		}
		num = rand() % 5 + 1;
		++data;
	}

	int n = 1;
	for (Block* ptr = root; ptr != nullptr; ptr = ptr->getNextPtr()) {
		cout << n++ << "번 블럭\n";
		ptr->printBlock();
	}

}