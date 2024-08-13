# This system minimizes the number of transactions between multiple Banks who borrow money from each other.



  Let's take an example. say we have the following Persons:
    1.Bank_1
    2.Bank_2
    3.Bank_3
    4.Bank_4
    5.Bank_5


&emsp;    **From**&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp; &nbsp;                 **To** &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; **Amount**
1. Bank_1  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;             Bank_3 &emsp;&emsp;&emsp;&emsp;&emsp;          Rs 1000
2. Bank_1  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;             Bank_5 &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;         Rs 2000
3. Bank_2  &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp; &nbsp;             Bank_4  &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;      Rs 3000
4. Bank_3   &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;          Bank_5 &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Rs 4000
5. Bank_4  &emsp;&emsp;&nbsp;&nbsp;&emsp;&emsp;&emsp;&nbsp;       Bank_1 &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp; Rs 5000
6. Bank_5 &emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;       Bank_2 &emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Rs 6000
7. Bank_3        &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;       Bank_2 &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp; Rs 7000


# Algorithm:

  We initialise,
  A Object with name Bank which contain {name,totalamount} <br>
  unordered_map -- map bank with index. <br>
  2D vector - To store amount of transactions between banks.

  First,we calculate the total amount for every bank and store them in vector:

  totalamount = (amounts to be received) - (amounts to pay)

  Now the idea is that we are finding the bank which has minimum totalamount (Bank A, totalamount  a(always negative)) and then finding the bank which has the
  maximum net amount (Bank B, totalamount b). After tha we find minimum of absolute value of a and b {c = min(-a,b)}.
  Now A pays Rs. c to B and totalamount modifies,Now A need to debit (-a+c) amount and B needs to credit (b-c) amount.

If any one OR both become zero, means it completely settles down.
We will continue the above process until all Bank will not settle down completely.

# Final Answer of above example: <br>
Bank_3 Pays Rs.10000 to Bank_2 <br>
Bank_4 Pays Rs.2000 to Bank_1
