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

    large1_size = getNumberOfTuplesInRelation(*large1);
    large2_size = getNumberOfTuplesInRelation(*large2);
    small_size = getNumberOfTuplesInRelation(*small);

    large1_tuple_size = large1[0].size();
    large2_tuple_size = large2[0].size();
    small_tuple_size = small[0].size();

    for(int i = 0; i < large1_tuple_size; i++){
      large1_attribute_types.push_back(getAttributeValueType(this->large1[0][i]));
      large2_attribute_types.push_back(getAttributeValueType(this->large2[0][i]));
      small_attribute_types.push_back(getAttributeValueType(this->small[0][i]));
    }
  }

  void swap(AttributeValue& a, AttributeValue& b){
    AttributeValue t = a;
    a = b;
    b = t;
  }
/*
  void swap_long(long& a, long& b){
    long t = a;
    a = b;
    b = t;
  }

  void swap_double(double& a, double& b){
    double t = a;
    a = b;
    b = t;
  }

  void swap_string(char const* a, char const* b){
    char const* t = a;
    a = b;
    b = t;
  }
*/
/*
  int partition_long(std::vector<long>& arr_a, int low, int high){
    long pivot = arr_a[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr_a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr_a[i], arr_a[j]);
        }
    }
    swap(arr_a[i + 1], arr_a[high]);
    return (i + 1);
  }

  int partition_double(std::vector<double>& arr_a, int low, int high){
    double pivot = arr_a[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr_a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap_double(arr_a[i], arr_a[j]);
        }
    }
    swap_double(arr_a[i + 1], arr_a[high]);
    return (i + 1);
  }

  int partition_string(std::vector<char const*>& arr_a, int low, int high){
    char const* pivot = arr_a[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr_a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap_string(arr_a[i], arr_a[j]);
        }
    }
    swap_string(arr_a[i + 1], arr_a[high]);
    return (i + 1);
  }
*/

  int partition(std::vector<AttributeValue>& arr_a, int low, int high){
    AttributeValue pivot = arr_a[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot

        // TODO: implement double and long 
        if (getLongValue(arr_a[j]) <= getLongValue(pivot))
        {
            i++;    // increment index of smaller element
            swap(arr_a[i], arr_a[j]);
        }
    }
    swap(arr_a[i + 1], arr_a[high]);
    return (i + 1);
  }
