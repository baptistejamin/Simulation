COUNTER=0
WON=0

while [  $COUNTER -lt 100 ]; do

if ./project -no_sleep -silent -no_map -docteurs 6
then
let WON=WON+1
fi

let COUNTER=COUNTER+1
sleep 1
done
echo "Les medecins ont gagne $WON parties sur $COUNTER"
