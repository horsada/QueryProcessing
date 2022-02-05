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

## large2.a = small.a

- Hash-join

## x\*large1.b + y\*large2.b + z*small.b > thershold 

- Calculator style
- User input for threshold

## sum(large1.c * large2.c * small.c)

- Calculator style