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
inline double getdoubleValue(AttributeValue const& value) { return std::get<double>(value); }
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

  int partition (std::vector<AttributeValue>& arr, int low, int high){
    AttributeValue pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
  }

  void quickSort(std::vector<AttributeValue>& arr, int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
  }

  long runQuery(long threshold = 9) {
    auto sum = 0L;
    // You should add your implementation here...

    // 1. Large1.a = Large2.a -> sort-merge join
    // a. Quicksort
    std::vector<AttributeValue> large1_a, large2_a, large_merge_join;
    for(int i = 0; i < large1_size; i++){
      large1_a.push_back(large1[0][i]);
      large2_a.push_back(large2[0][i]);
    }
    quickSort(large1_a, 0, large1_tuple_size);
    quickSort(large2_a, 0, large2_tuple_size);
    // b. Merge data
    auto leftI = 0;
    auto rightI = 0;
    while (leftI < large1_size && rightI < large2_size) {
      auto leftInput = large1_a[leftI];
      auto rightInput = large2_a[rightI];
      if(leftInput < rightInput){
        leftI++;
      }
      else if(rightInput < leftInput){
        rightI++;
      }
      else{
        large_merge_join.push_back(leftInput);
        rightI++;
        leftI++;
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
