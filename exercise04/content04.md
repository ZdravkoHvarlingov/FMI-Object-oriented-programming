# 20.03.2019

### What are we going to talk about today?
1. Class and its members(new memory space for each instance);
2. Class and dynamic memory(if there is **new** inside a class, there should be **delete** also!);
3. Copy constructors and operator= and their default behaviour;
4. Default constructor and destructor;
5. **Stack** with the new information;

### Tasks
1. Change the implementation of the **DynamicArray**, used in the previous exercises, so that it uses a dynamic memory instead of a static array:
    - *first, pass the size of the elements N in the constructor;*
    - *make a resize function, which changes the size N of the array. If the new N is larger - copy all the elements. If not - just not include the right most ones;*
    - *Once previous point is done you can set a default value of N. Once the amount of elements is N and you want to insert a new element - make the DynamicArray resize itself automatically(to size N*2 for example);*
    - *Make default constructor, copy constructor, operator= and destructor(because of the dynamic memory, used inside);*
3. Inform yourselves about **Singly linked list** and **Doubly linked list**. Think about a real representation. How would you store the data?