#include <stdbool.h>
#include <stdio.h>

typedef struct JSON JSON;

typedef enum {
  JSON_NULL,
  JSON_BOOLEAN,
  JSON_NUMBER,
  JSON_STRING,
  JSON_OBJECT,
  JSON_ARRAY
} JSONType;

typedef struct {
  char *field;
  bool value;
} JSONBoolean;

typedef struct {
  char *field;
  double value;
} JSONNumber;

typedef struct {
  char *field;
  char *text;
  size_t size;
} JSONString;

typedef struct {
  JSON *items;
  // Array Size
  size_t size;
} JSONArray;

typedef struct {
  JSON *members;
  // JSON Inner Object Size
  size_t size;
} JSONObject;

struct JSON {
  char *field; 
  JSONType type;
  union {
    JSONBoolean boolean;
    JSONNumber number;
    JSONString string;
    JSONObject object;
    JSONArray array;
  } value;
};

void json_free(JSON *j);
