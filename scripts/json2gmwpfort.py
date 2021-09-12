from sro import gmwpfort
import json

settingsfolder = "../BinOut/RelWithDebInfo/setting/"

with open(settingsfolder + "gmwpfort.json") as f:
    waypoints = [gmwpfort.Waypoint.from_dict(point) for point in json.load(f)]
    gmwpfort.write(settingsfolder + "gmwpfort.dat", waypoints)
