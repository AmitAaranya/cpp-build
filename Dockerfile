# escape=`

# Use the latest Windows Server Core 2022 image.
FROM mcr.microsoft.com/windows/servercore:ltsc2022
# FROM build2

# Restore the default Windows shell for correct batch processing.
SHELL ["Powershell"]

COPY .\dotnet\ C:\dotnet\

RUN Move-Item -Path C:\dotnet -Destination 'C:\Program Files\dotnet\'
# RUN powershell -command $Env:PATH += ";C:\Program Files\dotnet"
RUN setx path '%path%;C:\Program Files\dotnet'
RUN dotnet tool install --global wix --version 4.0.0-rc.1
# RUN $Env:PATH += ";C:\Users\ContainerAdministrator\.dotnet\tools\"
RUN setx path '%path%;C:\Users\ContainerAdministrator\.dotnet\tools\'


ENTRYPOINT ["powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass"]

