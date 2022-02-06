# Notes

## The Query

SQL Query:
select sum(large1.c * large2.c * small.c) from large1, large2, large3 where large1.a = large2.a and large2.a
= small.a and x*large1.b + y*large2.b + z*small.b > threshold;

Breaking down the query:
1. large1.a = large2.a AND
2. large2.a = small.a AND
3. x\*large1.b + y\*large2.b + z*small.b > thershold 
4. sum(large1.c * large2.c * small.c)

## Large1.a = Large2.a

- Sort-merge join
- Implement int

## large2.a = small.a

- Hash-join

## x\*large1.b + y\*large2.b + z*small.b > thershold 

- Calculator style
- User input for threshold

## sum(large1.c * large2.c * small.c)

- Calculator style

## TODO List
- Deal with dirty values
- Deal with equality problems with different data types

## Explanations of features
- Chose to use large2_size in sort-merge for loop because it will be smaller 
than large1_size because of the hash-join with small.
- Chose to do hash-join first because it will remove the most results 
for the sort-merge join