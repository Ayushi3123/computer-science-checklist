from pygal.maps.world import COUNTRIES


def get_country_code(country_name):
    """Return 2-digit country code for a country name"""
    for code, name in COUNTRIES.items():
        if name == country_name:
            return code

    return None
