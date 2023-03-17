#include "util.h"

void obj_iter() {
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

  json_object_t *obj = json_value_object(json);
  const char *key = NULL;
  const json_value_t *obj_cursor = NULL;

  printf("\n---------- iterate : ------------\n");
  json_object_for_each(key, obj_cursor, obj) {
    printf("%s : \t", key);
    print_json_value(obj_cursor, 0);
    printf("\n");
  }
  json_value_destroy(json);
}

void obj_iter_reverse() {
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

  json_object_t *obj = json_value_object(json);
  const char *key = NULL;
  const json_value_t *obj_cursor = NULL;

  printf("\n---------- iterate reverse: ------------\n");
  json_object_for_each_prev(key, obj_cursor, obj) {
    printf("%s : \t", key);
    print_json_value(obj_cursor, 0);
    printf("\n");
  }
  json_value_destroy(json);
}

int main() {
  printf("\n---------- iterate object ------------\n");
  obj_iter();

  printf("\n---------- iterate object (reverse) ------------\n");
  obj_iter_reverse();
}
