/*
Project Name: Level 1 - Expiration Manager (Expired Mailmerge)
Name: Joey Topasna
Date: 04/08/18
Description: this script can send custom email notifications to different email addresses depending on whether the
item has expired.
*/






//column type and corresponding index
var MGR_NAME_COL = 0;
var MGR_EMAIL_COL = 1;
var ITEM_TYPE_COL = 2;
var EXPIRATION_COL = 3;
var ITEM_NAME = 4;
var SENDER_NAME = 5;
var SENDER_TITLE = 6;
var ADMIN_EMAIL = 7;

var TODAY = new Date();





/*
Function Name: onOpen()
PreCondition: User opens linked google sheet
PostCondition: onOpen calls Spreadsheet service to retrieve user interface class and creates menu object.
*/
function onOpen() {

  var ui = SpreadsheetApp.getUi();
    
    ui.createMenu('Expiration Tracker Menu')
      
      .addItem('Send Notifications for Expired Items', 'notifyExpiredOwners')
    
      .addItem('Show Remaining Quota', 'showQuota')
      
      .addToUi();
  
}





/*
Function Name: showQuota()
PreCondition: active spreadsheet UI service
PostCondition: calls UI and performs alert to display remaining mail quota for google user.
*/
function showQuota() {

  var ui = SpreadsheetApp.getUi();
  
  ui.alert('Remaining Quota is: ' + MailApp.getRemainingDailyQuota());

  Logger.log(MailApp.getRemainingDailyQuota());

}







/*
Function Name: notifyExpiredOwners()
PreCondition: user opened spreadsheet + UI custom menu displayed
PostCondition: calls sendEmailNotification() function which emails only the emails/persons designated as expired in the
active spreadsheet
*/
function notifyExpiredOwners() {

    var activeCellArray = activeSpreadsheetCellArray();
        
    var expiringRowsArray = expiringRows(activeCellArray);
       
    //for each expiring row, push into HTML template + send
    for(i = 0; i < expiringRowsArray.length; i++) {
       
      var htmlTemplate = createPushHtmlVars(expiringRowsArray[i]);

      var htmlBODY = htmlTemplate
          .evaluate()
          .getContent();
          
      sendEmailNotification(expiringRowsArray[i], htmlBODY);

    }
        
}






/*
Function Name: activeSpreadsheetCellArray()
PreCondition: user opened spreadsheet
PostCondition: returns a two-dimensional array of values that represent the cells in the active spreadsheet
*/
function activeSpreadsheetCellArray() {

  var activeCellRange = SpreadsheetApp.getActiveSpreadsheet()
      .getDataRange();

  return activeCellRange.getValues();

}






/*
Function Name: expiringRows()
PreCondition: takes an array, cycling through all rows checking the expiration
PostCondition: returns an array of only the rows that are expiring in the spreadsheet
*/
function expiringRows(array) {

  var arrayOfExpiring = [];

  for(i = 1; i < array.length; i++) {
    
    if(array[i][EXPIRATION_COL] < TODAY) {
      
      arrayOfExpiring.push(array[i]);
    
    }
    
  }

  return arrayOfExpiring;

}






/*
Function Name: createPushHtmlVars()
PreCondition: takes an array of values that represent the row of an expiring item & associated info
PostCondition: returns a template HTML that pushes values to correspond with variables in the HTML template
*/
function createPushHtmlVars(expiringRow) {

  var template = HtmlService
    .createTemplateFromFile('lvl1MMHtml');
      
  for(j = 0; j < expiringRow.length; j++) {
    
    switch(j) {
    
      case 0:
        
        template.data0 = expiringRow[0];
        break;
        
      case 1:
      
        template.data1 = expiringRow[1];
        
        break;
      
      case 2:
      
        template.data2 = expiringRow[2];
        break;
        
      case 3:
      
        template.data3 = expiringRow[3];
       
        break;
        
      case 4:
      
        template.data4 = expiringRow[4];
        break;
        
        
      case 5:
        
        template.data5 = expiringRow[5];
        break;
        
      case 6:
        
        template.data6 = expiringRow[6];
        break;
        
      case 7:
        
        template.data7 = expiringRow[7];
        break;
      
      default:   
      
        template.data0 = "ERROR";
        template.data1 = "ERROR";
        template.data2 = "ERROR";
        template.data3 = "ERROR";
        template.data4 = "ERROR";
        template.data5 = "ERROR";
        template.data6 = "ERROR";
        break;
  
    
    }
  
  }

  return template;

}






/*
Function Name: expirationSubjectLine()
PreCondition: takes an array representing an expiring row
PostCondition: returns a string that corresponds to what the subject line should be for a notifications
*/
function expirationSubjectLine(expiringRow) {

  var subjLineString = "";
  
  subjLineString = "Reminder: " + expiringRow[MGR_NAME_COL] + "'s " + expiringRow[ITEM_NAME] + " expired on " + expiringRow[EXPIRATION_COL];

  return subjLineString;

}




/*
Function Name: sendEmailNotification()
PreCondition: takes the expiring row and the content of the html template that has been pushed values
PostCondition: sends email to recipient using the google MailApp web service
*/
function sendEmailNotification(expiringRow, htmlMessage) {
    
    var subj = expirationSubjectLine(expiringRow);
        
    var recipient = expiringRow[MGR_EMAIL_COL];
    
    MailApp.sendEmail({
    to: recipient,
    subject: subj,
    htmlBody: htmlMessage,
    replyTo: expiringRow[ADMIN_EMAIL]
    
    });

}

