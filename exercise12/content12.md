# 15.05.2019

### What are we going to talk about today?
1. Test preparation:
    -   inheritance
    -   polymorphism
    -   templates

### Exercise
We want to make a collection of classes having the following requirements:
1. We have a Server, which has a single method:
    -   string **ProcessRequest(string msg)** - accepts message, processes it and returns an answer;
2. There are severals types of servers which process the request in a different way
    -   a **DBTextServer** - accepts the message and stores it. The answer is whether the message was saved or not;
    -   a **MathServer** - accepts a message in the format "**number1 number2**", where **number1** is a non-negative integer(if the format is not as expected the answer announces it). The answer is the sum of the numbers(**AdditionServer**) or their product(**MultiplicationServer**);

3. There is a class **Network** with the following features:
    -   stores a collection of servers of different types;
    -   stores a collection of clients, every client has a name and age;
    -   every client and every server has a specific address(id) which is a positive number;
    -   every client can send a message to a specific server(request);
    -   stores information about all the sent messages;

4. The Network class has the following methods:
    - int **AddServer(<NeededType> server)** - adds a server and returns its id;
    - int **AddClient(string name, int age)** - adds a client and returns its id;
    - string **SendMessage(int clientId, int serverId, string message)** - sends a message to the server with the given ID from the client with the given ID, stores the information and the reply and returns the reply;
    - string **SendMessageToAll(int clientId, string message)** - that clients sends message to all the servers, stores all the information and returns all the responses into a single string(every response on a new line);
    - **vector<string>(or string array) GetAllInformation()** - returns all the information about the requests and responses;

5. *You can use string and vector;*

