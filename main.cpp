#include <iostream>
#include <string>
#include "SocialNetwork.h"
using namespace std;

int main() {

	SocialNetwork insta;
	//insta.addPerson("Valentin");
	insta.addPerson("0");
	insta.addPerson("1");
	insta.addPerson("2");
	insta.addPerson("3");
	insta.addPerson("4");
	insta.addPerson("5");
	insta.addPerson("6");
	//insta.delPerson("0");

	insta.addFriendship("0", "1");
	insta.addFriendship("1", "2");
	insta.addFriendship("2", "3");
	insta.addFriendship("3", "4");
	insta.addFriendship("4", "5");
	insta.addFriendship("5", "6");

	//insta.addFriendship("1", "4");

	insta.showThreeHandshakes();
	return 0;
}
