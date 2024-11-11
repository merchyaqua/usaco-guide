import requests

url = 'https://10.1.1.14:80'
myobj = {'somekey': 'somevalue'}

x = requests.post(url, data = myobj)

print(x.text)