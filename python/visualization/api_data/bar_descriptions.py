import pygal

from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

style = LS('#333366', base_style=LCS)

chart = pygal.Bar(style=style, x_label_rotation=45, show_legend=False)
chart.title = 'Python Projects'
chart.x_labels = ['httpie', 'django', 'flask']

plot_dicts = [
    {'value': 16101, 'label': 'httpie description'},
    {'value': 15028, 'label': 'django description'},
    {'value': 14798, 'label': 'flask description'},
]

chart.add('', plot_dicts)
chart.render_to_file('bar_descriptions.svg')
