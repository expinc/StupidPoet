set(json_src
    JsonArray.cpp
    JsonDoc.cpp
    JsonObject.cpp
    JsonValue.cpp
)
add_library(json STATIC ${json_src})
