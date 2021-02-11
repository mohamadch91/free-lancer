
from wordcloud import WordCloud, STOPWORDS
import matplotlib.pyplot as plt
import wikipedia
import re
import string

text = input("please input your text: ")
b = string.punctuation
for char in b:
    text = text.replace(char, ' ')

finaltext = text.replace('\n', '')


uninteresting_words = ["the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my", \
    "we", "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its", "they", "them", \
    "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was", "were", "be", "been", "being", \
    "have", "has", "had", "do", "does", "did", "but", "at", "by", "with", "from", "here", "when", "where", "how", \
    "all", "any", "both", "each", "few", "more", "some", "such", "no", "nor", "too", "very", "can", "will", "just"]

resultwords = [word for word in re.split("\W+",finaltext) if word.lower() not in uninteresting_words]

result = ' '.join(resultwords)

print(result)

# def Gcloud(wordcloud):
#
#     plt.figure(figsize=(40, 30))
#
#     plt.imshow(wordcloud)
#
#     plt.axis("off")
#
# mycloudpic = WordCloud(
#                         width = 3000, height = 2000, random_state=1,
#                         background_color='black', colormap='Set2',
#                         collocations=False,
#                         stopwords = STOPWORDS).generate(result)
# Gcloud(mycloudpic)
# mycloudpic.to_file("mycloud.png")
#

