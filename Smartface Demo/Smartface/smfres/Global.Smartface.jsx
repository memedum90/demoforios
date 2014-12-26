var fotoindex;
function Global_Events_OnStart(e) {
    changeLang(Device.language, true);
    include("BC.js"); //included for future BC support. Removing is not advised.

    //      Comment following block for navigationbar/actionbar sample. Read the JS code file for usage.
    //      Also there is a part of code block in Page1, which should be copied to every page for HeaderBar usage
    load("HeaderBar.js");
    header = new HeaderBar();

    //      Uncomment following block for menu sample. Read the JS code file for usage.
    /*
    load("Menu.js");
    /**/
    
}


   
function Global_Events_OnError(e) {
    switch (e.type) {
    case "Server Error":
    case "Size Overflow":
        alert(lang.networkError);
        break;
    default:
        SES.Analytics.eventLog("error", JSON.stringify(e));
        //change the following code for desired generic error messsage
        alert({
            title : lang.applicationError,
            message : e.message + "\n\n*" + e.sourceURL + "\n*" + e.line + "\n*" + e.stack
        });
        break;
    }
}

var ad="mehmet";
var soyad="durna";
var tckimlikno=0;
var dogum=0;
var tcKimlikValidation= new SMF.Net.WebClient({
        URL : 'https://tckimlik.nvi.gov.tr/Service/KPSPublic.asmx',
        httpMethod : "POST",
        contentType : 'text/xml;charset=UTF-8',
        onServerError : function (e){
            alert(ad+soyad+tckimlikno+dogum);
            alert (e);
        
        },
        onSyndicationSuccess : function (e) {
            var parser = new DOMParser();
            var xmlDoc = parser.parseFromString(this.responseText);
            var textF = xmlDoc.getElementsByTagName("TCKimlikNoDogrulaResult");
            //alert(textF[0].childNodes[0].nodeValue);
            Pages.Page3.Label1.text=textF[0].childNodes[0].nodeValue;
        },
        requestString : '<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">'
 + '<soap:Body>'
   + '<TCKimlikNoDogrula xmlns="http://tckimlik.nvi.gov.tr/WS">'
  +    '<TCKimlikNo>'  +tckimlikno+  '</TCKimlikNo>'
  +    '<Ad>'    +ad+     '</Ad>'
  +    '<Soyad>' +soyad+  '</Soyad>'
 +     '<DogumYili>'  +dogum+    '</DogumYili>'
 +   '</TCKimlikNoDogrula>'
+  '</soap:Body>' 
+'</soap:Envelope>'
});