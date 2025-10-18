#include <iostream>
#include <vector>
#include "src/parser/config/proxy.h"
#include "src/parser/subparser.h"

int main() {
    std::vector<Proxy> nodes;
    
    // Test parsing the hysteria2 configuration
    std::string config = R"(
proxies:
  - name: "AU A"
    type: hysteria2
    server: au.example.com
    ports: "50000-60000"
    password: "test123"
    sni: au.example.com
    skip-cert-verify: true
    alpn:
      - h3
)";
    
    try {
        YAML::Node yamlnode = YAML::Load(config);
        explodeClash(yamlnode, nodes);
        
        if (nodes.size() > 0) {
            std::cout << "Successfully parsed node: " << nodes[0].Remark << std::endl;
            std::cout << "Server: " << nodes[0].Hostname << std::endl;
            std::cout << "Port: " << nodes[0].Port << std::endl;
            std::cout << "Ports: " << nodes[0].Ports << std::endl;
            std::cout << "Type: " << getProxyTypeName(nodes[0].Type) << std::endl;
        } else {
            std::cout << "No nodes parsed!" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}