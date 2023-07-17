import requests
import json

# query = input("What type of news you want to see : ")
# url = f"https://newsapi.org/v2/everything?q={query}&from=2023-02-01&sortBy=popularity&apiKey=3441e250247942c0baef86b8c3546801"
# r = requests.get(url)
# # print(r.text)
# news = json.loads(r.text)
# # print(news)

# for article in news["articles"]:
#     print(article["title"])
#     print(article["description"])

url = "http://memebook.onrender.com"

r = requests.get(url)

print(r.text)
