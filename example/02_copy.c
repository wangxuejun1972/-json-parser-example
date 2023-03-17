#include "util.h"

json_value_t *json_value_copy(const json_value_t *val);

json_value_t *json_value_copy_object(const json_value_t *val) {
  json_value_t *dest_val = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *dest_obj = json_value_object(dest_val);
  json_object_t *obj = json_value_object(val);
  const char *name;

  json_object_for_each(name, val, obj)
      json_object_append(dest_obj, name, 0, json_value_copy(val));

  return dest_val;
}

json_value_t *json_value_copy_array(const json_value_t *val) {
  json_value_t *dest_val = json_value_create(JSON_VALUE_ARRAY);
  json_array_t *dest_arr = json_value_array(dest_val);
  json_array_t *arr = json_value_array(val);
  json_array_for_each(val, arr)
      json_array_append(dest_arr, 0, json_value_copy(val));
  return dest_val;
}

json_value_t *json_value_copy(const json_value_t *val) {
  switch (json_value_type(val)) {
  case JSON_VALUE_STRING:
    return json_value_create(JSON_VALUE_STRING, json_value_string(val));
  case JSON_VALUE_NUMBER:
    return json_value_create(JSON_VALUE_NUMBER, json_value_number(val));
  case JSON_VALUE_OBJECT:
    return json_value_copy_object(val);
  case JSON_VALUE_ARRAY:
    return json_value_copy_array(val);
  default:
    return json_value_create(json_value_type(val));
  }
}

void copy_json() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *test_obj = json_value_object(json);
  json_object_append(test_obj, "test", JSON_VALUE_NUMBER, 123.0);
  json_object_append(test_obj, "test", JSON_VALUE_STRING, "json");

  printf("\n--------- origin --------------\n");
  print_json_value(json, 0);
  json_value_t *copy = json_value_copy(json);

  printf("\n--------- copy --------------\n");
  print_json_value(copy, 0);
  json_value_destroy(json);
  json_value_destroy(copy);
}

int main() { copy_json(); }
