## This programm was written for solving quadratic equations.

#### Building the programm

Clone the programm files from github:
```
git clone https://github.com/alisavi/catcatcat.git
```
In the directory where git repository was cloned create a directory for *.o files:
```
mkdir obj
```
make the MyMake file to compile the programm:
```
make -f MyMake
```
#### Starting the programm

run the QuadEqu to start solving:
```
./Quadequ
```
you can add one of the two flags `-help`   `-test` in the command line
to receive help or run tests straitly after starting the programm

#### User's input

The programm requests user to input three coefficients a, b and c which would be used in solving equation

*ax^2 + bx + c = 0*.

After solving programm gives user the opportunity to solve another equation by printing `Y` as the response to the relevant offer.

Special symbols `t` `h` `q` can be used instead of requested input as special commands

 - `t` runs tests of the solving function;
 - `h` shows help message;
 - `q` exits the programm.
 
#### Output

The output contains roots of the equation or a message telling there is no roots or infinite number of roots.
In case of negative discriminant output contains complex roots.

#### Testing data

Testing data is contained in the file "testing_data.txt"
in following format:
```
[first coefficient] [second coefficient] [third coefficient] [nRoots] [first root] [second root]
```
Where `nRoots` is
 - `2` for two rational roots;
 - `1` for one rational root;
 - `0` for no roots;
 - `-1` for infinite number of roots;
 - `-2` for two complex roots.
Unused roots contain `0`, in other cases x1 > x2.
For example, we have an equation
```
0x^2 + 1x + 1 = 0;
x = -1.
```
Then in the file with data is written
```
0 1 1 1 -1 0
```
