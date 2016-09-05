# Firework is a project I did for my CSE 250 - data structures class in Junior year at UB. 
Warning: This is strictly a C++ programming assignment. It has nothing to do with actual fireworks or explosives of any kind.
For this assignment you will be implementing a FireworkFactory class in C++. This class manages the construction, purchase, and sale of different colored fireworks. Since the shelf life of a firework is limited, they must be sold in FIFO order to keep the factories inventory as fresh as possible. In addition, there will be a time when each factory is shut down. In this event, it is important to properly dispose of its entire inventory of fireworks (delete the objects).


LIFO and FIFO Inventory (1 point)

Implement this pair of functions to receive and ship fireworks while maintaining a proper order.

void fireworkShipment(stack<Firework*>&);
You will receive a stack of firework pointers via fireworkShipment and you must add the pointers to the factory's inventory starting with the top of the stack.

void sellFireworks(stack<Firework*>&, int quantity);
In sellFireworks, fireworks must be shipped in FIFO order to keep the inventory as new as possible. whether fireworks were delivered or created, they must maintain this FIFO order.


Create and Destroy Fireworks (1 point)

Implement functions to manage the creation and destruction of fireworks. It is important that every firework that is created with new is destroyed with delete exactly once.

void metalShipment(stack<Metal>&);
Receive a shipment of metal which will be used to make new fireworks in the factory. Whenever the factory has 5 of any type of metal, it must immediately make a firework of the corresponding color and add it to the inventory. To make a firework, you must use the new keyword to create it dynamically on the heap and manage a pointer to the firework.

Metals and colors are both defined using enums.


Metal	Color
CalciumChloride	Orange
CopperSulfate	Green
CopperChloride	Blue
PotassiumChloride	Purple
~FireworkFactory();
Before destroying the factory you must properly dispose of all the fireworks in your inventory (On the heap). Do this by calling delete on each firework in inventory exactly once. Leaving fireworks on the heap (memory leak) will fail the test for this point. Deleting a firework more than once will cause a runtime error.


Sell Fireworks by Color (1 point)

void sellFireworks(stack<Firework*>&, int quantity, Color color);
Some customers want to purchase fireworks all of a specific color and are not satisfied with just taking the oldest fireworks in stock. The FIFO ordering must still be maintained as much as possible, but fireworks of the specified color can be sold before other colors if there is no other way to fulfil the order.

Be sure not to sell the same firework more than once with either of the sellFireworks functions. Fireworks that are sold are launched by the customers. If two customers launch (delete) the same firework it will cause a runtime error. You must also be careful not to delete a firework that has been sold.


O(1) Efficiency (1 point)

Complete all functionality using only O(1) runtime operations in all data structures that maintain inventory for the factory. Runtime is in terms of the size of the inventory.


This can be a difficult point to obtain and it is meant to be a challenge for students motivated enough to strive for an A in the course.
