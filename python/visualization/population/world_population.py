import json

from pygal.style import LightColorizedStyle as LCS, RotateStyle as RS
from pygal.maps.world import World

from country_codes import get_country_code

filename = 'population_data.json'
with open(filename) as f:
    pop_data = json.load(f)

country_code_populations = {}
for pop_dict in pop_data:
    if pop_dict['Year'] == '2010':
        country_name = pop_dict['Country Name']
        population = int(float(pop_dict['Value']))
        code = get_country_code(country_name)
        if code:
            country_code_populations[code] = population
        else:
            print("Error - " + country_name)

cc_pops_1, cc_pops_2, cc_pops_3 = {}, {}, {}
for cc, population in country_code_populations.items():
    if population < 10000000:
        cc_pops_1[cc] = population
    elif population < 1000000000:
        cc_pops_2[cc] = population
    else:
        cc_pops_3[cc] = population

wm_style = RS('#336699', base_style=LCS)

wm = World(style=wm_style)
wm.title = "World Population in 2010, by Country"
wm.add("0-10m", cc_pops_1)
wm.add("10m-1b", cc_pops_2)
wm.add(">1bn", cc_pops_3)

wm.render_to_file("world_population.svg")
