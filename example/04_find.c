#include "util.h"

void object_find() {
  json_value_t *json = create_test_obj();
  printf("\n---------- origin json ------------\n");
  print_json_value(json, 0);

  json_object_t *obj = json_value_object(json);
  const json_value_t *find_val = json_object_find("1111", obj);

  printf("\n---------- find value ------------\n");
  print_json_value(find_val, 0);
  json_value_destroy(json);
}

int main() { object_find(); }
