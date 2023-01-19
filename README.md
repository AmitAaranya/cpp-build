# CPP

Installed SSH agent and Server in Windows Machine

````cmd
Get-WindowsCapability -Online | Where-Object Name -like 'OpenSSH*'

# Install the OpenSSH Client
Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0

# Install the OpenSSH Server
Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
````

````cmd
Set-Service -Name ssh-agent -StartupType Automatic
Set-Service -Name ssh-agent -Status Running

````
