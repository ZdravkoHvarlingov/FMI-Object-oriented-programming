# 17.04.2019

### What are we going to talk about today?
1. **public, protected, private** in two contexts:
    -   variables;
    -   inheritance;

2. Some information about exceptions:
    -   what are they doing?
    -   exception vs assert (input that can NOT be handled vs program bugs);
    -   throwing exceptions;
    -   catching exceptions;

3. Operator=, copy constructor and cast from a child to its parent:
    -   what happens?
    -   Do we lose information?

4. Virtual methods, Pure virtual methods(abstract methods) and abstract classes.


### Tasks
1. We want to make a veterinary, which has different animals: cats, dogs, horses.
    -   every animal can make a sound(just cout it) - bark, meoww, muuu, etc
    -   we want to be able to add animal inside;
    -   delete an animal which is of a specific type(cat, dog, etc..) and has specific name;
    -   MakeNoisesSymphony method which makes all the animals say their sound;
