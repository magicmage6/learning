
score_dict = {}

score_dict['jason'] = 10
score_dict['amy'] = 20
score_dict['yu'] = 100

for name in score_dict.keys():
    print(f'name {name} score {score_dict[name]}')

for name, score in score_dict.items():
    print(f'name {name} score {score}')

score_yu = score_dict['yu']
print(f'score of yu is {score_yu}')

score_jason = score_dict.get('jason')
print(f'score of jason is {score_jason}')

score_wrongname = score_dict.get('wrongname')
print(f'score of wrongname is {score_wrongname}')
if score_wrongname is None:
    print('can not find score for wrongname')
if 'wrongname' not in score_dict:
    print('can not find score for wrongname')

# score_x = score_dict['x']

age_dict = {
   'Yu': 45,
   'Jason': 19,
   'Amy': 15,
   'Julius': 17,
}

print(age_dict)