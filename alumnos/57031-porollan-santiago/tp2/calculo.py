import argparse


def resta(a):
    return a[0] - a[1]


def mult(a):
    return a[0] * a[1]


def div(a):
    return a[0] / a[1]


# calculo s -t int 1 2
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='process some integers')
    parser.add_argument('nums', metavar='N', type=int, nargs='+', help='numeros para realizar un calculo')
    parser.add_argument('-t', '--tipo', dest="tipo", default=float, choices=['int', 'float'], help='tipo')
    parser.add_argument('-s', '--suma', dest='operator_s', action='store_const', const=sum, default=0, help='suma')
    parser.add_argument('-r', '--resta', dest='operator_r', action='store_const', const=resta, default=0, help='resta')
    parser.add_argument('-m', '--mult', dest='operator_m', action='store_const', const=mult, default=0, help='multiplicacion')
    parser.add_argument('-d', '--div', dest='operator_d', action='store_const', const=div, default=0, help='division')
    args = parser.parse_args()
    if (len(args.nums) != 2 or
       (args.operator_s and 1) + (args.operator_r and 1) + (args.operator_m and 1) + (args.operator_d and 1) != 1):
        raise Exception("Uso incorrecto.\nusage: calculo.py [-h] [-s] [-r] [-m] [-d] N [N ...]")
    args.tipo = int if args.tipo == 'int' else float
    print(args.tipo((args.operator_s or args.operator_r or args.operator_m or args.operator_d)(args.nums)))
