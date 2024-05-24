# Enable VNC and Desktop Environment for your RunCode instance

CDN_URL="https://apexvm.snares-gar.ts.net/cdn/"

# Install XFCE4
sudo apt-get install -y xfce4 xfce4-session tigervnc-standalone-server
# Set up VNC and start session
vncserver :1 -xstartup /usr/bin/startxfce4 -localhost no -SecurityTypes none --I-KNOW-THIS-IS-INSECURE -geometry 1024x768
# Patch forwader
curl CDN_URL/.avm/runcode/forwader.sh -o avmforwader.sh
mv avmforwader ~/.avm/forwad.avm
touch ~/.avm/modules/forwader.avm
cp ~/.avm/forwad.avm ~/.avm/modules/forwader.avm

# Push avm scripts
echo "vncserver :1 -xstartup /usr/bin/startxfce4 -localhost no -SecurityTypes none --I-KNOW-THIS-IS-INSECURE -geometry 1024x768" > ~/.avm/vnc.avm
echo "vncserver -kill :1" > ~/.avm/killvnc.avm
touch ~/.avm/modules/vncserver.avm
# Patch AVM manager
curl CDN_URL/.avm/runcode/avm.cxx -o avm.cxx
g++ avm.cxx -o avm
sudo mv avm /usr/local/bin/avm && sudo chmod 777 /usr/local/bin/avm
# Clean terminal and show system config
clear && bash .avm/info.avm
