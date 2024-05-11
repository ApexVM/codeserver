# A file to set up domain for your RunCode instance

# Set up and start tailscale
echo ~/.tailscaled > "tailscaled --tun=userspace-networking --socks5-server=localhost:1055 --outbound-http-proxy-listen=localhost:1055 &"
sudo bash ~/.tailscaled &
# Set up and start code server and domain
