cmake_minimum_required(VERSION 3.6...3.27)
project(LCKERNEL)

#TODO: Fix this
set(PATTERN_RESOURCE_PATH ${CMAKE_SOURCE_DIR}/res/hatch)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/res/hatch"
		DESTINATION "${FINAL_INSTALL_DIR}/usr/share/librecad"
)

#Include TinySpline
add_definitions("-DTINYSPLINE_DOUBLE_PRECISION")
add_definitions("-DBOOST_ALL_NO_LIB")
remove_definitions("-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
add_subdirectory("tinyspline")
include_directories("${CMAKE_SOURCE_DIR}/lckernel/tinyspline/src")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions("-Wall")

message("***** LibreCAD kernel *****")

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# SOURCE FILES
set(lckernel_srcs
build_constants.cpp
cad/base/cadentity.cpp
cad/base/id.cpp
cad/base/metainfo.cpp
cad/storage/settings/modulesettings.cpp
cad/storage/settings/doublesettingvalue.cpp
cad/storage/settings/stringsettingvalue.cpp
cad/storage/documentimpl.cpp
cad/storage/entitycontainer.cpp
cad/storage/quadtree.cpp
cad/storage/storagemanagerimpl.cpp
cad/storage/undomanagerimpl.cpp
cad/storage/document.cpp
cad/math/intersect.cpp
cad/geometry/geoarc.cpp
cad/geometry/geocircle.cpp
cad/geometry/geocoordinate.cpp
cad/geometry/geoellipse.cpp
cad/geometry/geospline.cpp
cad/geometry/geobezier.cpp
cad/geometry/geobeziercubic.cpp
cad/geometry/georegion.cpp
cad/math/lcmath.cpp
cad/math/equation.cpp
cad/math/intersectionhandler.cpp
cad/meta/layer.cpp
cad/meta/icolor.cpp
cad/meta/metalinewidth.cpp
cad/meta/dxflinepattern.cpp
cad/operations/entitybuilder.cpp
cad/operations/entityops.cpp
cad/operations/documentoperation.cpp
cad/operations/layerops.cpp
cad/operations/linepatternops.cpp
cad/primitive/arc.cpp
cad/primitive/circle.cpp
cad/primitive/hatch.cpp
cad/primitive/point.cpp
cad/primitive/ellipse.cpp
cad/primitive/line.cpp
cad/primitive/spline.cpp
cad/primitive/text.cpp
cad/primitive/mtext.cpp
cad/primitive/textbase.cpp
cad/primitive/dimension.cpp
cad/primitive/dimradial.cpp
cad/primitive/dimdiametric.cpp
cad/primitive/dimlinear.cpp
cad/primitive/dimaligned.cpp
cad/primitive/dimangular.cpp
cad/primitive/lwpolyline.cpp
cad/primitive/image.cpp
cad/primitive/insert.cpp
cad/math/helpermethods.cpp
cad/meta/block.cpp
cad/builders/line.cpp
cad/builders/arc.cpp
cad/builders/circle.cpp
cad/builders/dimaligned.cpp
cad/builders/dimangular.cpp
cad/builders/dimension.cpp
cad/builders/dimdiametric.cpp
cad/builders/dimlinear.cpp
cad/builders/dimradial.cpp
cad/builders/ellipse.cpp
cad/builders/point.cpp
cad/builders/insert.cpp
cad/builders/layer.cpp
cad/builders/linepattern.cpp
cad/builders/spline.cpp
cad/builders/lwpolyline.cpp
cad/builders/text.cpp
cad/builders/mtext.cpp
cad/builders/textbase.cpp
cad/meta/customentitystorage.cpp
cad/operations/blockops.cpp
cad/operations/builder.cpp
cad/primitive/customentity.cpp
cad/interface/snapconstrain.cpp
cad/storage/documentlist.cpp
cad/logger/logger.cpp
cad/base/cadobject.cpp
cad/objects/layout.cpp
        settings.cpp)

# HEADER FILES
set(lckernel_hdrs
build_constants.h
cad/const.h
cad/base/id.h
cad/base/cadentity.h
cad/base/metainfo.h
cad/storage/settings/modulesettings.h
cad/storage/settings/doublesettingvalue.h
cad/storage/settings/settingtypeexception.h
cad/storage/settings/isettingvalue.h
cad/storage/settings/unknownsettingexception.h
cad/storage/settings/stringsettingvalue.h
cad/storage/documentimpl.h
cad/storage/entitycontainer.h
cad/storage/quadtree.h
cad/storage/storagemanagerimpl.h
cad/storage/undomanagerimpl.h
cad/storage/document.h
cad/storage/storagemanager.h
cad/storage/undomanager.h
cad/events/addentityevent.h
cad/events/addlayerevent.h
cad/events/addviewportevent.h
cad/events/addlinepatternevent.h
cad/events/beginprocessevent.h
cad/events/commitprocessevent.h
cad/events/removeentityevent.h
cad/events/removelayerevent.h
cad/events/removelinepatternevent.h
cad/events/replaceentityevent.h
cad/events/replacelayerevent.h
cad/events/replacelinepatternevent.h
cad/math/intersect.h
cad/geometry/geobase.h
cad/geometry/geocoordinate.h
cad/geometry/geoarc.h
cad/geometry/geoarea.h
cad/geometry/geocircle.h
cad/geometry/geoellipse.h
cad/geometry/geospline.h
cad/geometry/geovector.h
cad/geometry/geobezierbase.h
cad/geometry/geobezier.h
cad/geometry/geobeziercubic.h
cad/interface/entitydispatch.h
cad/interface/metatype.h
cad/interface/snapable.h
cad/interface/splitable.h
cad/interface/snapconstrain.h
cad/math/lcmath.h
cad/math/equation.h
cad/math/intersectionhandler.h
cad/meta/color.h
cad/meta/icolor.h
cad/meta/metacolor.h
cad/meta/layer.h
cad/meta/metalinewidth.h
cad/meta/dxflinepattern.h
cad/operations/entitybuilder.h
cad/operations/entityops.h
cad/operations/documentoperation.h
cad/operations/layerops.h
cad/operations/undoable.h
cad/operations/linepatternops.h
cad/vo/entitycoordinate.h
cad/vo/entitydistance.h
cad/primitive/arc.h
cad/primitive/circle.h
cad/primitive/hatch.h
cad/primitive/point.h
cad/primitive/ellipse.h
cad/primitive/line.h
cad/primitive/spline.h
cad/primitive/text.h
cad/primitive/mtext.h
cad/primitive/textbase.h
cad/primitive/lwpolyline.h
cad/primitive/dimension.h
cad/primitive/dimradial.h
cad/primitive/dimdiametric.h
cad/primitive/dimlinear.h
cad/primitive/dimaligned.h
cad/primitive/dimangular.h
cad/primitive/textconst.h
cad/tools/string_helper.h
cad/primitive/image.h
cad/math/helpermethods.h
cad/meta/block.h
cad/builders/cadentity.h
cad/builders/line.h
cad/builders/arc.h
cad/builders/circle.h
cad/builders/dimaligned.h
cad/builders/dimangular.h
cad/builders/dimension.h
cad/builders/dimdiametric.h
cad/builders/dimlinear.h
cad/builders/dimradial.h
cad/builders/ellipse.cpp
cad/builders/point.h
cad/builders/spline.h
cad/builders/text.h
cad/builders/mtext.h
cad/builders/textbase.h
cad/primitive/insert.h
cad/builders/insert.h
cad/builders/layer.h
cad/builders/linepattern.h
cad/meta/customentitystorage.h
cad/operations/blockops.h
cad/operations/builder.h
cad/base/visitor.h
cad/primitive/customentity.h
cad/events/newwaitingcustomentityevent.h
cad/storage/documentlist.h
cad/interface/unmanageddraggable.h
cad/interface/tangentable.h
cad/logger/logger.h
cad/base/cadobject.h
cad/objects/layout.h
cad/tools/maphelper.h
cad/objects/pattern.h
settings.h
)

# Boost logging
#find_package(Boost REQUIRED COMPONENTS log)
FIND_PACKAGE (Threads)
if (NOT MSVC)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories("${CMAKE_SOURCE_DIR}/lckernel")
include_directories("${CMAKE_SOURCE_DIR}/lcviewernoqt")

# Eigen 3
find_package(Eigen3 REQUIRED)
if(CMAKE_COMPILER_IS_GNUCXX)
    include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})
