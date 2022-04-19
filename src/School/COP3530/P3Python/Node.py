class node:

    def __init__(self, name, score, popularity, genres, summary):
        self.name = name
        self.score = score
        self.popularity = popularity
        self.genres = genres
        self.edges = []
        self.recommendations = []
        self.summary = summary
        self.similarity = 0.0

    def addEdge(self, weight):
        self.edges.append(weight)