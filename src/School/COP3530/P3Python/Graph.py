import Node

from sentence_transformers import SentenceTransformer
from sklearn.metrics.pairwise import cosine_similarity

class graph:
  names = set()

  vertices = []
  summaries = []

  def __init__(self, name):
    self.name = name
    self.vertices = []
    self.summaries = []
    self.names = set()

  def addVertice(self, name, score, genres, summary):
    if not name in self.names:
      newNode = Node.node(name, score, genres, summary)
      self.vertices.append(newNode)
      self.names.add(name)
      self.summaries.append(newNode.summary)

  def printGraph(self):
    for node in self.vertices:
      print("Name: " + node.name)
      print(node.genres)
      print(node.edges)

  def computeEdges(self):
    count = 0
    for v1 in self.vertices:
      if count % 100 == 0: 
        print(count)
      for v2 in self.vertices:
        relatedness = v2.score
        for genre in v1.genres:
          for genre2 in v2.genres:
            if genre == genre2:
              relatedness += 2.0/(len(v1.genres) + len(v2.genres))
        v1.addEdge(relatedness)
      count += 1

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
      self.vertices[i].similarity = result[0][i]
    return result
      