#include "util.h"

void test_create() {
  json_value_t *val = json_value_create(JSON_VALUE_NULL);
  fprintf(stderr, "%d\n", json_value_type(val));
  json_value_destroy(val);
}

void obj_create() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *test_obj = json_value_object(json);

  // be careful here, don't use 123, you can see what happen here, a bug here
  json_object_append(test_obj, "test", JSON_VALUE_NUMBER, 123.0);
  json_object_append(test_obj, "recv", JSON_VALUE_STRING, "json");
  print_json_value(json, 0);
  json_value_destroy(json);
}

void nested_obj_create() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *test_obj = json_value_object(json);
  json_object_append(test_obj, "test", JSON_VALUE_NUMBER, 123.0);
  json_object_append(test_obj, "recv", JSON_VALUE_STRING, "json");
  const json_value_t *json1 =
      json_object_append(test_obj, "1111", JSON_VALUE_OBJECT);
  json_object_t *test_obj1 = json_value_object(json1);
  json_object_append(test_obj1, "test", JSON_VALUE_NUMBER, 123.0);
  const char *str = "111111";
  json_object_append(test_obj1, "test1", JSON_VALUE_STRING, str);
  print_json_value(json, 0);
  json_value_destroy(json);
}

void arr_create() {
  json_value_t *json = json_value_create(JSON_VALUE_ARRAY);
  json_array_t *test_arr = json_value_array(json);
  json_array_append(test_arr, JSON_VALUE_NULL);
  print_json_value(json, 0);
  json_value_destroy(json);
}

void obj_duplicate_key() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *test_obj = json_value_object(json);
  json_object_append(test_obj, "test", JSON_VALUE_NUMBER, 123.0);
  json_object_append(test_obj, "test", JSON_VALUE_STRING, "json");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n-------- create basic value -----\n");
  test_create();

  printf("\n-------- create object ----------\n");
  obj_create();

  printf("\n-------- create nested level object ------\n");
  nested_obj_create();

  printf("\n-------- create nested level object ------\n");
  arr_create();

  printf("\n-------- create obj duplicate key ------\n");
  obj_duplicate_key(); // support duplicate key
}
