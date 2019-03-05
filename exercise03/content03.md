# 06.03.2019

### What are we going to talk about today?
1. Can we place variable in a class which has the same type as the class?
    - Is there a workaround?
2. Overloading operators
3. Our DynamicArray update and new features

### Tasks
1. Implement a data structure class which represents a stack. It has to have the following methods:
    - Pop() - it returns the last element added in the stack and removes it from it.
    - Push(element) - it adds element at the top of the stack
    - Top() - it returns the last element pushed in the stack but DOES NOT remove it.
    - Empty() - it returns if the stack has elements or not.
    - Size() - it returns the number of elements inside.
    - TIP: Use the same approach as the DynamicArray, use static array inside the class and set a limit for the number of elements - for example 1000.
2. Brackets with stack: given a char array which has brackets return true if the brackets are positioned correctly
    - Example: (()) is true, (()()()) is true, )() is false, )()( is false, ((()) is false, etc...
    - You can use the stack implemented in the first stack.
3. Person inside Person: Define a Person class which has the following fields:
    - name
    - family name
    - age
    - gender
    - Person* children[3] - maximum 3 children
4. The class should have the proper constructors, get and set methods, and at least the following methods:
    - operator == which compares two Persons;
    - AddChild method;

###BONUS TASKS: 
1. Given the root of the parents tree(Person object which has child but no parents) make a function which prints all the Person objects which have no children.
2. Solve the task with the brackets allowing the text to have different kinds of brackets( '(', '{', '[' ), for example:
    - ({}()[{}]) is valid;
    - {[()]} is valid;
    - {()()[]} is valid;
    - {()[] is not valid;
    - {([)]} is not valid;