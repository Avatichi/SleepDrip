import numpy as np 
from matplotlib import pyplot as plt 
import argparse


def calc_graph(args):
    f = open(args.file_path, "r")

    plt.title("DATA!") 
    plt.xlabel("Time") 
    plt.ylabel("A2D")
    i = 0
    for line in f.readlines():
        split_line = line.split(", ")
        plt.scatter(split_line[0], split_line[1])

    plt.show()


def main():
    parser = argparse.ArgumentParser(description='Show some graphs')
    parser.add_argument('--file',dest='file_path' type=str,
                        help='Path to data path')

    args = parser.parse_args()
    calc_graph(args)