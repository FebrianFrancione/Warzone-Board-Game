#include "Cards.cpp"


int main() {

	Card card("bomb");
	Card card("Airlift");
	Card card("diplomacy");
	Card card("reinforcement");
	Card card("bomb");


	Hand cards_in_hand;
	cards_in_hand.hand.push_back(card);
	for (int i = 0; i < sizeof(cards_in_hand); i++) {

	}

}

