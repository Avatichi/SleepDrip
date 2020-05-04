# serpipe :)
import os
import serial
import argparse
import time
from progressbar import ProgressBar

def parse_params():
    parser = argparse.ArgumentParser(
        description='Read from serial to file')
    parser.add_argument("-d", "--device", dest="device", type=str,
                        help="Device to read from")
    parser.add_argument("-b", "--baudrate", dest="baudrate", type=str,
                        help="baudrate to read from device")
    parser.add_argument("-f", "--file", dest="file", type=str,
                        help="file to write to")
    parser.add_argument("-t", "--time", dest="time", type=str,
                        help="How much time to record in min")

    return parser.parse_args()


def serpipe(args):
    # start_time = time.time()
    pbar = ProgressBar()
    s = serial.Serial(args.device, args.baudrate)
    with open(args.file, "a") as f:
        #while start_time + (int(args.time) * 60) > time.time():
        for x in pbar(range(int(args.time) * 60)):
            temp = s.read_all()
            f.write(temp)
            time.sleep(1)

def main():
    args = parse_params()
    serpipe(args)
    os.system("spd-say 'Sample Done'")

if __name__ == "__main__":
    main()