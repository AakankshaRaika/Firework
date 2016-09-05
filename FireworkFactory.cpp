#include "FireworkFactory.h"
#include "Firework.h"
#include <iostream>


FireworkFactory::FireworkFactory() {}

// Receive a stack of Firework pointers and add them to the factories inventory. Fireworks must be sold in the order
// that they are popped off the stack (The top of the stack is the oldest firework).
//I will be using queue for inventory FIFO
//Shipment is stack which is LIFO

void FireworkFactory::fireworkShipment(stack<Firework*>& fireworkShipment) {
	//should be right
	while (!fireworkShipment.empty()) {
		myInventoryQueue.push(fireworkShipment.top());
		Color color = fireworkShipment.top()->getColor();
		switch (color) {
		case (Green) :
			GREEN.push(new Firework(Green));
			break;
		case(Blue) :
			BLUE.push(new Firework(Blue));
			break;
		case(Purple) :
			PURPLE.push(new Firework(Purple));
			break;
		case(Orange) :
			ORANGE.push(new Firework(Orange));
			break;

		}
		fireworkShipment.pop();
	}
}

// Sell quantity fireworks by pushing them onto the customerStack with the oldest fireworks being sold first (FIFO).
void FireworkFactory::sellFireworks(stack<Firework*>& customerStack, int quantity) {
	//should be right
	for (int i = 0; i < quantity; i++) {
		Color color = myInventoryQueue.front()->getColor();
		if (Green == color && SOLDgreen > 0) {
			myInventoryQueue.pop();
			SOLDgreen--;
		}
		else if (Blue == color  && SOLDblue > 0) {
			myInventoryQueue.pop();
			SOLDblue--;
		}
		else if (Orange == color  && SOLDorange > 0) {
			myInventoryQueue.pop();
			SOLDorange--;
		}
		else if (Purple == color  && SOLDpurple > 0) {
			myInventoryQueue.pop();
			SOLDpurple--;
		}
		customerStack.push(myInventoryQueue.front());
		myInventoryQueue.pop();
	}
}

//RECIVED ! POINT
// Before destroying the factory you must properly dispose of all the fireworks in your inventory (On the heap).

FireworkFactory::~FireworkFactory() {
	//not right but should be right 
	while (!myInventoryQueue.empty()) {
		delete myInventoryQueue.front();
		myInventoryQueue.pop();

	}
	while (!GREEN.empty()) {
		delete GREEN.front();
		GREEN.pop();

	}
	while (!BLUE.empty()) {
		delete BLUE.front();
		BLUE.pop();

	}
	while (!ORANGE.empty()) {
		delete ORANGE.front();
		ORANGE.pop();

	}
	while (!PURPLE.empty()) {
		delete PURPLE.front();
		PURPLE.pop();

	}
}

// Receive a shipment of metal which will be used to make new fireworks in the factory. Whenever the factory has 5 of
// any type of metal it must immediately make a firework of the corresponding color and add it to the inventory.
// To make a firework, you must use the new keyword to create it dynamically on the heap and manage a pointer to
// the firework.
void FireworkFactory::metalShipment(stack<Metal>& metalShipment) {
	while (!metalShipment.empty()) {
		Metal myMetal = metalShipment.top();
		Color mycolor = metalToColor(myMetal);
		switch (myMetal) {
		case (CalciumChloride) :
			if (orange < 5) {
				orange++;
				if (orange == 5) {
					Firework* newFirework = new Firework(mycolor);
					myInventoryQueue.push(newFirework);
					ORANGE.push(new Firework(Orange));
					orange = 0;
				}
			}
			break;// 0: Orange
		case (CopperSulfate) :
			if (green < 5) {
				green++;
				if (green == 5) {
					Firework* newFirework = new Firework(mycolor);
					myInventoryQueue.push(newFirework);
					GREEN.push(new Firework(Green));
					green = 0;
				}
			}
		       break;// 1: Green
		case (CopperChloride):
			if (blue < 5) {
				blue++;
				if (blue == 5) {
					Firework* newFirework = new Firework(mycolor);
					myInventoryQueue.push(newFirework);
					BLUE.push(new Firework(Blue));
					blue = 0;
				}
			}
				break;// 2: Blue
		case (PotassiumChloride) :
			if (purple < 5) {
				purple++;
				if (purple == 5) {
					Firework* newFirework = new Firework(mycolor);
					myInventoryQueue.push(newFirework);
					PURPLE.push(new Firework(Purple));
					purple = 0;
				}
			}
		       break;// 3: Purple)
		} 
		metalShipment.pop();
	}
}


// A customer is purchasing quantity fireworks, but they must all be of the color specified by the customer. The order
// in which the fireworks are sold must be maintained (FIFO), but fireworks of the specified color can be sold before
// other colors if there is no other way to fulfil the order. Be sure not to sell the same firework more than once with
// either of the sellFireworks functions.
//
// For the efficient point of this assignment, this function must run in O(quantity) time. If only 1 firework is being
// purchased, the runtime must be O(1) regardless of where the firework to be sold is in the inventory.
void FireworkFactory::sellFireworks(stack<Firework*>& customerStack, int quantity, Color color) {
	int i = 0;
	while (i < quantity) {
		
			if (Green == color) {
				customerStack.push(GREEN.front());
				GREEN.pop();
				SOLDgreen++;
			}
		
			 if (Blue == color) {
				customerStack.push(BLUE.front());
				BLUE.pop();
				SOLDblue++;

			}
		
			 if (Orange == color) {
				customerStack.push(ORANGE.front());
				ORANGE.pop();
				SOLDorange++;

			}
		
			 if (Purple == color) {
				customerStack.push(PURPLE.front());
				PURPLE.pop();
				SOLDpurple++;

			}
			 i = i + 1;
		}

	}


	

