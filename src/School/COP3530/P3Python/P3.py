import json
import time

import Graph

all = Graph.graph("all")
dramas = Graph.graph("dramas")
animes = Graph.graph("animes")

startTime = time.asctime( time.localtime(time.time()) )

with open("animes.json", "r", encoding='utf-8') as read_file:
  animeData = json.load(read_file)
with open("top_5000_mydramalist.json", "r", encoding='utf-8') as read_file:
  dramaData = json.load(read_file)

loadTime = time.asctime( time.localtime(time.time()) )

for drama in dramaData:
  rank = drama["ranking"]
  if rank <= 500:
    genres = drama["genres"]
    score = drama["ratings"]
    summary = drama["synopsis"]
    all.addVertice(drama["name"], score/10, genres, summary)
    dramas.addVertice(drama["name"], score/10, genres, summary)

for anime in animeData:
  rank = anime["ranked"]
  if rank != None:
    if rank <= 500:
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

addTime = time.asctime( time.localtime(time.time()) )
animes.computeEdges()
dramas.computeEdges()
all.computeEdges()
computeTime = time.asctime( time.localtime(time.time()) )
animes.similarity("basketball go bounce")
for i in range(0, 10):
  print(animes.sorted[i].name + " " + str(animes.sorted[i].similarity))
endTime = time.asctime( time.localtime(time.time()) )
print(startTime)
print(loadTime)
print(addTime)
print(computeTime)
print(endTime)

