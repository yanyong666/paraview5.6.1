MACRO(LIBXML2_PLATFORM_TEST lang var description invert)
  IF(NOT DEFINED "${var}_COMPILED")
    MESSAGE(STATUS "${description}")
    TRY_COMPILE(${var}_COMPILED
      ${CMAKE_CURRENT_BINARY_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/${LIBXML2_PLATFORM_TEST_FILE_${lang}}
      COMPILE_DEFINITIONS -DTEST_${var} ${LIBXML2_PLATFORM_TEST_DEFINES} ${LIBXML2_PLATFORM_TEST_EXTRA_FLAGS}
      OUTPUT_VARIABLE OUTPUT)
    IF(${var}_COMPILED)
      FILE(APPEND
        ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeOutput.log
        "${description} compiled with the following output:\n${OUTPUT}\n\n")
    ELSE()
      FILE(APPEND
        ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "${description} failed to compile with the following output:\n${OUTPUT}\n\n")
    ENDIF()
    IF(${invert} MATCHES INVERT)
      IF(${var}_COMPILED)
        MESSAGE(STATUS "${description} - no")
      ELSE()
        MESSAGE(STATUS "${description} - yes")
      ENDIF()
    ELSE()
      IF(${var}_COMPILED)
        MESSAGE(STATUS "${description} - yes")
      ELSE()
        MESSAGE(STATUS "${description} - no")
      ENDIF()
    ENDIF()
  ENDIF()
  IF(${invert} MATCHES INVERT)
    IF(${var}_COMPILED)
      SET(${var} 0)
    ELSE()
      SET(${var} 1)
    ENDIF()
  ELSE()
    IF(${var}_COMPILED)
      SET(${var} 1)
    ELSE()
      SET(${var} 0)
    ENDIF()
  ENDIF()
ENDMACRO()

MACRO(LIBXML2_PLATFORM_TEST_RUN lang var description invert)
  IF(NOT DEFINED "${var}")
    MESSAGE(STATUS "${description}")
    TRY_RUN(${var} ${var}_COMPILED
      ${CMAKE_CURRENT_BINARY_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/${LIBXML2_PLATFORM_TEST_FILE_${lang}}
      COMPILE_DEFINITIONS -DTEST_${var} ${LIBXML2_PLATFORM_TEST_DEFINES} ${LIBXML2_PLATFORM_TEST_EXTRA_FLAGS}
      OUTPUT_VARIABLE OUTPUT)

    # Note that ${var} will be a 0 return value on success.
    IF(${var}_COMPILED)
      IF(${var})
        FILE(APPEND
          ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
          "${description} compiled but failed to run with the following output:\n${OUTPUT}\n\n")
      ELSE()
        FILE(APPEND
          ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeOutput.log
          "${description} compiled and ran with the following output:\n${OUTPUT}\n\n")
      ENDIF()
    ELSE()
      FILE(APPEND
        ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "${description} failed to compile with the following output:\n${OUTPUT}\n\n")
      SET(${var} -1 CACHE INTERNAL "${description} failed to compile.")
    ENDIF()

    IF(${invert} MATCHES INVERT)
      IF(${var}_COMPILED)
        IF(${var})
          MESSAGE(STATUS "${description} - yes")
        ELSE()
          MESSAGE(STATUS "${description} - no")
        ENDIF()
      ELSE()
        MESSAGE(STATUS "${description} - failed to compile")
      ENDIF()
    ELSE()
      IF(${var}_COMPILED)
        IF(${var})
          MESSAGE(STATUS "${description} - no")
        ELSE()
          MESSAGE(STATUS "${description} - yes")
        ENDIF()
      ELSE()
        MESSAGE(STATUS "${description} - failed to compile")
      ENDIF()
    ENDIF()
  ENDIF()

  IF(${invert} MATCHES INVERT)
    IF(${var}_COMPILED)
      IF(${var})
        SET(${var} 1)
      ELSE()
        SET(${var} 0)
      ENDIF()
    ELSE()
      SET(${var} 1)
    ENDIF()
  ELSE()
    IF(${var}_COMPILED)
      IF(${var})
        SET(${var} 0)
      ELSE()
        SET(${var} 1)
      ENDIF()
    ELSE()
      SET(${var} 0)
    ENDIF()
  ENDIF()
ENDMACRO()

MACRO(LIBXML2_PLATFORM_C_TEST var description invert)
  SET(LIBXML2_PLATFORM_TEST_DEFINES ${LIBXML2_PLATFORM_C_TEST_DEFINES})
  SET(LIBXML2_PLATFORM_TEST_EXTRA_FLAGS ${LIBXML2_PLATFORM_C_TEST_EXTRA_FLAGS})
  LIBXML2_PLATFORM_TEST(C "${var}" "${description}" "${invert}")
  SET(LIBXML2_PLATFORM_TEST_DEFINES)
  SET(LIBXML2_PLATFORM_TEST_EXTRA_FLAGS)
ENDMACRO()

MACRO(LIBXML2_PLATFORM_C_TEST_RUN var description invert)
  SET(LIBXML2_PLATFORM_TEST_DEFINES ${LIBXML2_PLATFORM_C_TEST_DEFINES})
  SET(LIBXML2_PLATFORM_TEST_EXTRA_FLAGS ${LIBXML2_PLATFORM_C_TEST_EXTRA_FLAGS})
  LIBXML2_PLATFORM_TEST_RUN(C "${var}" "${description}" "${invert}")
  SET(LIBXML2_PLATFORM_TEST_DEFINES)
  SET(LIBXML2_PLATFORM_TEST_EXTRA_FLAGS)
ENDMACRO()
