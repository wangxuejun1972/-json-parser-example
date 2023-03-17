#include "json_parser.h"
#include "util.h"

void obj_insert() {
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
  const json_value_t *obj_cursor = NULL;
  int i = 0;
  for (; i < 2; i++) {
    obj_cursor = json_object_next_value(obj_cursor, obj);
  }
  print_json_value(obj_cursor, 0);
  json_object_insert_before(obj_cursor, obj, "prev_new_key", JSON_VALUE_TRUE);
  json_object_insert_after(obj_cursor, obj, "after_new_key", JSON_VALUE_STRING,
                           "prev");

  printf("\n---------- after insert ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n---------- insert object ------------\n");
  obj_insert();
}
