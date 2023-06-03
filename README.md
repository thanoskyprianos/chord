# Question7 | Chord

## Table of contents
* [Description](#description)
* [How the program works](#how-the-program-works)
* [Other notes](#other-notes)
* [Directories](#directories)
* [Compile and Run](#compile-and-run)
* [Example outputs](#example-outputs)

## Description
The files in this directory try to simulate a distributed hash table using the Chord protocol.

## How the program works
* To simulate multiple clients in one computer I decided to use a seperate hash table for the entire network. The hash table stores the nodes and by hashing an IP address represented by a string, we get the client we want as a `nodeType` object. Every `nodeType` contains its IP address, its finger table and as its personal hash table that is used to store our `(key, value)` data pairs.
* Both hash tables use seperate chaining to handle collisions.
* As the Chord paper suggests, both the IP addresses and the keys are hashed using SHA-1. The `MAXNODENUMBER` macro is set to 256 so the hash function returns the first byte of the hash as an integer.
* All nodes are being initialized with a random IP address using the `random_ip()` function. In the process of initialization, every node is sorted into a temporary array. This is done to make the finger table creation easier.

## Other notes
* The directory contains multiple sub-directories which contain many implementations of the data structures used, i.e. hash table, linked list. As mentioned above the hash table used for the network is a seperate one from the one used by the nodes. As such there are two implementations of both the hash table and the linked list. The ones used by the nodes are in the `client` directory and the ones used by the chord protocol are in the `ring` directory.
* Even though it was not required, I implemented many unit tests for the functions used, in order to make sure that everything works as intended.

## Directories
* **acutest** : Acutest library used in unit tests.
* **dht**: Contains implementations for the hash tables, the linked lists and the nodeType object.
* **utils**: Contains utility functions.
* **main.c**: The main program.

## Compile and Run
* **Compile**: `make main`
* **Run**: `./main`
* **Test**: `make test`
* **Clean**: `make clean`

Alternatively you can compile and run the program using `make run` which also deletes object and executable files after execution.

## Example outputs
```
$ make run
Main menu
0. Exit
1. Client selection
Your choice: 1
```
*screen is cleared*
```
Server selection (Page 1/16)
1 . 103.198.105.115
2 . 81.255.74.236
3 . 41.205.186.171
4 . 242.251.227.70
5 . 124.194.84.248
6 . 27.232.231.141
7 . 118.90.46.99
8 . 51.159.201.154
9 . 102.50.13.183
10. 49.88.163.90
11. 37.93.5.23
12. 88.233.94.212
13. 171.178.205.198
14. 155.180.84.17
15. 14.130.116.65
16. 33.61.220.135

Choices
0.    Back
1-16. Select server
17.   Next page
Your choice: 17
```
*screen is cleared*
```
Server selection (Page 2/16)
1 . 112.233.62.161
2 . 65.225.252.103
3 . 62.1.126.151
4 . 234.220.107.150
5 . 143.56.92.42
6 . 236.176.59.251
7 . 50.175.60.84
8 . 236.24.219.92
9 . 2.26.254.67
10. 251.250.170.58
11. 251.41.209.230
12. 5.60.124.148
13. 117.216.190.97
14. 137.249.92.187
15. 168.153.15.149
16. 177.235.241.179

Choices
0.    Back
1-16. Select server
17.   Next page
Your choice: 14
```
*screen is cleared*
```
Client options(137.249.92.187)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 1
```
*screen is cleared*
```
Insert(137.249.92.187)
Give key: John Doe
Give value: 150000
```
*screen is cleared*
```
Insert(137.249.92.187)
Inserted (John Doe, 150000) successfully
Press ENTER to continue...
```
*screen is cleared*
```
Client options(137.249.92.187)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 2
```
*screen is cleared*
```
Lookup(137.249.92.187)
Give key: Jane Doe
```
*screen is cleared*
```
Lookup(137.249.92.187)
Jane Doe not found
Press ENTER to continue...
```
*screen is cleared*
```
Client options(137.249.92.187)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 3
```
*screen is cleared*
```
Lookup(137.249.92.187)
Give key: John Doe
```
*screen is cleared*
```
Lookup(137.249.92.187)
John Doe found! Value: 150000
Press ENTER to continue...
```
*screen is cleared*
```
Client options(137.249.92.187)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 0
```
*screen is cleared*

```
Main menu
0. Exit
1. Client selection
Your choice: 1
```
*screen is cleared*
```
Server selection (Page 1/16)
1 . 103.198.105.115
2 . 81.255.74.236
3 . 41.205.186.171
4 . 242.251.227.70
5 . 124.194.84.248
6 . 27.232.231.141
7 . 118.90.46.99
8 . 51.159.201.154
9 . 102.50.13.183
10. 49.88.163.90
11. 37.93.5.23
12. 88.233.94.212
13. 171.178.205.198
14. 155.180.84.17
15. 14.130.116.65
16. 33.61.220.135

Choices
0.    Back
1-16. Select server
17.   Next page
Your choice: 9
```
*screen is cleared*
```
Client options(102.50.13.183)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 3
```
*screen is cleared*
```
Lookup(102.50.13.183)
Give key: John Doe
```
*screen is cleared*
```
Lookup(102.50.13.183)
John Doe found! Value: 150000
Press ENTER to continue...
```
*screen is cleared*
```
Client options(102.50.13.183)
0. Back
1. Insert
2. Lookup
3. Smart lookup
Your choice: 0
```
*screen is cleared*
```
Main menu
0. Exit
1. Client selection
Your choice: 0

--- omitted ---
```
*end of program*

```
$ make test
List tests (Client):
Test list_push...                               [ OK ]
Test list_find...                               [ OK ]
Test list_key...                                [ OK ]
Test list_value...                              [ OK ]
Test list_next...                               [ OK ]
SUCCESS: All unit tests have passed.

List tests (Ring):
Test list_push...                               [ OK ]
Test list_find...                               [ OK ]
Test list_data...                               [ OK ]
Test list_next...                               [ OK ]
SUCCESS: All unit tests have passed.

Hashtable tests (Client):
Test hashtable_insert...                        [ OK ]
Test hashtable_get...                           [ OK ]
Test hashtable_resize...                        [ OK ]
Test hashtable_size...                          [ OK ]
Test hashtable_item_count...                    [ OK ]
SUCCESS: All unit tests have passed.

Hashtable tests (Ring):
Test hashtable_insert...                        [ OK ]
Test hashtable_get...                           [ OK ]
Test hashtable_size...                          [ OK ]
Test hashtable_item_count...                    [ OK ]
SUCCESS: All unit tests have passed.

Utils tests:
Test string_copy...                             [ OK ]
Test random_ip...                               [ OK ]
Test hash...                                    [ OK ]
Test is_prime...                                [ OK ]
Test next_prime...                              [ OK ]
SUCCESS: All unit tests have passed.

--- omitted ---
```

To check for memory leaks, compile and then run with valgrind:
```
$ make main
$ valgrind ./main

--- omitted ---

==50733== 
==50733== HEAP SUMMARY:
==50733==     in use at exit: 0 bytes in 0 blocks
==50733==   total heap usage: 105,839 allocs, 105,839 frees, 6,486,879 bytes allocated
==50733== 
==50733== All heap blocks were freed -- no leaks are possible
==50733== 
==50733== For lists of detected and suppressed errors, rerun with: -s
==50733== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

$ make clean

--- omitted ---
```