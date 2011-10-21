/************************************************************************/
/* $Id: MainP.cpp 65 2010-09-08 06:48:36Z yan.qi.asu $                                                                 */
/************************************************************************/

#include <limits>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "GraphElements.h"
#include "Graph.h"
#include "DijkstraShortestPathAlg.h"
#include "YenTopKShortestPathsAlg.h"

void testDijkstraGraph( const std::string& filename )
{
  Graph* my_graph_pt = new Graph( filename );
  DijkstraShortestPathAlg shortest_path_alg(my_graph_pt);
  BasePath* result =
    shortest_path_alg.get_shortest_path(
      my_graph_pt->get_vertex(0), my_graph_pt->get_vertex(5));
  result->PrintOut(std::cout);
}

void testYenAlg(const std::string filename, int k)
{
  //Graph my_graph("data/test_6_2");
  Graph my_graph(filename);

  YenTopKShortestPathsAlg yenAlg(my_graph, my_graph.get_vertex(0),
    my_graph.get_vertex(5));

  int i=0;

  if( k <= 0 )
  {
    while(yenAlg.has_next())
    {
      ++i;
      yenAlg.next()->PrintOut(std::cout);
    }
  }
  else
  {
  std::vector< BasePath* > paths;

  yenAlg.get_shortest_paths( my_graph.get_vertex(0), my_graph.get_vertex(5), k, paths );

  std::vector< BasePath* >::const_iterator it = paths.begin();

  while( it != paths.end() )
    {
    (*it)->PrintOut(std::cout);
    ++it;
    }

  }

//  System.out.println("Result # :"+i);
//  System.out.println("Candidate # :"+yenAlg.get_cadidate_size());
//  System.out.println("All generated : "+yenAlg.get_generated_path_size());

}

int main( int argc, char* argv[] )
{
  int kk = 0;
  if( argc < 2 )
  {
    std::cout << "kshortespath takes 2 arguments" << std::endl;
    std::cout << "1- file path" << std::endl;
    std::cout << "2- k (if 0, explore all paths)" << std::endl;
    return EXIT_FAILURE;
  }

  if( argc == 3 )
    {
    kk = atoi( argv[2] );
    }
  std::cout << "Welcome to the real world!" << std::endl;

  /*testDijkstraGraph( argv[1] );*/
  testYenAlg( argv[1], kk );

  return EXIT_SUCCESS;
}
