function Project_GetWeather_OnSyndicationSuccess(e){
    

   var parser= new DOMParser();
   var txt=Data.GetWeather_OutDSetGetWeatherResponse.GetWeatherResult;
   var txt2= txt.replace("utf-16", "utf-8");
   var xmlDoc=parser.parseFromString(txt2, "text/xml");
   
    Pages.Page1.Ticker1.text="Sıcaklık (" +Pages.Page1.EditBox1.text + "): "+
    xmlDoc.getElementsByTagName("Temperature")[0].childNodes[0].nodeValue;
    
    
       //alert(xmlDoc.getElementsByTagName("CurrentWeather"));
            
   
   
}