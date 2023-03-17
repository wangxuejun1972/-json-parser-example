#include "json_parser.h"
#include "util.h"

void arr_update() {
  json_value_t *json = create_test_arr();
  printf("\n---------- origin json ------------\n");
  print_json_value(json, 0);

  json_array_t *arr = json_value_array(json);
  const json_value_t *arr_cursor = NULL;
  int index = 0;
  json_array_for_each(arr_cursor, arr) {
    if (index++ == 1)
      break;
  }

  print_json_value(arr_cursor, 0);
  json_array_insert_before(arr_cursor, arr, JSON_VALUE_TRUE);
  json_value_t *remove_val = json_array_remove(arr_cursor, arr);
  json_value_destroy(remove_val); // don't forget

  printf("\n---------- after update ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n---------- update array ------------\n");
  arr_update();
}
