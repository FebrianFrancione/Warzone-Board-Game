#include "Orders.h";
using namespace std;

void f1() {
	OrdersList playerList = OrdersList();

	playerList.add(new Deploy());
	playerList.add(new Advance());
	playerList.add(new Bomb());
	playerList.add(new Blockade());
	playerList.add(new Airlift());
	playerList.add(new Negotiate());

	/*cout << playerList;

	playerList.move(0, 4);
	cout << playerList;

	playerList.move(3, 2);
	cout << playerList;

	playerList.deleteOrder(2);
	cout << playerList;

	playerList.deleteOrder(4);
	cout << playerList;*/
	for (int i = 0; i < 100; i++) {
		playerList.add(new Deploy());
	}
}

int main() {

	f1();

}