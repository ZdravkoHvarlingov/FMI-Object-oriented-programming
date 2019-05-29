# 29.05.2019

### What are we going to talk about today?
1. Friend functions and classes
    -   have access to all private data of a class;
    -   are NOT inherited, if Func() is a friend function of class A and B is derived class, Func() is not a friend function of B;
    -   if A is a friend class of B, B is not a friend class of A;
    -   should NOT be overused;
    -   why are they useful? mostly in operator overloading and testing. 
    -   See https://www.quora.com/Why-we-use-friend-function-in-c++
    -   https://www.geeksforgeeks.org/g-fact-34/
    -   https://www.geeksforgeeks.org/friend-class-function-cpp/

2. Namespaces
3. Using
    -   type alias (typedef)
    -   namespaces
    -   bringing base class method into scope, because if a derived class declares a method with the same name as a method defined by the base class, the derived class method hides the base class one.

