import json

import Graph

all = Graph.graph("all")
dramas = Graph.graph("dramas")
animes = Graph.graph("animes")

with open("animes.json", "r", encoding='utf-8') as read_file:
  animeData = json.load(read_file)
with open("top_5000_mydramalist.json", "r", encoding='utf-8') as read_file:
  dramaData = json.load(read_file)

for drama in dramaData:
  rank = drama["ranking"]
  if rank <= 3000:
    genres = drama["genres"]
    score = drama["ratings"]
    summary = drama["synopsis"]
    all.addVertice(drama["name"], score/10, genres, summary)
    dramas.addVertice(drama["name"], score/10, genres, summary)

for anime in animeData:
  rank = anime["ranked"]
  if rank != None:
    if rank <= 25:
      genresRaw = anime["genre"]
      genresRaw = genresRaw[1:-1]
      genresRaw = genresRaw.split(", ")
      genres = []
      for genre in genresRaw:
        genre = genre[1:-1]
        genres.append(genre)
      score = float(anime["score"])
      summary = anime["synopsis"]
      all.addVertice(anime["title"], score/10, genres, summary)
      animes.addVertice(anime["title"], score/10, genres, summary)

animes.computeEdges()
# dramas.computeEdges()
# animes.printGraph()

similarities = animes.similarity("play volleyball in high school")
for i in range(0, len(animes.vertices)-1):
  print(animes.vertices[i].name + " " + str(animes.vertices[i].similarity))
