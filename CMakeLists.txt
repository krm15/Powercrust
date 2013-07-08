cmake_minimum_required(VERSION 2.8)
 
PROJECT(SURFACERECONSTRUCTION)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

INCLUDE_DIRECTORIES( ${SURFACERECONSTRUCTION_SOURCE_DIR} )


ADD_LIBRARY( PowerCrust ${SURFACERECONSTRUCTION_SOURCE_DIR}/vtkPowerCrustSurfaceReconstruction.cxx )


add_executable( reconstruct ReconstructFromPoints.cxx )
target_link_libraries( reconstruct ${VTK_LIBRARIES} PowerCrust )

