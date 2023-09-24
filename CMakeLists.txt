cmake_minimum_required(VERSION 3.16)

set(Program hmac)
project(${Program} LANGUAGES C)

#optimize options
set(CMAKE_CXX_FLAGS "/Ot /fp:fast")

add_compile_definitions(USE_SSLEAY)

set(THIRD_PARTY_DIR "${CMAKE_SOURCE_DIR}/ThirdParty")

include_directories("${THIRD_PARTY_DIR}/openssl_x64-windows/include/openssl")
include_directories("${THIRD_PARTY_DIR}/openssl_x64-windows/include")
set(CRYPTO_LIBS "${THIRD_PARTY_DIR}/openssl_x64-windows/lib/libcrypto.lib")
set(SSL_LIBS "${THIRD_PARTY_DIR}/openssl_x64-windows/lib/libssl.lib")

add_executable(${Program}
	hmac.c
)

target_link_libraries(${Program} PUBLIC
	${CRYPTO_LIBS}
	${SSL_LIBS}
)
