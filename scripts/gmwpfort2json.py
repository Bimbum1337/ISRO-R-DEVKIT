from sro import gmwpfort
import json
import dataclasses


class EnhancedJSONEncoder(json.JSONEncoder):
    def default(self, o):
        if dataclasses.is_dataclass(o):
            return dataclasses.asdict(o)
        return super().default(o)


settingsfolder = "../BinOut/RelWithDebInfo/setting/"

waypoints = gmwpfort.read(settingsfolder + "gmwpfort.dat")

with open(settingsfolder + "gmwpfort.json", "w") as f:
    f.write(json.dumps(waypoints, cls=EnhancedJSONEncoder))
