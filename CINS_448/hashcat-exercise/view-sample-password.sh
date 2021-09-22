#!/bin/bash
#
# create (and destroy) a user account, in order to
# capture and display its password as stored in /etc/shadow
# and compare it the the password's pure hash
#
# david morgan 8/2014
#

clear
if [ $(id -u) -ne 0 ];then echo "This script must be run as root"; exit 1; fi

echo -n "Please supply a password: "; read password

user=testuser$RANDOM
useradd $user
echo -en "$password\n$password\n" | passwd $user &> /dev/null
record=$( tail -1 /etc/shadow )
userdel $user

passfield=$( echo $record | awk -F : '{print $2}' )

hashtype=$( echo $passfield | awk -F $ '{print $2}' )
salt=$( echo $passfield | awk -F $ '{print $3}' )
storedpass=$( echo $passfield | awk -F $ '{print $4}' )


echo -en "\nThis is the password record generated in /etc/shadow for a new user with your chosen password: \n\t$record"
echo -en "\nand this is its password related field: \n\t"; echo $record | awk -F : '{print $2}'
echo -en "\n...and these are that password field's components:\n" 
echo -en "hash-type code                $hashtype"
case $hashtype in
	1 )
		echo ' (md5)'
		;;
	5 )
		echo ' (sha-256)'
		;;
	6)
		echo ' (sha-512)'
		;;
esac
echo -e "salt                          $salt"
echo -e "stored/scrambled password     $storedpass"
echo



saltedpassword=$( echo ${salt}${password} )
echo -e "Salted password (password prefixed with salt):\n\t$saltedpassword"
case $hashtype in
	6 )
	echo -en "pure sha512 hash of this salted password:\n\t"
	purehash=$(echo -n $saltedpassword | sha512sum | cut -d " " -f 1)
	;;
	5 )
	echo -en "pure sha256 hash of this salted password:\n\t"
	purehash=$(echo -n $saltedpassword | sha256sum | cut -d " " -f 1)
	;;
	1 )
	echo -en "pure md5 hash of this salted password:\n\t"
	purehash=$(echo -n $saltedpassword | md5sum | cut -d " " -f 1) 
	;;
esac
echo $purehash

cat<<EOF

Note that password processing with a given hash algorithm does something
OTHER than merely hash with that algorithm, as shown by the fact that 
the stored/processed password ($storedpass)
and the pure hash ($purehash)
are NOT the same.

( see  man 3 crypt  and  man mkpasswd )

EOF
