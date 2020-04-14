
import argparse
parser = argparse.ArgumentParser(usage="./calculo.py -t type [s|r|m|d] arg1" +
                                 " arg2")

parser.add_argument("-s", "--suma", help="suma arg1 + arg2", type=float)
parser.add_argument("-r", "--resta", help="resta arg1 + arg2", type=float)
parser.add_argument("-m", "--multi", help="multiplica arg1 * arg2", type=float)
parser.add_argument("-d", "--div", help="divide arg1 / arg2", type=float)
parser.add_argument("-t", "--tipo", help="Desea int o float?")
parser.add_argument("y", type=float, help="Segundo argumento")

args = parser.parse_args()

if args.tipo == 'float':
    if args.suma:
        print((args.suma) + (args.y))
    if args.resta:
        print((args.resta) - (args.y))
    if args.multi:
        print((args.multi) * (args.y))
    if args.div:
        print((args.div) / (args.y))


if args.tipo == 'int':
    if args.suma:
        print(int(args.suma) + int(args.y))
    if args.resta:
        print(int(args.resta) - int(args.y))
    if args.multi:
        print(int(args.multi) * int(args.y))
    if args.div:
        print(int(args.div) / int(args.y))
