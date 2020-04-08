/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        11/11/2019
 *              This project is released under the 3-Clause BSD License.
 *
 */

#include "utilities/GraphUtilities.hh"
#include "utilities/Factory.hh"
#include <algorithm>

using namespace chase;
using namespace std;

using sptr_graph = std::shared_ptr<Graph>;
using sptr_vert = std::shared_ptr<Vertex>;

void chase::findAllPathsBetweenNodes(
        sptr_graph graph,
        std::vector< unsigned int >& visited,
        unsigned int end,
        std::list< std::vector< unsigned int > > &result )
{
    unsigned int back = visited.back();

    std::set< unsigned > adjNode = graph->getAdjacentNodes(back);
    for( auto node_it = adjNode.begin(); node_it != adjNode.end(); ++node_it )
    {
        unsigned node = *node_it;

        // Check if the node has been already visited.
        if( std::find(visited.begin(), visited.end(), node) != visited.end() )
        {
            continue;
        }

        if( node == end )
        {
            visited.push_back(*node_it);
            size_t hops = visited.size();
            std::vector< unsigned > found_path;
            for( size_t hop = 0; hop < hops; ++hop )
            {
                found_path.push_back(visited[hop]);
            }

            result.push_back(found_path);
            size_t n = visited.size() - 1;
            visited.erase(visited.begin() + n);
            break;
        }
    }
    for( auto node_it = adjNode.begin(); node_it != adjNode.end(); ++node_it )
    {
        unsigned node = *node_it;
        // Check if the node has been already visited.
        if( std::find(visited.begin(), visited.end(), node) != visited.end()
            || node == end )
        {
            continue;
        }
        visited.push_back(node);
        findAllPathsBetweenNodes(graph, visited, end, result);
        size_t n = visited.size() - 1;
        visited.erase(visited.begin() + n);
    }
}

sptr_graph chase::getSubGraph(sptr_graph graph, std::set< Vertex * > vertexes)
{
    sptr_graph ret = make_shared<Graph>(vertexes.size(), graph->isDirected());

    unsigned index = 0;
    for( auto v = vertexes.begin(); v != vertexes.end(); ++v)
    {
        std::string name = (*v)->getName()->getString();
        ret->associateVertex(index, make_shared<Vertex>(Nam(name)));
        ++index;
    }

    for( size_t i = 0; i < vertexes.size()-1; ++i )
        for( size_t j = 1; j < vertexes.size(); ++j )
        {
            std::string name_first(ret->getVertex(i)->getName()->getString());
            std::string name_second(ret->getVertex(j)->getName()->getString());
            int index_first = graph->getVertexIndex(name_first);
            int index_second = graph->getVertexIndex(name_second);

            if( index_first < 0 || index_second < 0) continue;

            Edge * edge = graph->getEdge(index_first, index_second).get();
            WeightedEdge * wedge = dynamic_cast<WeightedEdge*>(edge);
            bool weighted = (wedge != nullptr);

            if(edge != nullptr) {
                if (weighted) {
                    auto id = dynamic_cast< Identifier * >(wedge->getWeight().get());
                    if(id)
                        ret->addEdge(make_shared<WeightedEdge>(i,j,
                                                               make_shared<Identifier>(id->getDeclaration())));
                }
                else {
                    ret->addEdge(make_shared<Edge>(i, j));
                }
            }

            edge = graph->getEdge(index_second, index_first).get();

            if(edge != nullptr) {
                if (weighted) {
                    auto id = dynamic_cast< Identifier * >(wedge->getWeight().get());
                    if(id)
                        ret->addEdge(make_shared<WeightedEdge>(j,i,
                                                               make_shared<Identifier>(id->getDeclaration())));
                }
                else {
                    ret->addEdge(make_shared<Edge>(j,i));
                }
            }


        }

    return ret;
}