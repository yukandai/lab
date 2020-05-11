import argparse

parser = argparse.ArgumentParser(description='Calculadora python')
group = parser.add_mutually_exclusive_group(required='True')
group.add_argument('--suma','-s',action='store_true',default=False,help='Suma de operandos')
group.add_argument('--resta','-r',action='store_true',default=False,help='Resta de operandos')
group.add_argument('--div','-d',action='store_true',default=False,help='Division de operandos')
group.add_argument('--mul','-m',action='store_true',default=False,help='Multiplicacion de operandos')
parser.add_argument('operandos',action='store',nargs=2, type=float,metavar='N', help='Operandos del calculo')

args=parser.parse_args()

if args.suma==True:
    print(args.operandos[0]+args.operandos[1])
elif args.resta==True:
    print(args.operandos[0]-args.operandos[1])
elif args.div==True:
    print(args.operandos[0]/args.operandos[1])
elif args.mul==True:
    print(args.operandos[0]*args.operandos[1])


