project( KShortestPaths )

cmake_minimum_required( VERSION 2.6 )

add_executable( kshortestpath
  MainP.cpp
  BaseGraph.cpp
  BasePath.cpp
#  TGraph.cpp
  DijkstraShortestPathAlg.cpp
#  TPath.cpp
#  DynamicGraph.cpp
  YenTopKShortestPathsAlg.cpp
  Graph.cpp
)
