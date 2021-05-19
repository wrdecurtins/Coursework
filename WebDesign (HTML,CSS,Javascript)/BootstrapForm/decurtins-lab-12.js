"use strict";
/* define regular expressions for each type to be validated */
const datePattern = /^((0[13578]|1[02])[\/.]31[\/.](18|19|20)[0-9]{2})|((01|0[3-9]|1[1-2])[\/.](29|30)[\/.](18|19|20)[0-9]{2})|((0[1-9]|1[0-2])[\/.](0[1-9]|1[0-9]|2[0-8])[\/.](18|19|20)[0-9]{2})|((02)[\/.]29[\/.](((18|19|20)(04|08|[2468][048]|[13579][26]))|2000))$/;
const emailPattern = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.edu$/;
const phonePattern = /^\(\d{3}\) \d{3}\.\d{4}$/;
const zipPattern = /^[0123456789]{5}-[0123456789]{4}$/;

$(document).ready(() =>{
   /* set constants for each element we will manipulate */
   const form = $('#form');
   const txtEmail = $('#email');
   const txtPhone = $('#phone');
   const txtZip = $('#zip');
   const txtDOB = $('#dob');
   const btnSaveProfile = $('#save');

   /* define a boolean to determine if the form is valid or not */
   let isValid;

   /* function to set form and element to invalid*/
   const makeInvalid = (textbox, message) => {
        /* set the validation message */
        textbox.next().text(message);
        /* set the element to invalid and remove isvalid class */
        textbox.removeClass('is-valid');
        textbox.addClass('is-invalid');
        /* set our validation bool to false */
        isValid = false;
        /* change the form border from green to red */
        form.removeClass('border-success');
        form.addClass('border-danger');
        /* change the validation button from green to red */
        btnSaveProfile.removeClass("btn-success");
        btnSaveProfile.addClass("btn-danger");
   };

   /* function to set element to valid */
    const makeValid = (textbox) => {
        /* remove any validation error messages */
        textbox.next().text("");
        /* set the element to isvalid and remove isInvalid */
        textbox.removeClass('is-invalid');
        textbox.addClass('is-valid');
        /* if the form is valid, change the form border and button to green */
        if (isValid) {
            form.removeClass('border-danger');
            form.addClass('border-success');
            btnSaveProfile.removeClass("btn-danger");
            btnSaveProfile.addClass("btn-success");
        };
    };

    /* select and focus the top textbox */
    txtEmail.select().focus();

    /* on click handler for the validate button */
    $('#save').on('click', (evt) => {

        /* set the validation bool to true */
        isValid = true;

        /* set constants for the trimmed values of each form field */
        const email = txtEmail.val().trim();
        const phone = txtPhone.val().trim();
        const zip = txtZip.val().trim();
        const dob = txtDOB.val().trim();

        /* validate each entry based on an appropriate regex and display appropriate errors */
        !emailPattern.test(email) ?
            makeInvalid(txtEmail,'Please enter an email address that ends in .edu') : makeValid(txtEmail);
        !phonePattern.test(phone) ?
            makeInvalid(txtPhone,'Please enter a phone number in the (###) ###.#### format.') : makeValid(txtPhone);
        !zipPattern.test(zip) ?
            makeInvalid(txtZip,'Please enter a zip code in the #####-#### format.') : makeValid(txtZip);
        if (!datePattern.test(dob))
            makeInvalid(txtDOB,'Please enter a date in the MM/DD/YYYY format.');
        else if (Date.parse(dob) > Date.now())
            makeInvalid(txtDOB,'Please enter a date in the past.');
        else
            makeValid(txtDOB);

       // If all entries are valid
       if (isValid) {
           //create an array to store now profile
           const lab12info = [];
           //populate the array with the user provided data
           lab12info['email-address'] = email;
           lab12info['phone-number'] = phone;
           lab12info['zip-code'] = zip;
           lab12info['date-of-birth'] = dob;

           //create an empty session variable
           sessionStorage.lab12info = '';

           //for loop that populates the session array
           for (let i in lab12info) {
               sessionStorage.lab12info += i + '=' + lab12info[i] + '|';
           }

           //navigate to the profile save success page
           location.href = 'profile.html';
       }

        /* select and focus the first textbox */
        txtEmail.select().focus();
    });
});