else()
    include_directories(${Eigen3_INCLUDE_DIR})
endif()

# BUILDING CONFIG
# SEPARATE BUILDING FLAG
set(SEPARATE_BUILD OFF)

if (SEPARATE_BUILD STREQUAL "ON")
    include_directories("${CMAKE_SOURCE_DIR}")
    include_directories("${CMAKE_SOURCE_DIR}/../third_party")
else()
    include_directories("${CMAKE_SOURCE_DIR}/lckernel")
    include_directories("${CMAKE_SOURCE_DIR}/third_party")
endif()

#Create version.cpp
add_custom_command(
        PRE_BUILD
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/build_constants.cpp
        COMMAND ${CMAKE_COMMAND} -DPATTERN_RESOURCE_PATH=${PATTERN_RESOURCE_PATH} -DDIR=${CMAKE_CURRENT_SOURCE_DIR} -DSETTINGS_PATH=${SETTINGS_PATH} -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SetBuildInfo.cmake"
        DEPENDS always_rebuild
)

# Anything that depends on this will always be rebuilt.
add_custom_command(
        OUTPUT always_rebuild
        COMMAND ${CMAKE_COMMAND} -E echo
)

add_library(lckernel SHARED ${lckernel_srcs} ${lckernel_hdrs})
if (MSVC)
    set_target_properties(lckernel PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIRS}"
    )
    message(lib_dir_Boost="${Boost_INCLUDE_DIRS}")
    target_link_libraries(lckernel Boost::log)
endif()

target_link_libraries(lckernel ${Boost_LIBRARIES} ${APR_LIBRARIES} ${G_EXTRA_LIBS} tinysplinecxx)
if (MSVC)
	target_link_libraries(lckernel Boost::log ${RapidJSON_LIBRARIES})
endif()

# INSTALLATION
install(TARGETS lckernel 
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} 
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
