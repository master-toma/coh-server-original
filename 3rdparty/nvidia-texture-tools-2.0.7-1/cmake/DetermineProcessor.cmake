
# Assume i586 by default.
SET(NV_SYSTEM_PROCESSOR "i586")

IF(UNIX)
	FIND_PROGRAM(CMAKE_UNAME uname /bin /usr/bin /usr/local/bin )
	IF(CMAKE_UNAME)
		EXEC_PROGRAM(uname ARGS -p OUTPUT_VARIABLE NV_SYSTEM_PROCESSOR RETURN_VALUE val)

		IF("${val}" GREATER 0 OR NV_SYSTEM_PROCESSOR STREQUAL "unknown")
			EXEC_PROGRAM(uname ARGS -m OUTPUT_VARIABLE NV_SYSTEM_PROCESSOR RETURN_VALUE val)
		ENDIF("${val}" GREATER 0 OR NV_SYSTEM_PROCESSOR STREQUAL "unknown")

		# processor may have double quote in the name, and that needs to be removed
		STRING(REGEX REPLACE "\"" "" NV_SYSTEM_PROCESSOR "${NV_SYSTEM_PROCESSOR}")
		STRING(REGEX REPLACE "/" "_" NV_SYSTEM_PROCESSOR "${NV_SYSTEM_PROCESSOR}")
	ENDIF(CMAKE_UNAME)

	# Get extended processor information with:
	# `cat /proc/cpuinfo`

ELSE(UNIX)
  IF(WIN32)
    SET (NV_SYSTEM_PROCESSOR "$ENV{PROCESSOR_ARCHITECTURE}")
  ENDIF(WIN32)
ENDIF(UNIX)


