"use strict";
const datePattern = /^((0[13578]|1[02])[\/.]31[\/.](18|19|20)[0-9]{2})|((01|0[3-9]|1[1-2])[\/.](29|30)[\/.](18|19|20)[0-9]{2})|((0[1-9]|1[0-2])[\/.](0[1-9]|1[0-9]|2[0-8])[\/.](18|19|20)[0-9]{2})|((02)[\/.]29[\/.](((18|19|20)(04|08|[2468][048]|[13579][26]))|2000))$/;
const emailPattern = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/;
const phonePattern = /^\d{3}-\d{3}-\d{4}$/;

$(document).ready( () => {
    /* set a bool to tell if form is valid*/
    let isValid;
    /* set a const for text boxes*/
    const arrivalDate = $('#arrival-date');
    const nights = $('#nights');
    const name = $('#name');
    const email = $('#email');
    const phone = $('#phone-number');

    /* declare function to set validation messages and mark entries as invalid*/
    const makeInvalid = (textBox, message) => {
        /* display validation message */
        textBox.next().text(message);
        /* create red box around invalid entries */
        textBox.addClass('is-invalid');
        /* set bool as false to prevent submissions*/
        isValid = false;
    }
    /* declare function to empty validation messages and mark entries as valid*/
    const makeValid = (textBox) => {
        /* remove any validation message after textbox */
        textBox.next().text("");
        /* remove red box around valid entry */
        textBox.removeClass('is-invalid');
    }

    /* handle the onclick for the submit button*/
    $('#make-reservation').on( 'click', (e) => {
        /* form set to valid until proven otherwise */
        isValid = true;

        /* create a constant for the values of textboxes */
        const arrivalDateVal = arrivalDate.val().trim();
        const nightsVal = nights.val().trim();
        const nameVal = name.val().trim();
        const emailVal = email.val().trim();
        const phoneVal = phone.val().trim();

        /* if the arrivaldate is empty mark as invalid*/
        if (arrivalDateVal === ""){
            makeInvalid(arrivalDate,"This field is required");
        }
        /* if the date is not the correct format mark as invalid */
        else if (datePattern.test(arrivalDateVal) === false){
            makeInvalid(arrivalDate,"Incorrect formatting, please use DD/MM/YYYY");
        }
        /* if the date is in the past mark as invalid */
        else if (Date.parse(arrivalDateVal) < Date.now()){
            makeInvalid(arrivalDate,"Date must be in the future")
        }
        /* if the date passes validation mark as valid */
        else{ makeValid(arrivalDate); }

        /* if nights is empty mark as invalid */
        if (nightsVal === ""){
            makeInvalid(nights,"This field is required");
        }
        /* if nights is not a number mark as invalid */
        else if (isNaN(nightsVal)){
            makeInvalid(nights,"This field must be numeric");
        }
        /* if nights is greater than 30 mark as invalid */
        else if (nightsVal > 30){
            makeInvalid(nights,"Please enter a number equal to or less than 30");
        }
        /* if nights passes validation mark as valid*/
        else { makeValid(nights); }

        /* if the name is empty mark as invalid, otherwise mark as valid*/
        nameVal === "" ? makeInvalid(name,"This field is required") : makeValid(name);

        /* if the email is empty mark as invalid*/
        if (emailVal === ""){
            makeInvalid(email,"This field is required");
        }
        /* if the email is not formatted correctly mark as invalid*/
        else if (emailPattern.test(emailVal) === false){
            makeInvalid(email,"Invalid email format");
        }
        /* if the email passes validation mark as valid */
        else{ makeValid(email); }

        /* if phone is empty mark as invalid*/
        if (phoneVal === ""){
            makeInvalid(phone,"This field is required");
        }
        /* if phone is not formatted correctly mark as invalid*/
        else if (phonePattern.test(phoneVal) === false){
            makeInvalid(phone,"Incorrect formatting, please use ###-###-####");
        }
        /* if phone passes validation mark as valid*/
        else{ makeValid(phone); }

        /* set the radioOption to the checked radio button */
        let radioOption = $(':radio:checked');

        /* if there is no radio buttons selected mark as invalid */
        if (radioOption.length === 0){
            $(':radio').addClass('is-invalid');
            $('#contact-message').text("please chose one");
            isValid = false;
        }
        /* if at least one radio button is selected mark as valid*/
        else{
            $(':radio').removeClass('is-invalid');
            $('#contact-message').text("");
        }

        /* if any input is marked as invalid cancel submission */
        if (isValid === false) {
            /* prevent submit */
            e.preventDefault();
            /* set the focus to the first textbox */
            arrivalDate.select().focus();
        }
    })

    /* handle reset button onclick event */
    $('#reset-reservation-form').on('click', () => {
        /* set the value of all textboxes to empty */
        $('input[type="text"]').val('');
        /* remove red boxes from invalid options */
        $('input').removeClass('is-invalid');
        /* deselect any radio buttons */
        $('input[type="radio"]').removeClass("checked");
        /* remove any validation messages */
        $('small').text('');
        /* set the focus to the first textbox */
        arrivalDate.select().focus();
    })

    /* handle the onclick event for all radio buttons */
    $('input[type="radio"]').on('click', () => {
        /* remove red color from radio button labels */
        $('input[type="radio"]').removeClass("is-invalid");
        /* remove validation message for radio buttons */
        $('#contact-message').text("");
    })
})