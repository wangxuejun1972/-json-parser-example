#include "json_parser.h"
#include <stdio.h>

#define BUFSIZE (64 * 1024 * 1024)

void print_json_value(const json_value_t *val, int depth);

void print_json_object(const json_object_t *obj, int depth) {
  const char *name;
  const json_value_t *val;
  int n = 0;
  int i;

  printf("{\n");
  json_object_for_each(name, val, obj) {
    if (n != 0)
      printf(",\n");
    n++;
    for (i = 0; i < depth + 1; i++)
      printf("    ");
    printf("\"%s\": ", name);
    print_json_value(val, depth + 1);
  }

  printf("\n");
  for (i = 0; i < depth; i++)
    printf("    ");
  printf("}");
}

void print_json_array(const json_array_t *arr, int depth) {
  const json_value_t *val;
  int n = 0;
  int i;

  printf("[\n");
  json_array_for_each(val, arr) {
    if (n != 0)
      printf(",\n");
    n++;
    for (i = 0; i < depth + 1; i++)
      printf("    ");
    print_json_value(val, depth + 1);
  }

  printf("\n");
  for (i = 0; i < depth; i++)
    printf("    ");
  printf("]");
}

void print_json_string(const char *str) {
  printf("\"");
  while (*str) {
    switch (*str) {
    case '\r':
      printf("\\r");
      break;
    case '\n':
      printf("\\n");
      break;
    case '\f':
      printf("\\f");
      break;
    case '\b':
      printf("\\b");
      break;
    case '\"':
      printf("\\\"");
      break;
    case '\t':
      printf("\\t");
      break;
    case '\\':
      printf("\\\\");
      break;
    default:
      printf("%c", *str);
      break;
    }
    str++;
  }
  printf("\"");
}

void print_json_number(double number) {
  long long integer = number;

  if (integer == number)
    printf("%lld", integer);
  else
    printf("%lf", number);
}

void print_json_value(const json_value_t *val, int depth) {
  switch (json_value_type(val)) {
  case JSON_VALUE_STRING:
    print_json_string(json_value_string(val));
    break;
  case JSON_VALUE_NUMBER:
    print_json_number(json_value_number(val));
    break;
  case JSON_VALUE_OBJECT:
    print_json_object(json_value_object(val), depth);
    break;
  case JSON_VALUE_ARRAY:
    print_json_array(json_value_array(val), depth);
    break;
  case JSON_VALUE_TRUE:
    printf("true");
    break;
  case JSON_VALUE_FALSE:
    printf("false");
    break;
  case JSON_VALUE_NULL:
    printf("null");
    break;
  }
}

json_value_t *create_test_obj() {
  json_value_t *json = json_value_create(JSON_VALUE_OBJECT);
  json_object_t *obj = json_value_object(json);
  json_object_append(obj, "test", JSON_VALUE_NUMBER, 123.0);
  json_object_append(obj, "recv", JSON_VALUE_STRING, "json");
  const json_value_t *json1 =
      json_object_append(obj, "1111", JSON_VALUE_OBJECT);
  json_object_t *obj1 = json_value_object(json1);
  json_object_append(obj1, "test", JSON_VALUE_NUMBER, 123.0);
  const char *str = "111111";
  json_object_append(obj1, "test1", JSON_VALUE_STRING, str);
  return json;
}

json_value_t *create_test_arr() {
  json_value_t *json = json_value_create(JSON_VALUE_ARRAY);
  json_array_t *arr = json_value_array(json);
  json_array_append(arr, JSON_VALUE_NULL);
  json_array_append(arr, JSON_VALUE_STRING, "123");
  json_array_append(arr, JSON_VALUE_FALSE);
  return json;
}
