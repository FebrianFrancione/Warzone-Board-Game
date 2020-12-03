#include "Cards.h"
#include "Map.h"
#include "Player.h"
using namespace std;

Cards::Cards() {
    //default card name
	type = "Default Card";
}

Cards::Cards(std::string t) {
	type = t;
}

//copy constructor
Cards::Cards(const Cards& obj) {
	// body of constructor
	cout << "copy constructor allocating ptr" << endl;
	type = obj.type; // copy the value using deep copy
}
//destructor
Cards::~Cards(void) {
	cout << "Freeing Card Memory" << endl;
}

//ostream overrride
std::ostream& operator<<(ostream& os, const Cards& data)
{
	os << data.type;
	return os;
}

BombCard::BombCard() {
	type = "Bomb Card ";
}


ReinforcementCard::ReinforcementCard() {
	type = "Reinforcement Card ";
}

BlockadeCard::BlockadeCard() {
	type = "Blockade Card ";
}


AirliftCard::AirliftCard() {
	type = "Airlift Card ";
}

DiplomacyCard::DiplomacyCard() {
	type = "Diplomacy Card ";
}

Deck::Deck() {

}

void Deck::generateDeck() {
    int max_deck_size = 52;
	//generating deck
	std::vector<Cards*> playing_deck;
	//push back one of every card classes to he Csrd vector
	while (playing_deck.size() <= max_deck_size) {

		playing_deck.push_back(new BombCard());

		playing_deck.push_back(new ReinforcementCard());

		playing_deck.push_back(new BlockadeCard());

		playing_deck.push_back(new DiplomacyCard());

		playing_deck.push_back(new AirliftCard());

	}
	while (playing_deck.size() > max_deck_size) {
		playing_deck.pop_back();
	}
	//set deck to playing-deck vector
	deck = playing_deck;
	cout << "Deck generated" << endl;
}

std::vector<Cards*> Deck::Draw(std::vector <Cards*> player_deck) {

	//this causes issues in the code
	int n = deck.size();
	cout << "n: " << n << endl;
    player_deck.push_back(deck[n-1]);

    cout << "Player deck size: " << player_deck.size() << endl;
    cout << "Player deck card: " << player_deck.at(0)->type << endl;
    deck.pop_back();

    for(int i = 50 ;i < deck.size(); i++){
        cout << deck[i]->type;
    }
    cout << endl << "Deck size: " << deck.size() << endl;
    return player_deck;
}

void Deck::shuffle(){
    //shuffle the card using time based random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(deck), deck.end(), std::default_random_engine(seed));

    cout <<endl<< "Deck has been shuffled! " << endl;

    for(int i = 50 ;i < deck.size(); i++){
        cout << deck[i]->type;
    }

    cout << endl << "_______________________________________________" << endl;
}

Deck::~Deck(void) {
	cout << "Freeing Deck Memory" << endl;
}

void Cards::Play(){
    cout << "Default play Card" << endl;
}
//
//Cards are missing the implementation and effects when called, basic essage showing that cards can be stored is shown instead.
//

//Bomb::Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr){
void BombCard::Play(){
/*otherTerr.setArmies(troopsRemain);

if (otherTerr.getArmies() < 0) {
otherTerr.setArmies(0);*/
cout << "Bomb Card played. Enemy Territory's army has been halved. If armies = 0, set territory armies to 0" << endl;
   /* cout << "\n" << "otherTerr.getName()" << " now has " << "otherTerr.getArmies()" << " army units.\n";*/
}

//Bomb::Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr){
void ReinforcementCard::Play(){
/*otherTerr.setArmies(troopsRemain);

if (otherTerr.getArmies() < 0) {
otherTerr.setArmies(0);*/
    cout << "Reinforcement Card played. Add 5 armies to current terrritory." << endl;
   /* cout << "\n" << "otherTerr.getName()" << " now has " << "otherTerr.getArmies()" << " army units.\n";*/
}

//Bomb::Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr){
void BlockadeCard::Play(){
/*otherTerr.setArmies(troopsRemain);

if (otherTerr.getArmies() < 0) {
otherTerr.setArmies(0);*/
    cout << "Blockade Card played. Sets the territory owner to neutral and multiply army by 3" << endl;
//    cout << "\n" << "otherTerr.getName()" << " now has " << "otherTerr.getArmies()" << " army units.\n";
}

//Bomb::Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr){
void AirliftCard::Play(){
/*otherTerr.setArmies(troopsRemain);

if (otherTerr.getArmies() < 0) {
otherTerr.setArmies(0);*/
    cout << "Airlift Card played. Transfers an amount of armies from current territory to target territory" << endl;
//    cout << "\n" << "otherTerr.getName()" << " now has " << "otherTerr.getArmies()" << " army units.\n";
}

//Bomb::Play(Player player1, Player player2, Territory thisTerr, Territory otherTerr){
void DiplomacyCard::Play(){
/*otherTerr.setArmies(troopsRemain);

if (otherTerr.getArmies() < 0) {
otherTerr.setArmies(0);*/
    cout << "Diplomacy Card played. Make chosen opposing player unable to attack current player." << endl;
//    cout << "\n" << "otherTerr.getName()" << " now has " << "otherTerr.getArmies()" << " army units.\n";
}
