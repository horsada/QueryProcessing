#ifndef ADVANCEDDB2022COURSEWORK1_H
#define ADVANCEDDB2022COURSEWORK1_H

#include <array>
#include <cstdlib>
#include <tuple>
#include <variant>
#include <vector>
// YOU MAY NOT ADD ANY OTHER INCLUDES!!!
using AttributeValue = std::variant<long, double, char const*>;
using Tuple = std::vector<AttributeValue>;
using Relation = std::vector<Tuple>;

/**
 * 0 is long int, 1 is double, 2 is a c-string
 */
inline size_t getAttributeValueType(AttributeValue const& value) { return value.index(); }
inline long getLongValue(AttributeValue const& value) { return std::get<long>(value); }
inline double getDoubleValue(AttributeValue const& value) { return std::get<double>(value); }
inline char const* getStringValue(AttributeValue const& value) {
  return std::get<char const*>(value);
}
inline size_t getNumberOfValuesInTuple(Tuple const& t) { return t.size(); }
inline size_t getNumberOfTuplesInRelation(Relation const& t) { return t.size(); }

/**
 * DBMS shall implement the following query in the query function:
 *
 * select sum(large1.c * large2.c * small.c) from large1, large2, small where
 * large1.a = large2.a and large2.a = small.a and large1.b + large2.b + small.b
 * > 9;
 */
class DBMSImplementationForMarks { // you may edit anything inside this class
                                   // but nothing else
  Relation large1;
  Relation large2;
  Relation small;

  int large1_size;
  int large2_size;
  int small_size;

  int large1_tuple_size;
  int large2_tuple_size;
  int small_tuple_size;

