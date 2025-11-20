cmd_/home/vboxuser/lab5/modules.order := {   echo /home/vboxuser/lab5/hello1.ko;   echo /home/vboxuser/lab5/hello2.ko; :; } | awk '!x[$$0]++' - > /home/vboxuser/lab5/modules.order
