#########################################################################
# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

# Everything under Application uses VTK/ParaView ServerManager.
if (PARAVIEW_BUILD_QT_GUI)
  # Since the full module list can be really large, we only bring in a few
  # modules.
  vtk_module_config(__PV_VTK
    vtkCommonCore
    vtkPVServerManagerCore
    vtkPVServerManagerApplication
    pqCore
    pqComponents
    pqApplicationComponents)
  include_directories(${__PV_VTK_INCLUDE_DIRS})
  link_directories(${__PV_VTK_LIBRARY_DIRS})
  
  include(ParaViewBranding)
  add_subdirectory(ParaView)
endif()
