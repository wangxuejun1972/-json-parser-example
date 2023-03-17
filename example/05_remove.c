#include "util.h"

void remove_obj() {
  json_value_t *json = create_test_obj();
  printf("\n---------- origin json ------------\n");
  /*
  {
      "test": 123,
      "recv": "json",
      "1111": {
          "test": 123,
          "test1": "111111"
      }
  }
   */
  print_json_value(json, 0);

  // find the val you want to remove
  json_object_t *obj = json_value_object(json);
  const json_value_t *find_val = json_object_find("1111", obj);
  json_value_t *remove_val = json_object_remove(find_val, obj);
  json_value_destroy(remove_val); // don't forget

  printf("\n---------- after remove ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

void remove_arr() {
  json_value_t *json = create_test_arr();
  printf("\n---------- origin json ------------\n");
  /*
  [null, "123", false]
  */
  print_json_value(json, 0);

  const json_value_t *arr_cursor = NULL;
  json_array_t *arr = json_value_array(json);
  arr_cursor = json_array_next_value(arr_cursor, arr);
  printf("\n---------- first ele ------------\n");
  print_json_value(arr_cursor, 0);

  // move to the 2rd ele and remove it
  arr_cursor = json_array_next_value(arr_cursor, arr);
  json_value_t *remove_val = json_array_remove(arr_cursor, arr);
  json_value_destroy(remove_val); // don't forget

  printf("\n---------- after remove ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n---------- remove object ------------\n");
  remove_obj();

  printf("\n---------- remove array ------------\n");
  remove_arr();
}
