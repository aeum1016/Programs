import Node
import sys

from sentence_transformers import SentenceTransformer
from sklearn.metrics.pairwise import cosine_similarity

class graph:
  names = set()

  vertices = []
  summaries = []
  sorted = []

  def __init__(self, name):
    self.name = name
    self.vertices = []
    self.summaries = []
    self.names = set()

  def addVertice(self, name, score, popularity, genres, summary):
    if not name in self.names:
      newNode = Node.node(name, score, popularity, genres, summary)
      self.vertices.append(newNode)
      self.names.add(name)
      self.summaries.append(newNode.summary)

  def printGraph(self):
    for node in self.vertices:
      print("Name: " + node.name)
      print(node.genres)
      print(node.edges)

  def computeEdges(self):
    for v1 in self.vertices:
      for v2 in self.vertices:
        relatedness = v2.score
        for genre in v1.genres:
          for genre2 in v2.genres:
            if genre == genre2:
              relatedness += 2.0/(len(v1.genres) + len(v2.genres))
        v1.addEdge(relatedness)

  def shortestDist(self, unvisited, distances):
    smallestValue = sys.maxsize
    smallest = -1
    for i in unvisited:
      if distances[i] < smallestValue:
        smallestValue = distances[i]
        smallest = i
    return smallest

  def djikstras(self, source):
      unvisited = {i for i in range(len(self.vertices))}
      distances = [sys.maxsize for i in range(len(self.vertices))]
      distances[source] = 0
      while len(unvisited) != 0:
        index = self.shortestDist(unvisited, distances)
        if index==-1: break
        baseDist = distances[index]
        unvisited.remove(index)
        for j in range(len(self.vertices[source].edges)):
          if len(unvisited.intersection({j})) != 0:
            if baseDist + (1/pow(self.vertices[index].edges[j], 1)) < distances[j]:
              distances[j] = baseDist + (1/pow(self.vertices[index].edges[j], 1))
      distancesSorted = sorted(distances)
      distancesSorted = distancesSorted[0:10]
      recommendations = []
      for distance in distancesSorted:
        for i in range(len(distances)):
          if distances[i] == distance:
            recommendations.append(self.vertices[i])
      self.vertices[source].recommendations = recommendations

  def sortFunc(self, e):
    return e.similarity

  def similarity(self, phrase):
    model = SentenceTransformer('bert-base-nli-mean-tokens')
    phrases = [phrase]
    allPhrases = phrases + self.summaries
    sentence_embeddings = model.encode(allPhrases)
    result = cosine_similarity(
    [sentence_embeddings[0]],
    sentence_embeddings[1:]
    )
    for i in range(0, len(self.vertices)-1):
        if self.vertices[i].summary.count(phrase) > 0:
            self.vertices[i].similarity = self.vertices[i].summary.count(phrase)
        else:
            self.vertices[i].similarity = result[0][i]
    self.sorted = self.vertices.copy()
    self.sorted.sort(key=lambda x: x.similarity, reverse=True)
   # sorted = sort(sorted, key=lamda x: x.similarity, reverse=false)
      #sorted['similarity']