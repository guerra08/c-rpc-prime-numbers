$script = <<-SCRIPT
sudo apt update
sudo apt upgrade -y
sudo apt install -y build-essential
SCRIPT

Vagrant.configure("2") do |config|
    config.vm.box = "geerlingguy/debian10"
    config.vm.synced_folder ".", "/home/vagrant/dev"
    config.vm.provision "shell", inline: $script, privileged: false
end