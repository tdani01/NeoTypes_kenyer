#!bin/bash
CURR_PATH=$(pwd)
NEOTYPES_GIT="git@github.com:tdani01/NeoTypes_kenyer.git"
#Remove lib
echo "Removing old lib..." 
sudo rm -rf $CURR_PATH/NeoTypes
#cd $CURR_PATH &&
if [ $? -eq 0 ]; then
    echo "Lib removed, installing new!"
    git clone $NEOTYPES_GIT $CURR_PATH/NeoTypes
    cd $CURR_PATH/NeoTypes
    echo "Deleting unneccessary files"
    sudo rm -r Sample
    echo "Update was successful."
    echo "PATH: "$CURR_PATH
    exit 0
else
    echo "Update failed."
    echo "Error code: "$?
    exit 1
fi
