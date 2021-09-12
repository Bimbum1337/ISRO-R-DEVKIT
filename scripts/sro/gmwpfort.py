from dataclasses import dataclass
from dataclasses_json import dataclass_json
import struct


@dataclass_json
@dataclass
class Waypoint:
    name: str
    region: int
    x: float
    y: float
    z: float
    unknown: int


def read(path: str) -> list:
    file = open(path, "rb")

    number_of_entries = struct.unpack("i", file.read(4))[0]

    waypoints = list()

    for i in range(number_of_entries):
        name = _read_string(file)
        region, x, y, z, e = struct.unpack("ifffi", file.read(20))

        waypoints.append(Waypoint(name, region, x, y, z, e))

    return waypoints


def write(path: str, waypoints: list):
    with open(path, "wb") as f:
        f.write(struct.pack("i", len(waypoints)))

        for waypoint in waypoints:
            f.write(struct.pack("i", len(waypoint.name)))
            f.write(waypoint.name.encode())
            f.write(struct.pack("ifffi", waypoint.region, waypoint.x, waypoint.y, waypoint.z, waypoint.unknown))


def _read_string(f):
    length = struct.unpack("i", f.read(4))[0]
    raw_data = f.read(length)
    return raw_data.decode()
