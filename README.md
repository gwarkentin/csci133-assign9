We haven't yet been taught Stacks or Queues in class. Since we are running out of time in this class and there's still supposed to be assignments after this as well as an exam I took it upon myself to figure it out. Initially I planned to do a Queue class and may still do so. If I were to I would probably use a linked list instead of an array but we had this limit of 10 train cars so I don't really see the point.




Assignment Details:
Create a new C++ program, RailcarSwitcher, that simulates a railroad switching station.

--------------------------   --------------------------
Input -->                 \ /                Output -->
                           |
-----------------------         -----------------------
                       |       |  
                       |   Y   |
                       |   a   |
                       |   r   |
                       |   d   |
                       |       |

Railroad engineers often have to switch cars on the trains that they manage. Because of the lack of maneuverability of these railcars (and the fact that they can only move on tracks), getting the correct cars off of one train and on to another can be problematic. Using the above diagram as a guide, cars can enter from the left and are sent to the output on the right by routing through the yard "stack". Each car can be brought into the stack and removed at any time.

The RailcarSwitcher program will aid railroad engineers in determining the ordering of outgoing railcars. Design the program with the following specifications:

The RailcarSwitcher class should have the following member variables:
string inSequence: The railcars to evaluate as the incoming sequence.
string outSequence: The target sequence that the program will attempt to build.
int maxCars = 10: Largest number of cars that the entire program can accept at any one time.
inSequence and outSequence should be obtained from the user.
A queue to represent the original car arrangement.
A stack to represent the yard.
A second queue to represent the output arrangement.
push, pop, and peek methods to add, remove, and scan items from the stack.
The program should work through the input queue until either the output sequence is created in its entirety or the program cannot continue to build the desired output.

Example:
An input of: 1 2 3 4 can be mapped to an output of 4 3 2 1 using the sequence: push push push push pop pop pop pop

But: An input of: 1 2 3 4 cannot be mapped to an output of 4 2 3 1

The proceeding examples would produce the output:

Attempting to map the input 1 2 3 4 to the output 4 3 2 1 ...
     The sequence of moves are: push push push push pop pop pop pop

Attempting to map the input 1 2 3 4 to the output 4 2 3 1 ...
     The sequence of moves are: push push push push pop
     The input cannot be mapped to the output.

Deliverables. Submit your .cpp source code file in a folder named assign10 in your csci133 folder. Make sure your compiled file name is assign10.
