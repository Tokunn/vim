#!/usr/bin/env python3.2
import sys

infa_path = "/etc/network/interfaces"
help_path = "./ip/help"


def uses(): #uses error message
    argvs = sys.argv
    print("\n" + "*"*50)
    print("   Please type: " + argvs[0] + " <-help>")  #print uses
    print("*"*50 + "\n")
    quit()

def help_def(): #show help
    help_file = open(help_path, "r", encoding="utf-8")   #open help file
    help_mes = help_file.read()
    print(help_mes)
    quit()

def set_ip(plase):
    set_path = "./ip/infa" + plase

    set_file = open(set_path, "r", encoding="utf-8") #open HOME setting file
    comm = set_file.read()
    set_file.close()
    interfaces = open(infa_path, "w", encoding="utf-8")  #write interface file
    interfaces.write(comm)
    interfaces.close()

def main():
    argvs = sys.argv
    argc = len(argvs)
    if (argc == 1): #argc check (default)
        set_ip("-r")
    elif (argc != 2): #argc check
        uses()
    elif (argvs[1] == "-help"):   #check help
        help_def()
    elif (argvs[1] != "-h") and (argvs[1] != "-n") and (argvs[1] != "-r") and (argvs[1] != "-help"): #argv check
        uses()
    else:
        set_ip(argvs[1])    #call set_ip

    print("Please reboot now!")


if __name__ == '__main__':
    try:
        main()
    except IOError:
        print("\n" + "*"*50)
        print("++\tPlease run this script with sudo\t++")
        print("*"*50 + "\n")
