class node:

    def __init__(self, name, score, genres, summary):
        self.name = name
        self.score = score
        self.genres = genres
        self.edges = []
        self.summary = summary
        self.similarity = 0.0

    def addEdge(self, weight):
        self.edges.append(weight)