  std::vector<int> large1_attribute_types;
  std::vector<int> large2_attribute_types;
  std::vector<int> small_attribute_types;

public:
  void loadData(Relation const* large1,
                Relation const* large2, // NOLINT(bugprone-easily-swappable-parameters)
                Relation const* small)  // NOLINT(bugprone-easily-swappable-parameters)
  {
    this->large1 = *large1; // you can copy the relation or just keep a pointer
    this->large2 = *large2;
    this->small = *small;
    // here is some example code for the exatraction of values. Feel free to
    // access the data any way you like (without changing the function
    // signature, of course)
    if(getAttributeValueType(this->large1[0][0]) == 0) {
      long exampleLoadedValue = getLongValue(this->large1[0][0]);
    }
    // You should add your implementation here...

  }
void printRelation(Relation a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
          if(getAttributeValueType(a.at(i).at(j)) == 0){
            printf(" %d", getLongValue(a.at(i).at(j)));
          }
          else if(getAttributeValueType(a.at(i).at(j)) == 1){
            printf(" %d", getDoubleValue(a.at(i).at(j)));
          }
          else if(getAttributeValueType(a.at(i).at(j)) == 2){
            if(getStringValue(a.at(i).at(j)) == nullptr){
              continue;
            }
            printf(" %d", getStringValue(a.at(i).at(j)));
          }
          else{
            printf("Incorrect type\n");
          }
        }
        printf("\n");
    }
}

  void Testswap(Tuple& a, Tuple& b){
    //printf("Entered Testswap\n, a = %d, b = %d\n", a, b);
    Tuple t = a;
    a = b;
    b = t;
  }

  int Testpartition(Relation& arr, int low, int high){
    //printf("high =  %d\n", high);
    AttributeValue pivot = arr.at(high-1).at(0);    // pivot
    int i = (low - 1);  // Index of smaller element
    //printf("Pivot = %d, Before partition for loop\n", pivot);
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        //printf("Entered partition for loop\n");
        if( (getAttributeValueType(pivot) == 0) && (getAttributeValueType(arr.at(j).at(0)) == 0) ){
          if (getLongValue(arr.at(j).at(0)) <= getLongValue(pivot)){
            //printf("Entered partition long if statement\n");
            i++;    // increment index of smaller element
            //Testswap(arr.at(i).at(0), arr.at(j).at(0));
            Testswap(arr.at(i), arr.at(j));
          }
        }
        else if( (getAttributeValueType(pivot) == 1) && (getAttributeValueType(arr.at(j).at(0)) == 1) ){
          if ((int)getDoubleValue(arr.at(j).at(0)) <= (int)getDoubleValue(pivot)){
            //printf("Entered partition double if statement\n");
            i++;    // increment index of smaller element
            //Testswap(arr.at(i).at(0), arr.at(j).at(0));
            Testswap(arr.at(i), arr.at(j));
          }
        }
        else if( (getAttributeValueType(pivot) == 2) && (getAttributeValueType(arr.at(j).at(0)) == 2) ){
          if (getStringValue(arr.at(j).at(0)) <= getStringValue(pivot)){
            //printf("Entered partition string if statement\n");
            i++;    // increment index of smaller element
            //Testswap(arr.at(i).at(0), arr.at(j).at(0));
            Testswap(arr.at(i), arr.at(j));
          }
        }
        else{
          //printf("Incorrect types\n");
        }
    }
    //printf("After partition if statement. i = %d\n", i);
    if((i+1) >= (high-1)){
      return (i + 1);
    }
    else{
      if(getAttributeValueType(arr.at(i+1).at(0)) == getAttributeValueType(arr.at(high-1).at(0))){
        Testswap(arr.at(i + 1), arr.at(high-1));
      }
    }
    //printf("Before returning from partition\n");
    return (i + 1);
  }

  void TestquickSort(Relation& arr, int low, int high){
    //printf("Entered Quicksort\n");
    int pi;
    //printf("After arr_a pushback\n");
    //printf("arr_a size: %d\n", arr_a.size());
    if (low < high){
        // Separately sort elements before partition and after partition
        //printf("Before Testpartition\n");
        pi = Testpartition(arr, low, high);
        //printf("After Testpartition\n");
        TestquickSort(arr, low, pi - 1);
        TestquickSort(arr, pi + 1, high);
    }
  }

  // for finding index of element
  int getIndex(std::vector<AttributeValue>::iterator beg, 
    std::vector<AttributeValue>::iterator end, size_t type, AttributeValue val){
    //printf("Entered getIndex\n");
    int index = -1;
    //size_t beg_type = getAttributeValueType(*beg);
    for (auto it = beg; it != end; ++it){
      size_t beg_type = getAttributeValueType(*it);
      if(type == 0 && beg_type == 0){
        //printf("Entered type == 0 if statement of getIndex\n");
        //printf("Before for loop. Beg = %d", getLongValue(*beg));
        //printf("getLongValue(*it) = %d, getLongValue(val) = %d\n", 
        //getLongValue(*it), getLongValue(val));
        if(getLongValue(*it) == getLongValue(val)){
          //printf("Entered getLongValue(*beg) == getLongValue(val)\n");
          index = abs(std::distance(it, beg)); 
          break;
        }
      }
      else if(type == 1 && beg_type == 1){
        if ((int)getDoubleValue(*it) == (int)getDoubleValue(val)){
          //printf("Entered type == 1 if statement\n");
          index = abs(std::distance(it, beg)); 
          break;
        }
      }
      else if(type == 2 && beg_type == 2){
        if (atoi(getStringValue(*it)) == atoi(getStringValue(val))){
          printf("Entered type == 2 if statement\n");
          index = abs(std::distance(it, beg));
          break;
        }
      }
      else{
        continue;
      }  
    }
    //printf("Returning index = %d\n", index);
    return index;
  }

