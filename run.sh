
set -xe

if [ $# -eq 2 ]
then args="$1 $2"
else args=$1
fi
echo $args

make
time src/meshpro $args out.off+ # leafves
cp leaf.txt ../pine/
cd ../pine
matlab -nodisplay -nosplash -nodesktop -r "run('simu_pine_scan.m'); exit;"
cp exp.txt ../L3D/ # copying filtered leaf file
cp sonar_beam.txt ../L3D/ # copying sonar_beam location file 
cd ../L3D/
time src/meshview out.off+
