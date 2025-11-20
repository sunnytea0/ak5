cmd_/home/vboxuser/lab5/Module.symvers := sed 's/\.ko$$/\.o/' /home/vboxuser/lab5/modules.order | scripts/mod/modpost -m -a  -o /home/vboxuser/lab5/Module.symvers -e -i Module.symvers   -T -
