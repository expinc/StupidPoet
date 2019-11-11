set(infra_src
    ExceptionBase.cpp
    FileIo.cpp
    InfraException.cpp
    UStr.cpp
)
add_library(infra STATIC ${infra_src})
