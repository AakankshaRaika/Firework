#ifndef HW2_FIREWORKFACTORY_H
#define HW2_FIREWORKFACTORY_H

#include <stack>
#include <queue>
#include <vector>
#include <deque>

#include "Firework.h"

class FireworkFactory {

private:
	queue<Firework*> myInventoryQueue ; //my factory inventory FIFO
	stack<Firework*> customerInventoryStack;// customer inventory  LIFO
	queue<Firework*> ORANGE;
	queue<Firework*> BLUE;
	queue<Firework*> PURPLE;
	queue<Firework*> GREEN;
	queue<Firework*> myTempInventoryQueue;
	int green = 0;
	int blue = 0;
	int purple = 0;
	int orange = 0;
	int SOLDgreen = 0;
	int SOLDblue = 0;
	int SOLDpurple = 0;
	int SOLDorange = 0;
    // TODO: Track quantities of metals
    // TODO: Track finished fireworks in the proper order

public:
    FireworkFactory();

    // Point 1
    void fireworkShipment(stack<Firework*>&);
    void sellFireworks(stack<Firework*>&, int quantity);
    // Point 2
    void metalShipment(stack<Metal>&);
    ~FireworkFactory();
    // Point 3 for correctness, Point 4 for O(1) runtime
    void sellFireworks(stack<Firework*>&, int quantity, Color color);
};


#endif //HW2_FIREWORKFACTORY_H
