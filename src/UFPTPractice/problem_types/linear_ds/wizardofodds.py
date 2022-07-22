i = input().split(' ')

if int(i[1]) > 350:
  print("Your wish is granted!")
elif pow(2, int(i[1])) >= int(i[0]):
  print("Your wish is granted!")
else:
  print("You will become a flying monkey!")