project( KShortestPaths )

cmake_minimum_required( VERSION 2.6 )

include_directories( ${KShortestPaths_SOURCE_DIR} )

configure_file( ${KShortestPaths_SOURCE_DIR}/MainP.cpp.in
                ${KShortestPaths_BINARY_DIR}/MainP.cpp
                @ONLY
)

add_executable( kshortestpath
  ${KShortestPaths_BINARY_DIR}/MainP.cpp
  BaseGraph.cpp
  BasePath.cpp
#  TGraph.cpp
  DijkstraShortestPathAlg.cpp
#  TPath.cpp
#  DynamicGraph.cpp
  YenTopKShortestPathsAlg.cpp
  Graph.cpp
)
