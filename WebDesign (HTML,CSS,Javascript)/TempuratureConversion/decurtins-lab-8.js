$(document).ready(function () {
    //set the initial focus to the top textbox
    $('#temperature-entered').focus();
    //handle the on click for the convert to fahrenheit radiobutton
    $('#to-fahrenheit').click(function () {
        //set the top label to enter in celsius
        $('#temperature-top-label').text('Enter temperature in Celsius:');
        //set the bottom label to convert to fahrenheit
        $('#temperature-bottom-label').text('Temperature converted to Fahrenheit:');
        //call the clear onclick
        $('#clear-entries').click();
    });
    //handle the on click for the convert to celsius radiobutton
    $('#to-celsius').click(function () {
        //set the top label to enter in fahrenheit
        $('#temperature-top-label').text('Enter temperature in Fahrenheit:');
        //set the bottom label to convert to celsius
        $('#temperature-bottom-label').text('Temperature converted to Celsius:');
        //call the clear onclick
        $('#clear-entries').click();
    });
    //handle the on click for the convert button
    $('#convert').click(function () {
        //if the entry is not a number
        if (isNaN($('#temperature-entered').val())) {
            //display a validation message that entry must be a number
            $('#validation-message').text('Please enter a number');
            //add the is-invalid class
            $('#temperature-entered').addClass('is-invalid');
            // clear the value of the converted-temperature box
            $('#converted-temperature').val('');
        //if the entry is null
        } else if ($('#temperature-entered').val() === '') {
            //display a validation message that there must be an entry
            $('#validation-message').text('This field is required');
            //add the is-invalid class
            $('#temperature-entered').addClass('is-invalid');
        //if the entry is not null and a number
        } else {
            //clear any validation messages
            $('#validation-message').text('');
            //remove is-invalid class to get rid of red outlines
            $('#temperature-entered').removeClass('is-invalid');
            //declare temperature variables
            let fahrenheit, celsius;
            //set a radioButton equal to checked for comparison purposes
            const radioButton = $(':checked').val();
            //if the convert to celsius radiobutton is checked
            if (radioButton === 'convert-to-celsius') {
                //set fahrenheit variable equal to the entered temp
                fahrenheit = parseFloat($('#temperature-entered').val());
                //set the celsius variable according to equation
                celsius = (fahrenheit - 32) * (5 / 9);
                //put the equations output into the converted textbox
                $('#converted-temperature').val(celsius.toFixed(2) + ' Degrees');
            //if the convert to fahrenheit radiobutton is checked
            } else if (radioButton === 'convert-to-fahrenheit') {
                //set the celsius variable equal to the entered temp
                celsius = parseFloat($('#temperature-entered').val());
                //set the fahrenheit variable according to equation
                fahrenheit = (celsius * (9 / 5)) + 32;
                //put the equations output into the converted textbox
                $('#converted-temperature').val(fahrenheit.toFixed(2) + ' Degrees');
            }
        }

        //select text and send focus to textbox
        $('#temperature-entered').select().focus();
    });
    //handle the on click for the clear button
    $('#clear-entries').click(function () {
        //set the value of all textboxs to empty string
        $(':text').val('');
        //clear any validation message
        $('#validation-message').text('');
        //remove red outline from textbox and remove is-invalid class
        $('#temperature-entered').removeClass('is-invalid').focus();
    });
    //handle the double click for the top textbox
    $('#temperature-entered').dblclick(function () {
        //call the clear button onclick
        $('#clear-entries').click();
    });
});