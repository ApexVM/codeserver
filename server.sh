# Start a server on the VM!
UNDER_DEVELOPMENT <3

CDN_URL="https://apexvm.snares-gar.ts.net/cdn/"


# Download installer
curl -fsSL https://code-server.dev/install.sh | sh
# curl -fsSL https://apexvm.snares-gar.ts.net/cdn/.avm/scripts/install.sh | sh
clear
# Setup ApexVM RunCode domain systems
# Nuh uh, domains are your stuff

# Set up desktop environment
curl -fsSL CDN_URL/.avm/scripts/setupde.sh | sh
# Patch AVM script
mkdir ~/.avm
curl -fsSL CDN_URL/.avm/scripts/setupavm.sh | sh
