<<<<<<< HEAD
package com.example.programs;

import java.util.ArrayList;

public class ContactManagerProgram {
    static class Contact {
        String email;
        String name;
        String phoneNumber;

        Contact(String name, String phoneNumber, String email) {
            this.name = name;
            this.email = email;
            this.phoneNumber = phoneNumber;
        }

        public String getEmail() {
            return email;
        }
        public void setEmail(String email) {
            this.email = email;
        }
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
        public String getPhonenumber() {
            return phoneNumber;
        }
        public void setPhonenumber(String phoneNumber) {
            this.phoneNumber = phoneNumber;
        }
    }

    static class ContactManager {
        ArrayList<Contact> myContacts;

        ContactManager() {
            myContacts = new ArrayList<>();
        }

        void addContact(Contact contact){
            myContacts.add(contact);
        }

        Contact searchContact(String searchName){
            for(Contact i: myContacts){
                if(i.name.equals(searchName)){
                    return i;
                }
            }
            return null;
        }


    }

    public static void main(String [] args){
        ContactManager myContactManager = new ContactManager();

        Contact James = new Contact("James", "0012223333", "james@email.com");
        Contact Cezanne = new Contact("Cezanne", "987654321", "cezzane@email.com");

        myContactManager.addContact(James);
        myContactManager.addContact(Cezanne);

        Contact result = myContactManager.searchContact("James");
        System.out.println(result.phoneNumber);
    }
}
=======
package com.example.programs;

import java.util.ArrayList;

public class ContactManagerProgram {
    static class Contact {
        String email;
        String name;
        String phoneNumber;

        Contact(String name, String phoneNumber, String email) {
            this.name = name;
            this.email = email;
            this.phoneNumber = phoneNumber;
        }

        public String getEmail() {
            return email;
        }
        public void setEmail(String email) {
            this.email = email;
        }
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
        public String getPhonenumber() {
            return phoneNumber;
        }
        public void setPhonenumber(String phoneNumber) {
            this.phoneNumber = phoneNumber;
        }
    }

    static class ContactManager {
        ArrayList<Contact> myContacts;

        ContactManager() {
            myContacts = new ArrayList<>();
        }

        void addContact(Contact contact){
            myContacts.add(contact);
        }

        Contact searchContact(String searchName){
            for(Contact i: myContacts){
                if(i.name.equals(searchName)){
                    return i;
                }
            }
            return null;
        }


    }

    public static void main(String [] args){
        ContactManager myContactManager = new ContactManager();

        Contact James = new Contact("James", "0012223333", "james@email.com");
        Contact Cezanne = new Contact("Cezanne", "987654321", "cezzane@email.com");

        myContactManager.addContact(James);
        myContactManager.addContact(Cezanne);

        Contact result = myContactManager.searchContact("James");
        System.out.println(result.phoneNumber);
    }
}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
