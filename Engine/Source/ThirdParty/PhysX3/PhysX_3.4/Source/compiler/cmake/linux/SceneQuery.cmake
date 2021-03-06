#
# Build SceneQuery
#

SET(PHYSX_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../)

SET(LL_SOURCE_DIR ${PHYSX_SOURCE_DIR}/SceneQuery/src)

SET(SCENEQUERY_PLATFORM_INCLUDES
	PRIVATE ${PHYSX_SOURCE_DIR}/Common/src/linux
)

# Use generator expressions to set config specific preprocessor definitions
SET(SCENEQUERY_COMPILE_DEFS
	# Common to all configurations
	${PHYSX_LINUX_COMPILE_DEFS};PX_PHYSX_STATIC_LIB
)

if(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	LIST(APPEND SCENEQUERY_COMPILE_DEFS
		${PHYSX_LINUX_DEBUG_COMPILE_DEFS}
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "checked")
	LIST(APPEND SCENEQUERY_COMPILE_DEFS
		${PHYSX_LINUX_CHECKED_COMPILE_DEFS}
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "profile")
	LIST(APPEND SCENEQUERY_COMPILE_DEFS
		${PHYSX_LINUX_PROFILE_COMPILE_DEFS}
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "release")
	LIST(APPEND SCENEQUERY_COMPILE_DEFS
		${PHYSX_LINUX_RELEASE_COMPILE_DEFS}
	)
else(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	MESSAGE(FATAL_ERROR "Unknown configuration ${CMAKE_BUILD_TYPE}")
endif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")

IF(DEFINED PX_STATIC_LIBRARIES)
	SET(SCENEQUERY_LIBTYPE OBJECT)
ELSE()
	SET(SCENEQUERY_LIBTYPE STATIC)
ENDIF()

# include common SceneQuery settings
INCLUDE(../common/SceneQuery.cmake)

# enable -fPIC so we can link static libs with the editor
SET_TARGET_PROPERTIES(SceneQuery PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
