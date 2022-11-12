									Real Estate Agency

I created 3 classes (Locuinta(place to live), Apartament(apartment), Casa(house)). I used inheritance (classes Apartment and House are derived from Place class).

All of the 3 classes have set and get functions, constructors, destructors, the overloaded = operator.

The base class contains a pure virtual function for calculating rent. Attributes suprafata_utila(usable surface) and discount are protected, because we need access when we are defining the virtual function in the derived classes.

The read and write functions are virtual, because we are using pointers.

Classes Apartment and House have a static variable to keep track of the number of objects created and static function which returns this variable.

Interactive Menu

We put objects of type House and Apartment into a vector of Place pointers(upcasting).

First option: It helps pick an apartment based on preferences. We create a vector of Apartment objects. Before doing that we downcast, so that we have a pointer to an Apartment object.
We check the downcast in a try-catch block.

Second Option: Same as option one, but instead of an apartment we are looking for a house.

Third Option: Exits the interactive menu.

Fourth Option: Lists the Places and their rent.
