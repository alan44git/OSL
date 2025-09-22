//  Assignment 1B
#!/bin/bash
addBk="AddressBook.txt"
touch $addBk
menu(){
echo "1.Add 2.Update"
}
addContact(){
echo -n "Name: "
read name
echo -n "Phone: "
read phone
echo -n "Email: "
read email
if grep -q "|$phone|" $addBk;
then
echo "Already exists"
else
echo "$name|$phone|$email" >> $addBk

fi
}
viewContacts(){
if [[ ! -s $addBk ]] ;
then
echo "No contacts"
else
echo "All contacts"
column -t -s '|' "$addBk"

fi
}
updateContact(){
read -p "Enter phone number to update: " phone
if grep -q "|$phone|" "$addBk" ; then
read -p "New Name: " name
read -p "New Email: " email
sed -i "/|$phone|/c\\$name|$phone|$email" "$addBk"
echo "Contact updated."
else
echo "Contact not found."
fi
}
deleteContact(){
read -p "Enter phone number to delete: " phone
if grep -q "|$phone|" "$addBk"; then
sed -i "/|$phone|/d" "$addBk"
echo "Contact deleted."
else
echo "Contact not found."
fi
}