/*
  Relation quickSort(Relation& arr, int low, int high){
    std::vector<long> arr_a_long;
    std::vector<double> arr_a_double;
    std::vector<char const*> arr_a_string;
    for(int i = 0; i < arr.size(); i++){
      if(getAttributeValueType(large1[i][0]) == 0){
        arr_a_long.push_back(getLongValue(large1[i][0]));
      }
      else if(getAttributeValueType(large1[i][0]) == 1){
        arr_a_double.push_back(getDoubleValue(large1[i][0]));
      }
      else if(getAttributeValueType(large1[i][0]) == 2){
        arr_a_string.push_back(getStringValue(large1[i][0]));
      }
      else{
        // TODO
      }
    }
    int pi;
    if (low < high){
        // pi is partitioning index, arr[p] is now at right place 
      if(getAttributeValueType(large1[0][0]) == 0){
        int pi = partition_long(arr_a_long, low, high);
      }
      else if(getAttributeValueType(large1[0][0]) == 1){
        int pi = partition_double(arr_a_double, low, high);
      }
      else if(getAttributeValueType(large1[0][0]) == 2){
        int pi = partition_string(arr_a_string, low, high);
      }
      else{
        // TODO
      }
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
    for(int i=0; i < arr.size(); i++){
      arr[i][0] = arr_a[i];
    }
    return arr;
  }
*/
  Relation quickSort(Relation& arr, int low, int high){
    std::vector<AttributeValue> arr_a;
    for(int i = 0; i < arr.size(); i++){
      arr_a.push_back(arr[i][0]);
    }
    int pi;
    if (low < high){
        // Separately sort elements before partition and after partition
        pi = partition(arr_a, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
    for(int i=0; i < arr.size(); i++){
      arr[i][0] = arr_a[i];
    }
    return arr;
  }

  long runQuery(long threshold = 9) {
    auto sum = 0L;
    // You should add your implementation here...
    int x,y,z = 1;
    std::vector<AttributeValue> large1_a, large2_a, small_a;
    Relation large_merge_join, small_hash_join;
    std::vector<AttributeValue> threshold_calc;
    for(int i = 0; i < small_size; i++){
      large1_a.push_back(large1[i][0]);
      large2_a.push_back(large2[i][0]);
      small_a.push_back(small[i][0]);
    }
    // 1. Large2.a = small.a -> Hash join
    // a. Build phase
    std::vector<int> hashTable(small_size, -1);
    for(size_t i = 0; i < small_size; i++) {
      long hashValue = -1;
      int attribute_type = getAttributeValueType(small[i][0]) == 0;
      if(attribute_type == 0){
        hashValue = getLongValue(small[i][0]) % 10; // hash-function
      }
      else{
        break;
      }
      while(hashTable[hashValue] != -1){
        hashValue = (hashValue++ % 10); // probe function
        } 
        hashTable[hashValue] = getLongValue(small[i][0]);
    }
    // b. Probe phase
    for(size_t i = 0; i < large2_size; i++) {
      auto probeInput = large2[i][0];
      long hashValue = -1;
      if(getAttributeValueType(probeInput) == 0){
        auto hashValue = getLongValue(probeInput) % 10;
      }
      else{ // TODO: implement other data types
        break;
      }
      while(hashTable[hashValue] != -1 &&  hashTable[hashValue] != getLongValue(probeInput)){
        hashValue = (hashValue++ % 10);
      }
      if(hashTable[hashValue] == getLongValue(probeInput)){
        for(int j = 0; j < small_hash_join.size(); j++){
            small_hash_join[j].push_back(large2[j][1]);
            small_hash_join[j].push_back(large2[j][2]);
        }
      }
    }

    // 2. small_hash_join = large1 -> sort-merge join
    // a. Quicksort
    quickSort(small_hash_join, 0, small_size);
    quickSort(large1, 0, large2_size);
    // b. Merge data
    auto leftI = 0;
    auto rightI = 0;

    while (leftI < small_hash_join.size() && rightI < large2_size) {
      auto leftInput = small_hash_join[leftI][0];
      auto rightInput = large1[rightI][0];
      if(getAttributeValueType(leftInput) == 0 && getAttributeValueType(rightInput) == 0){
        leftInput = getLongValue(small_hash_join[leftI][0]);
        rightInput = getLongValue(large1[rightI][0]);
      }
      else if(getAttributeValueType(leftInput) == 1 && getAttributeValueType(rightInput) == 1){
        leftInput = getDoubleValue(small_hash_join[leftI][0]);
        rightInput = getDoubleValue(large1[rightI][0]);
      }
      else if(getAttributeValueType(leftInput) == 2 && getAttributeValueType(rightInput) == 2){
        leftInput = getStringValue(small_hash_join[leftI][0]);
        rightInput = getStringValue(large1[rightI][0]);
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
        large_merge_join.push_back(small_hash_join[leftI]);
        for(int i = 0; i < large_merge_join.size(); i++){
            large_merge_join[i].push_back(large1[rightI][1]);
            large_merge_join[i].push_back(large1[rightI][2]);
        }
        rightI++;
        leftI++;
      }
    }

    for(int i = 0; i < large_merge_join.size(); i++){
      if(z*getLongValue(large_merge_join[i][0]) + y*getLongValue(large_merge_join[i][4])
       + x*getLongValue(large_merge_join[i][6]) > threshold){
         sum += getLongValue(large_merge_join[i][2])*getLongValue(large_merge_join[i][5])
         *getLongValue(large_merge_join[i][7]);
       }
    }
    return sum;
  }
};

class DBMSImplementationForCompetition : public DBMSImplementationForMarks {
public:
  static constexpr char const* teamName =
      nullptr; // set this to your team name if you mean to compete
};

#endif /* ADVANCEDDB2022COURSEWORK1_H */
