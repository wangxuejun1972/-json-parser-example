#include "util.h"

void arr_iter() {
  json_value_t *json = create_test_arr();
  printf("\n---------- origin json ------------\n");
  print_json_value(json, 0);

  json_array_t *arr = json_value_array(json);
  const json_value_t *arr_cursor = NULL;
  json_array_for_each(arr_cursor, arr) {
    print_json_value(arr_cursor, 0);
    printf("\n");
  }

  json_value_destroy(json);
}

void arr_iter_reverse() {
  json_value_t *json = create_test_arr();
  printf("\n---------- origin json ------------\n");
  print_json_value(json, 0);

  json_array_t *arr = json_value_array(json);
  const json_value_t *arr_cursor = NULL;
  json_array_for_each_prev(arr_cursor, arr) {
    print_json_value(arr_cursor, 0);
    printf("\n");
  }
  json_value_destroy(json);
}

int main() {
  printf("\n---------- iterate array ------------\n");
  arr_iter();

  printf("\n---------- iterate array (reverse) ------------\n");
  arr_iter_reverse();
}
