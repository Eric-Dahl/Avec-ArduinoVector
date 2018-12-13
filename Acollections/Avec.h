#ifndef ARDUINO_VECTOR_H
#define ARDUINO_VECTOR_H

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#ifndef Arduino_h
#include "Arduino.h"
#endif

template<class T, byte _size = 10>
class Avec{
private:
	T collection[_size];
	byte effective_size;

	void one_step_forward(byte from);	//moves all items after arg.from 1 step forward

public:
    static const byte MAX_SIZE = _size - 1;
	//ctor
	Avec() : effective_size(0) {}
	Avec(const Avec &rval) : collection(rval.get()), effective_size(rval.size()) {}
	//~Avec(){ free(collection); }
	/*Avec& operator =(const Avec& rval) {
		return *this;
	}*/
	const T& operator[](byte index) const {
		return collection[index];
	}

	void add(T item);		//adds item to collection and increases effective_size by 1
	void remove(byte pos);		//removes the item at position pos
	void clear(){ effective_size = 0; }		//"clears" the vector

	T *get(){ return collection; }
	T *get(byte pos){ return (&collection[pos]); }	//returns the item at position pos


	byte size() { return effective_size; }	//returns the effective size of the array
	bool isFull() const { return (effective_size - 1 == MAX_SIZE); }		//all the "empty" items are filled
	bool isEmpty() const { return (effective_size <= 0 ); }
};

//#include "Avec.cpp"	//otherwise there will be a linking error  #workaround-include this cpp in your client file(not just the header)

#endif //ARDUINO_VECTOR_H
