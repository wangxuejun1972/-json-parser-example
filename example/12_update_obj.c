#include "json_parser.h"
#include "util.h"

void obj_update() {
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
  const json_value_t *find = json_object_find("recv", obj);
  if (find != NULL) {
    printf("find the element\n");
  }
  json_object_insert_before(find, obj, "recv", JSON_VALUE_TRUE);
  json_value_t *remove_val = json_object_remove(find, obj);
  json_value_destroy(remove_val); // don't forget

  printf("\n---------- after insert ------------\n");
  print_json_value(json, 0);
  json_value_destroy(json);
}

int main() {
  printf("\n---------- update object ------------\n");
  obj_update();
}
