## This programm was written for solving quadratic equations.

#### Starting the programm

make the MyMake file to compile the programm:
```
make -f MyMake
```

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

Special symbols `t` `h` `q` can be used instead of requested input for special output

 - `t` for running tests of the solving function;
 - `h` for showing help message;
 - `q` for exiting the programm.
 
#### Output

The output contains roots of the equation or a message telling there is no roots or infinite number of roots.
In case of negative discriminant output contains irrational roots.

#### Testing data

Testing data is contained in the file "testing_data.txt"
in following format:
```
[first coefficient] [second coefficient] [third coefficient] [nRoots] [first root] [second root]
```