long runQuery(long threshold = 9) {
    auto sum = 0L;
    // You should add your implementation here...
    int x = 1;
    int y = 1;
    int z = 1;
    std::vector<AttributeValue> large1_a, large2_a, small_a;
    Relation small_hash_join;
    std::vector<AttributeValue> threshold_calc;
    printf("Before creating large1_a and large2_a\n");
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
    //printf("hashTable (size = %d):\n", hashTable.size());
    for(size_t i = 0; i < large2.size(); i++) {
      long long_hashValue = -1;
      double double_hashValue = -1.0;
      long string_hashValue = -1;
      int attribute_type = getAttributeValueType(large2.at(i).at(0));
      if(attribute_type == 0){
        long_hashValue = getLongValue(large2.at(i).at(0)) % 10; // hash-function
        //printf("After hash function. Hash value = %d\n", long_hashValue);
        while(hashTable[long_hashValue] != -1){
          //printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", long_hashValue);
          // probe function
          long_hashValue += 1; 
          long_hashValue %= 10;
        } 
        //printf("Entering value into hashTable\n");
        hashTable.at(long_hashValue) = getLongValue(large2.at(i).at(0));
        //printf("New hashtable value: %d\n", hashTable.at(long_hashValue));
      }
      else if(attribute_type == 1){
        double_hashValue = (int)getDoubleValue(large2.at(i).at(0)) % 10; // hash-function
        //printf("After hash function. Hash value = %f\n", double_hashValue);
          while(hashTable[double_hashValue] != -1){
          printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", double_hashValue);
          // probe function
          double_hashValue += 1.0; 
          double_hashValue = (int)double_hashValue % 10;
        } 
        //printf("Entering value into hashTable\n");
        hashTable.at((int)double_hashValue) = (int)getDoubleValue(large2.at(i).at(0));
        //printf("New hashtable value: %d\n", hashTable.at((int)double_hashValue));
      }
      else if(attribute_type == 2){
        if(getStringValue(large2.at(i).at(0)) != nullptr){
          string_hashValue = atoi(getStringValue(large2.at(i).at(0))) % 10; // hash-function
        }
        else{
          continue;
        }
        //printf("After hash function in string. Hash value = %f\n", string_hashValue);
        while(hashTable[string_hashValue] != -1){
          //printf("Entered while hashTable[hashValue] != -1. hashValue = %d\n", string_hashValue);
          // probe function
          string_hashValue += 1; 
          string_hashValue = string_hashValue % 10;
        } 
        //printf("Entering value into hashTable\n");
        hashTable.at(string_hashValue) = atoi(getStringValue(large2.at(i).at(0)));
        //printf("New hashtable value: %d\n", hashTable.at(string_hashValue));
      }
      else{
        printf("Incorrect type\n");
      }
    }
    printf("After build phase\n");
    /*printf("hashTable:\n");
    for(int i = 0; i < hashTable.size(); i++){
      printf("hashTable at index %d: %d\n", i, hashTable.at(i));
    }
    */
    // b. Probe phase
    for(int i = 0; i < small.size(); i++) {
      AttributeValue probeInput = small.at(i).at(0);
      long long_hashValue = -1;
      double double_hashValue = -1.0;
      long string_hashValue = -1;
      if(getAttributeValueType(probeInput) == 0){
        long_hashValue = abs(getLongValue(probeInput) % 10);
        //printf("Before while loop, probeInput type Long. probeInput = %d, hashValue = %d\n", 
        //getLongValue(probeInput), long_hashValue);
        //printf("Relation small size: %d\n", small.size());
        //printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(long_hashValue) != -1 &&  hashTable.at(long_hashValue) != getLongValue(probeInput)){
          long_hashValue = (long_hashValue++) % 10;
      }
        if(hashTable.at(long_hashValue) == getLongValue(probeInput)){
          int index = getIndex(large2_a.begin(), large2_a.end(), 0, probeInput);
          //printf("index  = %d\n", index);
          if(index == -1){
            continue;
          }
          small_hash_join.push_back(small.at(i));
          //printf("Entered type=Long if statement\n");
          // find index of a value in large2 table:
          small_hash_join.at(small_hash_join.size()-1).push_back(large2.at(index).at(1));
          small_hash_join.at(small_hash_join.size()-1).push_back(large2.at(index).at(2));
        }
      }
      else if(getAttributeValueType(probeInput) == 1){
        double_hashValue = abs((int)getDoubleValue(probeInput) % 10);
        //printf("Before while loop, probeInput type Double. probeInput = %d, hashValue = %d\n", 
        //(int)getDoubleValue(probeInput), double_hashValue);
        //printf("Relation small size: %d\n", small.size());
        //printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(double_hashValue) != -1 &&  
        hashTable.at(double_hashValue) != (int)getDoubleValue(probeInput)){
          double_hashValue = ((int)double_hashValue++) % 10;
      }
        if(hashTable.at(double_hashValue) == getDoubleValue(probeInput)){
          //printf("Entered type=Double if statement\n");
          int index = getIndex(large2_a.begin(), large2_a.end(), 1, probeInput);
          if(index == -1){
            continue;
          }
          small_hash_join.push_back(small.at(i));
          // find index of a value in large2 table:
          small_hash_join.at(i).push_back(large2.at(index).at(1));
          small_hash_join.at(i).push_back(large2.at(index).at(2));
        }
      }
      else if(getAttributeValueType(probeInput) == 2){
        //printf("Entered string probe phase\n");
        if(getStringValue(probeInput) == nullptr){
          continue;
        }
        else{
          //printf("getStringValue(probeInput) = %d\n", atoi(getStringValue(probeInput)));
          string_hashValue = atoi(getStringValue(probeInput)) % 10;
        }
        //printf("Before while loop, probeInput type String. probeInput = %d, hashValue = %d\n", 
        //atoi(getStringValue(probeInput)), string_hashValue);
        //printf("Relation small size: %d\n", small.size());
        //printf("Relation large2 size: %d\n", large2.size());
        while(hashTable.at(string_hashValue) != -1 &&  hashTable.at(string_hashValue) 
        != atoi(getStringValue(probeInput))){
          string_hashValue = (string_hashValue++) % 10;
        }
        if(hashTable.at(string_hashValue) == atoi(getStringValue(probeInput))){
          int index = getIndex(large2_a.begin(), large2_a.end(), 2, probeInput);
          //printf("index = %d\n", index);
          if(index == -1){
            //printf("Entered index == -1 of string probe\n");
            continue;
          }
          small_hash_join.push_back(small.at(i));
          //printf("Entered type=String if statement\n");
          //printf("Index = %d\n", index);
          // find index of a value in large2 table:
          small_hash_join.at(i).push_back(large2.at(index).at(1));
          small_hash_join.at(i).push_back(large2.at(index).at(2));
        }
      }
      else{
        break;
      }
      //printf("Exited for loop\n");
    }
    printf("After probe phase\n");
    //printf("Before Quicksort:\n");
    //printf("small_hash_join size: %d\n", small_hash_join.size());
    //printRelation(small_hash_join);
    // 2. small_hash_join = large1 -> sort-merge join
    // a. Quicksort
    if(small_hash_join.size() > 1){
      TestquickSort(small_hash_join, 0, small_hash_join.size());
    }
    printf("After small_hash_join Quicksort:\n");
    printRelation(small_hash_join);
    //printf("Before large1 Quicksort:\n");
    //printRelation(large1);
    if(large1.size() > 1){
      TestquickSort(large1, 0, large1.size());
    }
    printf("After large1 Quicksort:\n");
    printRelation(large1);
    // b. Merge data
    auto leftI = 0;
    auto rightI = 0;

    while (leftI < small_hash_join.size() && rightI < large1.size()) {
      //printf("leftI: %d, rightI: %d\n", leftI, rightI);
      auto leftInput = small_hash_join.at(leftI).at(0);
      auto rightInput = large1.at(rightI).at(0);
      size_t leftInputType = getAttributeValueType(leftInput);
      size_t rightInputType = getAttributeValueType(rightInput);
      //printf("leftInputType = %d, rightInputType = %d\n", leftInputType, rightInputType);
      if(leftInputType == 0 && rightInputType == 0){
        //printf("Entered Long merge\n");
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
      else if(rightInputType == 2){
        //printf("Entered else if(rightInputType == 2)\n");
        rightI++;
        continue;
      }
      else if(leftInputType == 2){
        //printf("Entered else if(leftInputType == 2)\n");
        leftI++;
        continue;
      }
      else{
        //printf("Incorrect type\n");
      }
      if(leftInput < rightInput){
        leftI++;
      }
      else if(rightInput < leftInput){
        rightI++;
      }
      else{
        printf("Before large_merge_join pushback\n");
        for(int i = 0; i < small_hash_join.size(); i++){
          printf("Entered for loop\n");
          if(leftInputType == 0 && rightInputType == 0){
            if(getLongValue(large1.at(rightI).at(0)) == getLongValue(small_hash_join.at(i).at(0))){
            printf("Entered if statement of for loop\n");
            small_hash_join.at(i).push_back(large1.at(rightI).at(1));
            small_hash_join.at(i).push_back(large1.at(rightI).at(2));
            }
          }
          else if(leftInputType == 1 && rightInputType == 1){
            if((int)getDoubleValue(large1.at(rightI).at(0)) 
            == (int)getDoubleValue(small_hash_join.at(i).at(0))){
            printf("Entered if statement of for loop\n");
            small_hash_join.at(i).push_back(large1.at(rightI).at(1));
            small_hash_join.at(i).push_back(large1.at(rightI).at(2));
            }
          }
          else if(leftInputType == 2 && rightInputType == 2){
            if(getStringValue(large1.at(rightI).at(0)) == getStringValue(small_hash_join.at(i).at(0))){
            printf("Entered String if statement of for loop\n");
            small_hash_join.at(i).push_back(large1.at(rightI).at(1));
            small_hash_join.at(i).push_back(large1.at(rightI).at(2));
            }
          }
          else{
            printf("Incorrect type\n");
          }
        }
        rightI++;
        leftI++;
      }
    }
    printf("Finish merge sort\n");
    printf("small_hash_join (size = %d): \n", small_hash_join.size());
    printRelation(small_hash_join);

    if(small_hash_join.size() == 0){
      return 0L;
    }
    long calc = 0;
    //printf("calc before for loop: %d\n", calc);
    for(int i = 0; i < small_hash_join.size(); i++){
      if(small_hash_join.at(i).size() > 1){
      calc += z*getLongValue(small_hash_join.at(i).at(1));
      }
      if(small_hash_join.at(i).size() > 3){
        //printf("Entered if(small_hash_join.at(i).size() > 2)\n");
        calc += y*getLongValue(small_hash_join.at(i).at(3));
      }
      if(small_hash_join.at(i).size() > 5){
        //printf("Entered if(small_hash_join.at(i).size() > 4)\n");
        calc += x*getLongValue(small_hash_join.at(i).at(5));
      }
    }

    std::vector<long> c_sums;
    //printf("Calc after loop: %d\n", calc);
    if(calc > threshold){
      //printf("Entered threshold if statement\n");
    for(int i = 0; i < small_hash_join.size(); i++){
        long c_sum = 1;
        if(small_hash_join.at(i).size() > 2){
         c_sum *= getLongValue(small_hash_join.at(i).at(2));
        }
         if(small_hash_join.at(i).size() > 4){
          c_sum *= getLongValue(small_hash_join.at(i).at(4));
          }
        if(small_hash_join.at(i).size() > 6){
          c_sum *= getLongValue(small_hash_join.at(i).at(6));
        }
        c_sums.push_back(c_sum);
      }
    }

    for(int i = 0; i < c_sums.size(); i++){
      sum += c_sums.at(i);
    }
    printf("sum = %d, End of testcase\n", sum);
    return sum;
  }
};

class DBMSImplementationForCompetition : public DBMSImplementationForMarks {
public:
  static constexpr char const* teamName =
      nullptr; // set this to your team name if you mean to compete
};

#endif /* ADVANCEDDB2022COURSEWORK1_H */
