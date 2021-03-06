#
# Build APEX_ForceField
#

SET(GW_DEPS_ROOT $ENV{GW_DEPS_ROOT})
FIND_PACKAGE(PxShared REQUIRED)

SET(APEX_MODULE_DIR ${PROJECT_SOURCE_DIR}/../../../module)

SET(AM_SOURCE_DIR ${APEX_MODULE_DIR}/forcefield)

FIND_PACKAGE(nvToolsExt REQUIRED)

# Set the CUDA includes, etc.
INCLUDE(../common/SetupCUDA.cmake)

SET(APEX_FORCEFIELD_PLATFORM_INCLUDES
	${NVTOOLSEXT_INCLUDE_DIRS}
	${Boost_INCLUDE_DIRS}
	${CUDA_INCLUDE_DIRS}

	${PXSHARED_ROOT_DIR}/include/cudamanager
	${PROJECT_SOURCE_DIR}/../../../common/include/windows

	${PHYSX_ROOT_DIR}/Source/PhysXGpu/include
	${PHYSX_ROOT_DIR}/Include/gpu
)

SET(APEX_FORCEFIELD_PLATFORM_SOURCE_FILES
	${AM_SOURCE_DIR}/cuda/forcefield.cu
)

SET(APEX_FORCEFIELD_COMPILE_DEFS
	# Common to all configurations

	${APEX_WINDOWS_COMPILE_DEFS};ENABLE_TEST=0;EXCLUDE_CUDA=1;EXCLUDE_PARTICLES=1;

	$<$<CONFIG:debug>:${APEX_WINDOWS_DEBUG_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=DEBUG;>
	$<$<CONFIG:checked>:${APEX_WINDOWS_CHECKED_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=CHECKED;>
	$<$<CONFIG:profile>:${APEX_WINDOWS_PROFILE_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=PROFILE;>
	$<$<CONFIG:release>:${APEX_WINDOWS_RELEASE_COMPILE_DEFS};>
)

# include common ApexForceField.cmake
INCLUDE(../common/ApexForceField.cmake)

