# codeserver
## Scripts to install and manager for Apex VM code server along with web servers and all hosts and domains.

### What, why, how
RunCode is Apex VM hyper virtualized coding platform capable of handling multiple users, terminals, apps and port forwading! We built it on code-server (VS Code application on web, like Codespaces). We always wanted to provide "free" VMs for everyone and let anyone do what they love the most!

### Self-hostable
***RunCode frontend*** is **fully selfhostable** - just host a code-server instance! But backend - all VMs, services, apps ***are not***. We can look through your instances to make sure you ***are NOT*** hosting illegal (we want to make sure Apex VM users are safe).
To self-host frontend, open your RunCode instance and execute:
```
sysdump --all
```
This will dump all frontend files to ~/.avm/temp/ allowing you to copy the files but it also dumps backend so please don't copy avm files.

### Available systems
Currently RunCode supports all Linux machines. Most likely ***we won't*** support Windows due to security leaks and lack of VMs.

Current VM list:

-Ubuntu ARM64 (16.04-22.04)

-Arch ARM64

-Alpine (x64 and ARM64)

-Debian (10-12)

-RaspbianOS (armhw only)

-Devuan (ARM64 only)

-VMware Proton (ARM64 only)

-PostmarketOS - this system is in BETA stage, only available for testers

**Some of those systems are self-hosted on various hosts, depending on who's in the "HQs" we may or may not provide some of those systems.**

### Port-forwading
We use uh... ApexNET? yeah that's it, we use our domains to forwad port 8080 of your instance on 8443 to allow you test your app, we also support VS Code forwader. 

To use port-forwader you can run:
```
avm --forwad
```
It will forwad port 8080 on port 8443 of your RunCode domain.

### Running heavy apps
By default, RunCode automatically detects apps that use 50% (or more) of CPU and terminates them allowing us to save resources. 

If you need to test your app or compile something, you can temporarily disable CPU limiter allowing you to compile your app. 

To disable CPU limiter you need to have SUDO rights and edit your RunCode config file 
```
sudo nano ~/.avm/runcode-avm.conf
```
There, you have to disable the CPU limiter, it should look like this:
```
USE_MODULE CPULIMITER.avm TRUE
```
Change this to **FALSE**. Then you have to re-load your environment (yes it WILL kill your session but it is needed to prevent systems from banning you)

To restart your session run:
```
avmservice --reload
```
Wait few seconds and you can now compile your apps!

### Running Docker, containers, VMs, servers
RunCode by default has pre-installed tools for running Docker containers and allowing you deploying Docker apps directly on RunCode instance! But, almost all of our instances **do not** support **KVM** which means you cannot run VMs (or they will run very slowly). 

You can also run servers like Nginx, Apache, Python webserver and others. If the server isn't taking 50% of CPU then it's fine but if it does, we have the rights to terminate your VM.

### Using desktop environments
Woah calm down, okay? This may be okay but is illegal on RunCode systems. However you can "patch" avm to run DEs on your instance, check [Running DEs on RunCode instance](https://github.com/ApexVM/codeserver/tree/feat/de) .

### Using remote administration tools
Using any tools that are designed to gain access to the computers are **FORBITTEN**. RunCode itself is SSH and VS Code server so why do you need another SSH client? Just start new terminal -_-

If you want to use any remote control apps like anydesk or rustdesk, they are not allowed too unless they're offically supported on Apex VM's site. However RunCode supports noVNC :)
