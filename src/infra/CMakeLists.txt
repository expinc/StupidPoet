set(infra_src
    ExceptionBase.cpp
    InfraException.cpp
    NGram.cpp
    Poetry.cpp
    Sentence.cpp
)
add_library(infra STATIC ${infra_src})

add_subdirectory(test)
