# An Email slicer is a very useful program for separating the username and domain name of an email address

email = input("Enter your mail address: ").strip()
# strip removes leading & trailing spaces
username = email[:email.index('@')].capitalize()
# capitalizes the first letter of username
domain_name = email[email.index('@')+1:]
format = print(f"Username is: '{username}' \nDomain name is : '{domain_name}'")
print(format)