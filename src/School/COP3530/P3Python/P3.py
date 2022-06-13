from gettext import find
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
  if rank <= 500:
    genres = drama["genres"]
    score = drama["ratings"]
    summary = drama["synopsis"]
    popularity = drama["popularity_rank"]
    all.addVertice(drama["name"], score/10, popularity, genres, summary)
    dramas.addVertice(drama["name"], score/10, popularity, genres, summary)

for anime in animeData:
  rank = anime["ranked"]
  if rank != None:
    if rank <= 200:
      genresRaw = anime["genre"]
      genresRaw = genresRaw[1:-1]
      genresRaw = genresRaw.split(", ")
      genres = []
      for genre in genresRaw:
        genre = genre[1:-1]
        genres.append(genre)
      score = float(anime["score"])
      summary = anime["synopsis"]
      popularity = anime["popularity"]
      all.addVertice(anime["title"], score/10, popularity, genres, summary)
      animes.addVertice(anime["title"], score/10, popularity, genres, summary)

print("Welcome to the search for Dramas and Anime!")
print("1. Dramas")
print("2. Anime")
print("3. Both")
dataset = input("Please choose your dataset: ")
if (dataset == '1'):
    dramas.computeEdges()
    dataset = dramas
elif (dataset == '2'):
    animes.computeEdges()
    dataset = animes
elif (dataset == '3'):
    dataset = all
    all.computeEdges()
else:
    print("Not valid")
    
keywords = input("Please enter keywords to generate 10 most similar and relevant results from synopses:\n")
dataset.similarity(keywords)

results = dataset.sorted[0:10]

print("0. Sort by Relatedness")
print("1. Sort by Popularity")
print("2. Sort by Rating")
algorithm = input("How do you want your results sorted? ")
findSimilar = 0
while(findSimilar != -1):
  for i in range(48):
    print()
  if (algorithm == '0'):
      pass
  elif (algorithm == '1'):
      results = dataset.quickSort(results, "popularity")
  elif (algorithm == '2'):
      results = dataset.quickSort(results, "score")
      results = dataset.reverse(results)
  else:
      print("Not valid")
    

  print("Recommendations for " + recommendationsName + ":" if findSimilar != 0 else "Results:")


  for i in range(0, 10):
    print(str(i+1) + ". " + results[i].name + " | " + str(round(results[i].score*10,1)) + " stars | " + str(results[i].popularity) + " | " + str(results[i].similarity))


  findSimilar = input("Search similar results to one of the previous results? Choose 1-10 or -1 to quit: ")
  findSimilar = int(findSimilar)
  if findSimilar == -1:
    break
  recommendationsName = results[findSimilar-1].name
  for i in range(len(dataset.vertices)):
    if(dataset.vertices[i].name == recommendationsName):
      dataset.djikstras(i)
      results = dataset.vertices[i].recommendations
      results = results[0:10]
