# 20.02.2019

### Course plan:
1. What is Object oriented programming?
2. Why is it useful?
3. Important things to consider: abstraction, inheritance, encapsulation, polymorphism.
4. Dynamic memory and pointers - the main tool we need for OOP.
5. Basic data structures - stack, queue, etc...
6. Finally we will be able to use string... but after we implement it!

### What are we going to talk about today?
1. Functions, member functions, methods;
2. Methods/member functions in a struct definition;
3. Constructors;

### Tasks
1. Define **struct Car** which have the following fields:
    -   brand name up to 127 symbols;
    -   model name up to 127 symbols;
    -   number of horse powers;
    -   weight;
    -   number of doors;
    -   average fuel consumption per 100 km;

2. Define methods for the following things:
    - given the distance in km and number of passengers, it returns the fuel required in liters. Every passenger, except the driver, increases the average consumption by 1 liter;
    - it prints all the information about the car;
    - given another car(say B), it return true if and only our car A is faster the the car B(the one passed as an argument). (compare the ratios (number of horses) / weight);

3. Make a constructor for the car with all the fields(afterwards can you define a variable with type that struct the way we used to do in the last course?);

4. Make a default constructor(which does not have parameters). It should set the default values of the fields.

5. Make an array of N cars, enter them from the console and print the slowest one and the most economical one(maybe they are the same? idk);
