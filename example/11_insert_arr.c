#include "json_parser.h"
#include "util.h"

void arr_insert() {
  json_value_t *json = create_test_arr();
  printf("\n---------- origin json ------------\n");
  print_json_value(json, 0);

  json_array_t *arr = json_value_array(json);
  const json_value_t *arr_cursor = NULL;
  int i = 0;
  for (; i < 2; i++) {
    arr_cursor = json_array_next_value(arr_cursor, arr);
  }
  print_json_value(arr_cursor, 0);
  json_array_insert_before(arr_cursor, arr, JSON_VALUE_TRUE);
  json_array_insert_after(arr_cursor, arr, JSON_VALUE_STRING, "after");
  printf("\n---------- after insert ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n---------- insert array ------------\n");
  arr_insert();
}
