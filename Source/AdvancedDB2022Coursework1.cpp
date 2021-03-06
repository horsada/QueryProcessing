#include "AdvancedDB2022Coursework1.hpp"
/*
#include <array>
#include <cstdlib>
#include <tuple>
#include <variant>
#include <vector>
#include <iostream>
// YOU MAY NOT ADD ANY OTHER INCLUDES!!!
using AttributeValue = std::variant<long, double, char const*>;
using Tuple = std::vector<AttributeValue>;
using Relation = std::vector<Tuple>;

/**
 * 0 is long int, 1 is double, 2 is a c-string
 */
/*
inline size_t getAttributeValueType(AttributeValue const& value) { return value.index(); }
inline long getLongValue(AttributeValue const& value) { return std::get<long>(value); }
inline double getDoubleValue(AttributeValue const& value) { return std::get<double>(value); }
inline char const* getStringValue(AttributeValue const& value) {
  return std::get<char const*>(value);
}
inline size_t getNumberOfValuesInTuple(Tuple const& t) { return t.size(); }
inline size_t getNumberOfTuplesInRelation(Relation const& t) { return t.size(); }

void printRelation(Relation a){
    for(int i = 0; i < a.size(); i++){
        printf("i: %d\n", i); 
        for(int j = 0; j < a[i].size(); j++){
          if(getAttributeValueType(a.at(i).at(j)) == 0){
            printf("j: %d, value: %d\n", j, getLongValue(a.at(i).at(j)));
          }
          else if(getAttributeValueType(a.at(i).at(j)) == 1){
            printf("j: %d, value: %d\n", j, getDoubleValue(a.at(i).at(j)));
          }
          else if(getAttributeValueType(a.at(i).at(j)) == 2){
            printf("j: %d, value: %d\n", j, getStringValue(a.at(i).at(j)));
          }
          else{
            printf("Incorrect type\n");
          }
        }
    }
}

  void Testswap(AttributeValue& a, AttributeValue& b){
    printf("Entered Testswap\n, a = %d, b = %d\n", a, b);
    AttributeValue t = a;
    a = b;
    b = t;
  }

  int Testpartition(Relation& arr, int low, int high){
    printf("high =  %d\n", high);
    AttributeValue pivot = arr.at(high-1).at(0);    // pivot
    int i = (low - 1);  // Index of smaller element
    printf("Pivot = %d, Before partition for loop\n", pivot);
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        printf("Entered partition for loop\n");
        // TODO: implement double and long 
        if( (getAttributeValueType(pivot) == 0) && (getAttributeValueType(arr.at(j).at(0)) == 0) ){
          if (getLongValue(arr.at(j).at(0)) <= getLongValue(pivot)){
            printf("Entered partition long if statement\n");
            i++;    // increment index of smaller element
            Testswap(arr.at(i).at(0), arr.at(j).at(0));
          }
        }
        else if( (getAttributeValueType(pivot) == 1) && (getAttributeValueType(arr.at(j).at(0)) == 1) ){
          if ((int)getDoubleValue(arr.at(j).at(0)) <= (int)getDoubleValue(pivot)){
            printf("Entered partition double if statement\n");
            i++;    // increment index of smaller element
            Testswap(arr.at(i).at(0), arr.at(j).at(0));
          }
        }
        else if( (getAttributeValueType(pivot) == 2) && (getAttributeValueType(arr.at(j).at(0)) == 2) ){
          if (getStringValue(arr.at(j).at(0)) <= getStringValue(pivot)){
            printf("Entered partition string if statement\n");
            i++;    // increment index of smaller element
            Testswap(arr.at(i).at(0), arr.at(j).at(0));
          }
        }
        else{
          printf("Incorrect types\n");
        }
    }
    printf("After partition if statement. i = %d\n", i);
    if((i+1) < (high-1)){
      if(getAttributeValueType(arr.at(i+1).at(0)) == getAttributeValueType(arr.at(high-1).at(0))){
        Testswap(arr.at(i + 1).at(0), arr.at(high-1).at(0));
      }
    }
    printf("Before returning from partition\n");
    return (i + 1);
  }

  void TestquickSort(Relation& arr, int low, int high){
    printf("Entered Quicksort\n");
    std::vector<AttributeValue> arr_a;
    for(int i = 0; i < arr.size(); i++){
      arr_a.push_back(arr.at(i).at(0));
    }
    int pi;
    printf("After arr_a pushback\n");
    printf("arr_a size: %d\n", arr_a.size());
    if (low < high){
        // Separately sort elements before partition and after partition
        printf("Before Testpartition\n");
        pi = Testpartition(arr, low, high);
        printf("After Testpartition\n");
        TestquickSort(arr, low, pi - 1);
        TestquickSort(arr, pi + 1, high);
    }
  }

  // for finding index of element
  int getIndex(std::vector<AttributeValue>::iterator beg, 
    std::vector<AttributeValue>::iterator end, size_t type, AttributeValue val){
    printf("Entered getIndex\n");
    int index = -1;
    for (auto it = beg; it != end; ++it){
      if(type == 0){
        printf("Entered type == 0 if statement\n");
        if(getLongValue(*it) == getLongValue(val)){
          printf(("Entered getLongValue(*beg) == getLongValue(val)\n"));
          index = abs(std::distance(it, beg)); 
        }
      }
      else if(type == 1){
        if ((int)getDoubleValue(*beg) == (int)getDoubleValue(val)){
          index = std::distance(it, beg); 
          return index;
        }
      }
      else if(type == 2){
        if (getStringValue(*beg) == getStringValue(val)){
          index = std::distance(it, beg); 
        }
      }
      else{
        printf("Incorrect type, returning -1\n");
      }  
    }
    printf("Returning index = %d", index);
    return index;
  }

long TestrunQuery(Relation large1, Relation large2, Relation small, long threshold = 9) {
    auto sum = 0L;
    // You should add your implementation here...
    int x = 1;
    int y = 1;
    int z = 1;
    std::vector<AttributeValue> large1_a, large2_a, small_a;
    Relation small_hash_join;
    std::vector<AttributeValue> threshold_calc;

    // creating large2_a and large1_a
    for(int i = 0; i < large2.size(); i++){
      size_t val = getAttributeValueType(large2.at(i).at(0));
      if(val == 0){
        large2_a.push_back(getLongValue(large2.at(i).at(0)));
      }
      else if(val == 1){
        large2_a.push_back(getDoubleValue(large2.at(i).at(0)));
      }
      else if(val == 2){
        large2_a.push_back(getStringValue(large2.at(i).at(0)));
      }
      else{
        printf("Incorrect type\n");
      }
    }
    for(int i = 0; i < large1.size(); i++){
      size_t val = getAttributeValueType(large1.at(i).at(0));
      if(val == 0){
        large1_a.push_back(getLongValue(large1.at(i).at(0)));
      }
      else if(val == 1){
        large1_a.push_back(getDoubleValue(large1.at(i).at(0)));
      }
      else if(val == 2){
        large1_a.push_back(getStringValue(large1.at(i).at(0)));
      }
      else{
        printf("Incorrect type\n");
      }
    }

    printf("Before build phase:\n");
    // 1. Large2.a = small.a -> Hash join
    // a. Build phase
    std::vector<long> hashTable(large2.size()*2, -1);
    printf("hashTable (size = %d):\n", hashTable.size());
    for(int i = 0; i < hashTable.size(); i++){
      printf("hashTable at index %d: %d (should be -1)\n", i, hashTable.at(i));
    }
    for(size_t i = 0; i < large2.size(); i++) {
      long long_hashValue = -1;
      double double_hashValue = -1.0;
      long string_hashValue = -1;
      int attribute_type = getAttributeValueType(large2.at(i).at(0));
      if(attribute_type == 0){
        long_hashValue = getLongValue(large2.at(i).at(0)) % 10; // hash-function
        printf("After hash function. Hash value = %d\n", long_hashValue);
        while(hashTable[long_hashValue] != -1){
          printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", long_hashValue);
          // probe function
          long_hashValue += 1; 
          long_hashValue %= 10;
        } 
        printf("Entering value into hashTable\n");
        hashTable.at(long_hashValue) = getLongValue(large2.at(i).at(0));
        printf("New hashtable value: %d\n", hashTable.at(long_hashValue));
      }
      else if(attribute_type == 1){
        double_hashValue = (int)getDoubleValue(large2.at(i).at(0)) % 10; // hash-function
        printf("After hash function. Hash value = %f\n", double_hashValue);
          while(hashTable[double_hashValue] != -1){
          printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", double_hashValue);
          // probe function
          double_hashValue += 1.0; 
          double_hashValue = (int)double_hashValue % 10;
        } 
        printf("Entering value into hashTable\n");
        hashTable.at((int)double_hashValue) = (int)getDoubleValue(large2.at(i).at(0));
        printf("New hashtable value: %d\n", hashTable.at((int)double_hashValue));
      }
      else if(attribute_type == 2){
        string_hashValue = atoi(getStringValue(large2.at(i).at(0))) % 10; // hash-function
        printf("After hash function in string. Hash value = %f\n", string_hashValue);
        while(hashTable[string_hashValue] != -1){
          printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", string_hashValue);
          // probe function
          string_hashValue += 1; 
          string_hashValue = string_hashValue % 10;
        } 
        printf("Entering value into hashTable\n");
        hashTable.at(string_hashValue) = atoi(getStringValue(large2.at(i).at(0)));
        printf("New hashtable value: %d\n", hashTable.at(string_hashValue));
      }
      else{
        printf("Incorrect type\n");
      }
    }
    printf("After build phase\n");
    printf("hashTable:\n");
    for(int i = 0; i < hashTable.size(); i++){
      printf("hashTable at index %d: %d\n", i, hashTable.at(i));
    }
    // b. Probe phase
    for(int i = 0; i < small.size(); i++) {
      AttributeValue probeInput = small.at(i).at(0);
      long long_hashValue = -1;
      double double_hashValue = -1.0;
      long string_hashValue = -1;
      if(getAttributeValueType(probeInput) == 0){
        long_hashValue = abs(getLongValue(probeInput) % 10);
        printf("Before while loop, probeInput type Long. probeInput = %d, hashValue = %d\n", 
        getLongValue(probeInput), long_hashValue);
        printf("Relation small size: %d\n", small.size());
        printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(long_hashValue) != -1 &&  hashTable.at(long_hashValue) != getLongValue(probeInput)){
          long_hashValue = (long_hashValue++) % 10;
      }
        if(hashTable.at(long_hashValue) == getLongValue(probeInput)){
          small_hash_join.push_back(small.at(i));
          printf("Entered type=Long if statement\n");
          // find index of a value in large2 table:
          int index = getIndex(large2_a.begin(), large2_a.end(), 0, probeInput);
          small_hash_join.at(i).push_back(large2.at(index).at(1));
          small_hash_join.at(i).push_back(large2.at(index).at(2));
        }
      }
      else if(getAttributeValueType(probeInput) == 1){
        double_hashValue = abs((int)getDoubleValue(probeInput) % 10);
        printf("Before while loop, probeInput type Double. probeInput = %d, hashValue = %d\n", 
        (int)getDoubleValue(probeInput), double_hashValue);
        printf("Relation small size: %d\n", small.size());
        printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(double_hashValue) != -1 &&  
        hashTable.at(double_hashValue) != (int)getDoubleValue(probeInput)){
          double_hashValue = ((int)double_hashValue++) % 10;
      }
        if(hashTable.at(double_hashValue) == getDoubleValue(probeInput)){
          printf("Entered type=Double if statement\n");
          small_hash_join.push_back(small.at(i));
          // find index of a value in large2 table:
          int index = getIndex(large2_a.begin(), large2_a.end(), 1, probeInput);
          small_hash_join.at(i).push_back(large2.at(index).at(1));
          small_hash_join.at(i).push_back(large2.at(index).at(2));
        }
      }
      else if(getAttributeValueType(probeInput) == 2){
        printf("Entered string probe phase\n");
        string_hashValue = atoi(getStringValue(probeInput)) % 10;
        printf("Before while loop, probeInput type String. probeInput = %d, hashValue = %d\n", 
        atoi(getStringValue(probeInput)), string_hashValue);
        printf("Relation small size: %d\n", small.size());
        printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(string_hashValue) != -1 &&  hashTable.at(string_hashValue) 
        != atoi(getStringValue(probeInput))){
          string_hashValue = (string_hashValue++) % 10;
      }
        if(hashTable.at(string_hashValue) == atoi(getStringValue(probeInput))){
          small_hash_join.push_back(small.at(i));
          printf("Entered type=String if statement\n");
          // find index of a value in large2 table:
          int index = getIndex(large2_a.begin(), large2_a.end(), 2, probeInput);
          small_hash_join.at(i).push_back(large2.at(index).at(1));
          small_hash_join.at(i).push_back(large2.at(index).at(2));
        }
      }
      else{
        break;
      }
      printf("Exited for loop\n");
    }
    printf("Before Quicksort:\n");
    printf("small_hash_join size: %d\n", small_hash_join.size());
    printRelation(small_hash_join);
    // 2. small_hash_join = large1 -> sort-merge join
    // a. Quicksort
    if(small_hash_join.size() > 1){
      TestquickSort(small_hash_join, 0, small_hash_join.size());
    }
    printf("After small_hash_join Quicksort:\n");
    printRelation(small_hash_join);
    if(large1.size() > 1){
      TestquickSort(large1, 0, large1.size());
    }
    printf("After large1 Quicksort:\n");
    printRelation(large1);
    // b. Merge data
    auto leftI = 0;
    auto rightI = 0;

    while (leftI < small_hash_join.size() && rightI < large1.size()) {
      printf("leftI: %d, rightI: %d\n", leftI, rightI);
      auto leftInput = small_hash_join.at(leftI).at(0);
      auto rightInput = large1.at(rightI).at(0);
      size_t leftInputType = getAttributeValueType(leftInput);
      size_t rightInputType = getAttributeValueType(rightInput);
      if(leftInputType == 0 && rightInputType == 0){
        leftInput = getLongValue(small_hash_join.at(leftI).at(0));
        rightInput = getLongValue(large1.at(rightI).at(0));
      }
      else if(leftInputType == 1 && rightInputType == 1){
        leftInput = getDoubleValue(small_hash_join.at(leftI).at(0));
        rightInput = getDoubleValue(large1.at(rightI).at(0));
      }
      else if(leftInputType == 2 && rightInputType == 2){
        printf("Entered String merge\n");
        leftInput = getStringValue(small_hash_join.at(leftI).at(0));
        rightInput = getStringValue(large1.at(rightI).at(0));
      }
      else{
        break;
      }
      if(leftInput < rightInput){
        leftI++;
      }
      else if(rightInput < leftInput){
        rightI++;
      }
      else{
        printf("Before large_merge_join pushback\n");
        small_hash_join.at(leftI).push_back(large1.at(rightI).at(1));
        small_hash_join.at(leftI).push_back(large1.at(rightI).at(2));
        rightI++;
        leftI++;
      }
    }
    printf("Finish merge sort\n");
    printf("small_hash_join (size = %d , %d): \n", small_hash_join.size(), small_hash_join[0].size());
    printRelation(small_hash_join);

    long calc = 0;
    printf("calc before for loop: %d\n", calc);
    for(int i = 0; i < small_hash_join.size(); i++){
      calc = z*getLongValue(small_hash_join.at(i).at(1)) + y*getLongValue(small_hash_join.at(i).at(3))
       + x*getLongValue(small_hash_join.at(i).at(5));
      printf("Calc after loop: %d\n", calc);
      if(calc > threshold){
         printf("Entered threshold if statement\n");
         sum += getLongValue(small_hash_join.at(i).at(2))*getLongValue(small_hash_join.at(i).at(4))
         *getLongValue(small_hash_join.at(i).at(6));
       }
    }
    /*
    for(int i = 0; i < small_hash_join.size(); i++){
      if(z*getLongValue(small_hash_join[i][1]) + y*getLongValue(small_hash_join[i][3])
       + x*getLongValue(small_hash_join[i][5]) > threshold){
         sum += getLongValue(small_hash_join[i][2])*getLongValue(small_hash_join[i][4])
         *getLongValue(small_hash_join[i][6]);
       }
    }
    return sum;
  }


int main(){
  printf("Entered main\n");
  fflush(stdout);

  /* Test 1
  auto a = Relation{Tuple{1L, 20L, 3L}};
  auto b = Relation{Tuple{1L, 15L, 3L}};
  auto c = Relation{Tuple{1L, 25L, 3L}};
  */

  // Test 2
  /*
  auto a = Relation{Tuple{1L, 20L, 6L}, Tuple{1L, 20L, 3L}};
  auto b = Relation{Tuple{1L, 20L, 7L}, Tuple{1L, 17L, 4L}};
  auto c = Relation{Tuple{1L, 20L, 8L}, Tuple{1L, 29L, 5L}};

  // Test 3
  auto a = Relation{Tuple{"one", 20L, 3L}};
  auto b = Relation{Tuple{"one", 17L, 4L}}; // //
  auto c = Relation{Tuple{"one", 29L, 5L}};
  long sum = TestrunQuery(a,b,c);
  printf("Sum: %i\n", sum);
}
*/