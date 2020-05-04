import numpy as np 
from matplotlib import pyplot as plt 
import argparse


def calc_graph(args):
    f = open(args.file_path, "r")

    plt.title("Just some random Title") 
    plt.xlabel("Time")
    plt.ylabel("A2D")
    i = 0

    for line in f.readlines():
        if i > 10:
            try:
                split_line = line.split(", ")
                plt.scatter(split_line[1], split_line[0])
                i = 0
            except Exception:
                pass
        i += 1
    plt.show()


def main():
    parser = argparse.ArgumentParser(description='Show some graphs')
    parser.add_argument('--file',dest='file_path', type=str,
                        help='Path to data path')

    args = parser.parse_args()
    calc_graph(args)


if __name__ == "__main__":
    main()
