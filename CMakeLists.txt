project( KShortestPaths )

cmake_minimum_required( VERSION 2.6 )

include_directories( ${KShortestPaths_SOURCE_DIR} )

add_executable( kshortestpath
  MainP.cpp
  BaseGraph.cpp
  BasePath.cpp
  DijkstraShortestPathAlg.cpp
  YenTopKShortestPathsAlg.cpp
  Graph.cpp

#  TGraph.cpp
#  TPath.cpp
#  DynamicGraph.cpp

)

include( CTest )

add_test( NAME kshortestpath1
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  1
)

add_test( NAME kshortestpath2
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  2
)

add_test( NAME kshortestpath10
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  10
)

add_test( NAME kshortestpath50
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  50
)

add_test( NAME kshortestpath100
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  100
)

add_test( NAME kshortestpath1000
  COMMAND ${KShortestPaths_BINARY_DIR}/kshortestpath
  ${KShortestPaths_SOURCE_DIR}/data/test_50
  1000
)

