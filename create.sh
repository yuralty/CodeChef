if [ -d $1 ]; then
    echo "$1 already exist"
else
    cp -r template $1
    cd $1
fi
