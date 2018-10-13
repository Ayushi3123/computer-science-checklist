import requests
import pygal

from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
print("Status code:", r.status_code)

response_dict = r.json()

print("Total Repositories:", response_dict['total_count'])

repo_dicts = response_dict['items']

names, plot_dicts = [], []
for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    plot_dicts.append({
        'value': repo_dict['stargazers_count'],
        'label': repo_dict['description'] if repo_dict['description'] is not None else '',
        'xlink': repo_dict['html_url']
    })

style = LS('#333366', base_style=LCS)

config = pygal.Config()
config.x_label_rotation = 45
config.show_legend = False
config.title_font_size = 24
config.label_font_size = 14
config.major_label_font_size = 18
config.truncate_label = 15
config.show_y_guides = False
config.width = 1000

chart = pygal.Bar(config, style=style)
chart.title = "Most Starred Python Projects - Github"
chart.x_labels = names

chart.add('', plot_dicts)

chart.render_to_file('python_repos.svg')
