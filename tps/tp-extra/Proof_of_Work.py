import hashlib
from datetime import datetime
d = datetime.today()
t = int(d.timestamp())
data = 'Hola Mono!'
prevHash = '0'
maxLoops = 100000000
difficulty = 5
breakCondition = '0' * difficulty
for idx in range(1, maxLoops):
    s = str(str(t) + data + str(idx) + prevHash).encode('utf-8')
    hash = hashlib.sha256(s)
    hash = hash.hexdigest()    
    if hash[0:difficulty] == breakCondition:
        print('HASH: ' + hash)
        print('Idx: ' + str(idx))
        break
