
import os
from os import path

content = """
This is an exmple.
Anything can be here.
"""

file_name = 'example.txt'

with open(file_name , 'w') as f:
    f.write(content)

new_content = """
This is new content.
It will replace the old one.
"""

with open(file_name, 'w') as f:
    f.write(new_content)

with open(file_name, 'a') as f:
    f.write('A new line.')

with open(file_name) as f:
    file_content = f.read()

print(file_content)

if not path.exists('output'):
    os.makedirs('output')

with open('output/new.txt', 'w') as f:
    f.write('Some thing new.')


html_content = """
<html>
  <a href="http://www.google.com">Link to Google.</a>
</html>
"""

with open('output/example.html', 'w') as f:
    f.write(html_content)


