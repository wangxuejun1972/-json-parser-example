#include "util.h"

void move_value() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *test_obj = json_value_object(json);

  json_object_append(test_obj, "test", JSON_VALUE_NUMBER, 123.0);

  printf("\n--------- origin json --------\n");
  print_json_value(json, 0);

  json_value_t *other = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *other_obj = json_value_object(other);
  json_object_append(other_obj, "recv", JSON_VALUE_STRING, "json");

  printf("\n--------- other json --------\n");
  print_json_value(other, 0);
  // move `other` to be a sub part of `json`
  json_object_append(test_obj, "sub", 0, other);

  printf("\n--------- after move --------\n");
  print_json_value(json, 0);

  json_value_destroy(json);
}

int main() { move_value(); }
